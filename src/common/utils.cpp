#include "utils.h"

#include <SDL_image.h>

#include <exception.h>

SDL_Texture *loadTexture(SDL_Renderer *renderer, const QString &path, int *width, int *height)
{
    SDL_Surface *loaded = IMG_Load(path.toStdString().c_str());

    if (!loaded) {
        throw Exception(QStringLiteral("Error loading image: ").append(path));
    }

    SDL_SetColorKey(loaded, SDL_TRUE, SDL_MapRGB(loaded->format, 0x00, 0xFF, 0xFF));

    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, loaded);

    if (width) {
        *width = loaded->w;
    }

    if (height) {
        *height = loaded->h;
    }

    SDL_FreeSurface(loaded);

    return texture;
}