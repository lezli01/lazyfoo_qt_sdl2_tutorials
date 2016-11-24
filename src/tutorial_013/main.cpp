#include <iostream>

#include <QCoreApplication>

#include <SDL.h>
#include <SDL_image.h>

#include <exception.h>

#include "ltexture.h"

int SCREEN_WIDTH = 640;
int SCREEN_HEIGHT = 480;

SDL_Window *window = nullptr;
SDL_Renderer *renderer = nullptr;

LTexture *fadeInTex = nullptr;
LTexture *fadeOutTex = nullptr;

void init()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        throw Exception(QStringLiteral("Could not initialize SDL"));
    }

    window = SDL_CreateWindow("Tutorial 013", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if (!window) {
        throw Exception(QStringLiteral("Could not create window"));
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (!renderer) {
        throw Exception(QStringLiteral("Could not create renderer: ").append(SDL_GetError()));
    }

    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

    int imgFlags = IMG_INIT_PNG;

    if ( !(IMG_Init(imgFlags) & imgFlags)) {
        throw Exception(QStringLiteral("Could not init SDL_Image: ").append(IMG_GetError()));
    }
}

void loadMedia()
{
    fadeInTex = new LTexture(renderer, qApp->applicationDirPath().append(QStringLiteral("/fadein.png")));

    fadeOutTex = new LTexture(renderer, qApp->applicationDirPath().append(QStringLiteral("/fadeout.png")));
    fadeOutTex->setBlendMode(SDL_BLENDMODE_BLEND);
}

void close()
{
    delete fadeInTex;
    delete fadeOutTex;

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    IMG_Quit();
    SDL_Quit();
}

int main(int argc, char* argv[])
{
    QCoreApplication app(argc, argv);
    Q_UNUSED(app);
    
    try{
        init();
        loadMedia();
    } catch (const Exception &exception) {
        std::cerr << "Error: " << exception.stdMsg() << " " << SDL_GetError() << std::endl;
    }

    bool quit = false;
    SDL_Event e;

    Uint8 a = 255;
    Uint8 STEP = 32;

    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                quit = true;
            } else if (e.type == SDL_KEYDOWN) {
                switch (e.key.keysym.sym) {
                    case SDLK_w:
                        a += STEP;
                        break;

                    default: case SDLK_s:
                        a -= STEP;
                        break;
                }
            }
        }

        SDL_RenderClear(renderer);

        fadeInTex->render(renderer, 0, 0);

        fadeOutTex->setAlpha(a);
        fadeOutTex->render(renderer, 0, 0);

        SDL_RenderPresent(renderer);

        SDL_Delay(200);
    }

    close();

    return 0;
}
