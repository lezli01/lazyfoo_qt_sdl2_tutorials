#include <iostream>

#include <SDL.h>

#include <exception.h>

int SCREEN_WIDTH = 640;
int SCREEN_HEIGHT = 480;

SDL_Window *window = nullptr;
SDL_Surface *surface = nullptr;

int main(int argc, char* argv[])
{
    try{
        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
            throw Exception(QStringLiteral("Could not initialize SDL"));
        }

        window = SDL_CreateWindow("Tutorial 001", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

        if (!window) {
            throw Exception(QStringLiteral("Could not create window"));
        }

        surface = SDL_GetWindowSurface(window);

        SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0xff, 0xff, 0xff));
        SDL_UpdateWindowSurface(window);

        SDL_Delay(2000);

        SDL_DestroyWindow(window);
    } catch (const Exception &exception) {
        std::cerr << "Error: " << exception.stdMsg() << " " << SDL_GetError() << std::endl;
    }

    SDL_Quit();

    return 0;
}
