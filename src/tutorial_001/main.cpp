#include <SDL.h>

int main() {
    SDL_Window *window = nullptr;
    SDL_Surface *surface = nullptr;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        return 1;
    }

    window = SDL_CreateWindow(nullptr, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);

    if (!window) {
        return 1;
    }

    surface = SDL_GetWindowSurface(window);

    SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0xff, 0xff, 0xff));
    SDL_UpdateWindowSurface(window);

    SDL_Delay(2000);

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}