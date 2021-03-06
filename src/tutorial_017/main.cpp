#include <iostream>

#include <QCoreApplication>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include <exception.h>
#include <ltexture.h>
#include <lbutton.h>

int SCREEN_WIDTH = 640;
int SCREEN_HEIGHT = 480;

SDL_Window *window = nullptr;
SDL_Renderer *renderer = nullptr;

TTF_Font *font = nullptr;

LTexture **texture = nullptr;

void init()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        throw Exception(QStringLiteral("Could not initialize SDL"));
    }

    window = SDL_CreateWindow("Tutorial 017", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if (!window) {
        throw Exception(QStringLiteral("Could not create window"));
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
//    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

    if (!renderer) {
        throw Exception(QStringLiteral("Could not create renderer: ").append(SDL_GetError()));
    }

    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

    int imgFlags = IMG_INIT_PNG;

    if ( !(IMG_Init(imgFlags) & imgFlags)) {
        throw Exception(QStringLiteral("Could not init SDL_Image: ").append(IMG_GetError()));
    }

    if (TTF_Init() < 0) {
        throw Exception(QStringLiteral("Could not init SDL_ttf ").append(IMG_GetError()));
    }
}

void loadMedia()
{
    texture = new LTexture*[BUTTON_SPRITE_TOTAL];

    font = TTF_OpenFont(qApp->applicationDirPath().append(QStringLiteral("/font.ttf")).toStdString().c_str(), 56);

    SDL_Color color = {0, 0, 0};
    texture[BUTTON_SPRITE_MOUSE_OUT] = new LTexture(renderer, font, "Mouse Out", color);
    texture[BUTTON_SPRITE_MOUSE_OVER_MOTION] = new LTexture(renderer, font, "Mouse Over", color);
    texture[BUTTON_SPRITE_MOUSE_DOWN] = new LTexture(renderer, font, "Mouse Down", color);
    texture[BUTTON_SPRITE_MOUSE_UP] = new LTexture(renderer, font, "Mouse Up", color);
}

void close()
{
    delete [] texture;

    TTF_CloseFont(font);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    TTF_Quit();
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

    double degrees = 0.0;
    SDL_RendererFlip flipType = SDL_FLIP_NONE;

    LButton topLeft;
    topLeft.setPos(0, 0);
    topLeft.setSize(320, 240);

    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }

            topLeft.handleEvent(&e);
        }

        SDL_RenderClear(renderer);

        topLeft.render(renderer, texture);

        SDL_RenderPresent(renderer);
        SDL_Delay(20);
    }

    close();

    return 0;
}
