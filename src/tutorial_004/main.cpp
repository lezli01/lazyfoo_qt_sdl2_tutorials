#include <iostream>

#include <QCoreApplication>

#include <SDL.h>

#include <exception.h>

int SCREEN_WIDTH = 640;
int SCREEN_HEIGHT = 480;

enum KeyPressSurfaces
{
    KEY_PRESS_SURFACE_DEFAULT,
    KEY_PRESS_SURFACE_UP,
    KEY_PRESS_SURFACE_DOWN,
    KEY_PRESS_SURFACE_LEFT,
    KEY_PRESS_SURFACE_RIGHT,
    KEY_PRESS_SURFACE_TOTAL
};

SDL_Window *window = nullptr;
SDL_Surface *windowSurface = nullptr;
SDL_Surface *imageSurfaces[KEY_PRESS_SURFACE_TOTAL];
SDL_Surface *currentImageSurface = nullptr;

SDL_Surface *loadSurface(const QString &path)
{
    SDL_Surface *loaded = SDL_LoadBMP(path.toStdString().c_str());

    if (!loaded) {
        throw Exception(QStringLiteral("Error loading bmp: ").append(path));
    }

    return loaded;
}

void init()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        throw Exception(QStringLiteral("Could not initialize SDL"));
    }

    window = SDL_CreateWindow("Tutorial 004", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if (!window) {
        throw Exception(QStringLiteral("Could not create window"));
    }

    windowSurface = SDL_GetWindowSurface(window);
}

void loadMedia()
{
    imageSurfaces[KEY_PRESS_SURFACE_DEFAULT] = loadSurface(qApp->applicationDirPath().append(QStringLiteral("/base.bmp")));
    imageSurfaces[KEY_PRESS_SURFACE_UP] = loadSurface(qApp->applicationDirPath().append(QStringLiteral("/up.bmp")));
    imageSurfaces[KEY_PRESS_SURFACE_DOWN] = loadSurface(qApp->applicationDirPath().append(QStringLiteral("/down.bmp")));
    imageSurfaces[KEY_PRESS_SURFACE_LEFT] = loadSurface(qApp->applicationDirPath().append(QStringLiteral("/left.bmp")));
    imageSurfaces[KEY_PRESS_SURFACE_RIGHT] = loadSurface(qApp->applicationDirPath().append(QStringLiteral("/right.bmp")));

    currentImageSurface = imageSurfaces[KEY_PRESS_SURFACE_DEFAULT];
}

void close()
{
    SDL_FreeSurface(imageSurfaces[KEY_PRESS_SURFACE_DEFAULT]);
    SDL_FreeSurface(imageSurfaces[KEY_PRESS_SURFACE_UP]);
    SDL_FreeSurface(imageSurfaces[KEY_PRESS_SURFACE_DOWN]);
    SDL_FreeSurface(imageSurfaces[KEY_PRESS_SURFACE_LEFT]);
    SDL_FreeSurface(imageSurfaces[KEY_PRESS_SURFACE_RIGHT]);

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
    } catch (const Exception &exception) {
        std::cerr << "Error: " << exception.stdMsg() << " " << SDL_GetError() << std::endl;
    }

    bool quit = false;
    SDL_Event e;

    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                quit = true;
            } else if (e.type == SDL_KEYDOWN) {
                switch (e.key.keysym.sym) {
                    case SDLK_UP:
                        currentImageSurface = imageSurfaces[KEY_PRESS_SURFACE_UP];
                        break;

                    case SDLK_DOWN:
                        currentImageSurface = imageSurfaces[KEY_PRESS_SURFACE_DOWN];
                        break;

                    case SDLK_LEFT:
                        currentImageSurface = imageSurfaces[KEY_PRESS_SURFACE_LEFT];
                        break;

                    case SDLK_RIGHT:
                        currentImageSurface = imageSurfaces[KEY_PRESS_SURFACE_RIGHT];
                        break;

                    default:
                        currentImageSurface = imageSurfaces[KEY_PRESS_SURFACE_DEFAULT];
                        break;
                }
            }
        }

        SDL_BlitSurface(currentImageSurface, nullptr, windowSurface, nullptr);
        SDL_UpdateWindowSurface(window);
    }

    close();

    return 0;
}
