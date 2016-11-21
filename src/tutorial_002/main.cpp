#include <iostream>

#include <QCoreApplication>

#include <SDL.h>

#include <exception.h>

int SCREEN_WIDTH = 640;
int SCREEN_HEIGHT = 480;

SDL_Window *window = nullptr;
SDL_Surface *windowSurface = nullptr;
SDL_Surface *imageSurface = nullptr;

void init()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        throw Exception(QStringLiteral("Could not initialize SDL"));
    }

    window = SDL_CreateWindow("Tutorial 002", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if (!window) {
        throw Exception(QStringLiteral("Could not create window"));
    }

    windowSurface = SDL_GetWindowSurface(window);
}

void loadMedia()
{
    imageSurface = SDL_LoadBMP(qApp->applicationDirPath().append("/hello_world.bmp").toStdString().c_str());

    if (!imageSurface) {
        throw Exception(QStringLiteral("Could not load bmp image"));
    }
}

void close()
{
    SDL_FreeSurface(imageSurface);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

int main(int argc, char* argv[])
{
    QCoreApplication app(argc, argv);
    Q_UNUSED(app);
    
    try{
        init();
        loadMedia();

        SDL_BlitSurface(imageSurface, nullptr, windowSurface, nullptr);
        SDL_UpdateWindowSurface(window);
        SDL_Delay(2000);
    } catch (const Exception &exception) {
        std::cerr << "Error: " << exception.stdMsg() << " " << SDL_GetError() << std::endl;
    }

    close();

    return 0;
}
