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

LTexture *texture = nullptr;

void init()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        throw Exception(QStringLiteral("Could not initialize SDL"));
    }

    window = SDL_CreateWindow("Tutorial 014", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if (!window) {
        throw Exception(QStringLiteral("Could not create window"));
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

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
    texture = new LTexture(renderer, qApp->applicationDirPath().append(QStringLiteral("/foo.png")));
}

void close()
{
    delete texture;

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

    SDL_Rect spriteClips[4];
    spriteClips[ 0 ].x =   0;
    spriteClips[ 0 ].y =   0;
    spriteClips[ 0 ].w =  64;
    spriteClips[ 0 ].h = 205;

    spriteClips[ 1 ].x =  64;
    spriteClips[ 1 ].y =   0;
    spriteClips[ 1 ].w =  64;
    spriteClips[ 1 ].h = 205;

    spriteClips[ 2 ].x = 128;
    spriteClips[ 2 ].y =   0;
    spriteClips[ 2 ].w =  64;
    spriteClips[ 2 ].h = 205;

    spriteClips[ 3 ].x = 196;
    spriteClips[ 3 ].y =   0;
    spriteClips[ 3 ].w =  64;
    spriteClips[ 3 ].h = 205;

    int frame = 0;
    int delay = 400;

    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }

        SDL_RenderClear(renderer);

        texture->render(renderer, 0, 0, &spriteClips[frame / delay]);

        SDL_RenderPresent(renderer);

        frame++;

        if (frame / delay >= 4) {
            frame = 0;
        }
    }

    close();

    return 0;
}
