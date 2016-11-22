#include <iostream>

#include <QCoreApplication>

#include <SDL.h>

#include <exception.h>

int SCREEN_WIDTH = 640;
int SCREEN_HEIGHT = 480;

SDL_Window *window = nullptr;
SDL_Renderer *renderer = nullptr;


void init()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        throw Exception(QStringLiteral("Could not initialize SDL"));
    }

    window = SDL_CreateWindow("Tutorial 008", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if (!window) {
        throw Exception(QStringLiteral("Could not create window"));
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (!renderer) {
        throw Exception(QStringLiteral("Could not create renderer: ").append(SDL_GetError()));
    }
}

void close()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();
}

int main(int argc, char* argv[])
{
    QCoreApplication app(argc, argv);
    Q_UNUSED(app);
    
    try{
        init();
    } catch (const Exception &exception) {
        std::cerr << "Error: " << exception.stdMsg() << " " << SDL_GetError() << std::endl;
    }

    bool quit = false;
    SDL_Event e;

    SDL_Rect fillRect = {
            SCREEN_WIDTH / 4,
            SCREEN_HEIGHT / 4,
            SCREEN_WIDTH / 2,
            SCREEN_HEIGHT / 2
    };

    SDL_Rect outlineRect = {
            SCREEN_WIDTH / 6,
            SCREEN_HEIGHT / 6,
            SCREEN_WIDTH * 2 / 3,
            SCREEN_HEIGHT * 2 / 3
    };

    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }

        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
        SDL_RenderFillRect(renderer, &fillRect);

        SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0x00, 0xFF);
        SDL_RenderDrawRect(renderer, &outlineRect);

        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xFF, 0xFF);
        SDL_RenderDrawLine(renderer, 0, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT / 2);

        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0x00, 0xFF);
        for (int i = 0; i < SCREEN_HEIGHT; i += 5) {
            SDL_RenderDrawPoint(renderer, SCREEN_WIDTH / 2, i);
        }

        SDL_RenderPresent(renderer);
    }

    close();

    return 0;
}
