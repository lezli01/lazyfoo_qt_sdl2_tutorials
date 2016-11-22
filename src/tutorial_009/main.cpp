#include <iostream>

#include <QCoreApplication>

#include <SDL.h>
#include <SDL_image.h>

#include <exception.h>

int SCREEN_WIDTH = 640;
int SCREEN_HEIGHT = 480;

SDL_Window *window = nullptr;
SDL_Texture *imageTexture = nullptr;
SDL_Renderer *renderer = nullptr;

SDL_Texture *loadTexture(const QString &path)
{
    SDL_Surface *loaded = IMG_Load(path.toStdString().c_str());

    if (!loaded) {
        throw Exception(QStringLiteral("Error loading png: ").append(path));
    }

    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, loaded);
    SDL_FreeSurface(loaded);

    return texture;
}

void init()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        throw Exception(QStringLiteral("Could not initialize SDL"));
    }

    window = SDL_CreateWindow("Tutorial 009", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

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
    imageTexture = loadTexture(qApp->applicationDirPath().append(QStringLiteral("/viewport.png")));
}

void close()
{
    SDL_DestroyTexture(imageTexture);
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

    SDL_Rect topLeft = {
        0,
        0,
        SCREEN_WIDTH / 2,
        SCREEN_HEIGHT / 2
    };

    SDL_Rect topRight = {
        SCREEN_WIDTH / 2,
        0,
        SCREEN_WIDTH / 2,
        SCREEN_HEIGHT / 2
    };

    SDL_Rect bottom = {
        0,
        SCREEN_HEIGHT / 2,
        SCREEN_WIDTH,
        SCREEN_HEIGHT / 2
    };

    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }

        SDL_RenderClear(renderer);

        SDL_RenderSetViewport(renderer, &topLeft);
        SDL_RenderCopy(renderer, imageTexture, nullptr, nullptr);

        SDL_RenderSetViewport(renderer, &topRight);
        SDL_RenderCopy(renderer, imageTexture, nullptr, nullptr);

        SDL_RenderSetViewport(renderer, &bottom);
        SDL_RenderCopy(renderer, imageTexture, nullptr, nullptr);

        SDL_RenderPresent(renderer);
    }

    close();

    return 0;
}
