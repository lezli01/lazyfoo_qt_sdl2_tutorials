#include "ltexture.h"

#include <utils.h>

LTexture::LTexture(SDL_Renderer *renderer, const QString &path)
    : texture(loadTexture(renderer, path, &width, &height))
{}

LTexture::~LTexture()
{
    SDL_DestroyTexture(texture);
}

void LTexture::render(SDL_Renderer *renderer, int x, int y)
{
    SDL_Rect renderRect = {
            x,
            y,
            width,
            height
    };

    SDL_RenderCopy(renderer, texture, nullptr, &renderRect);
}