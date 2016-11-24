#include "ltexture.h"

#include <utils.h>

LTexture::LTexture(SDL_Renderer *renderer, const QString &path)
    : texture(loadTexture(renderer, path, &width, &height))
{}

LTexture::~LTexture()
{
    SDL_DestroyTexture(texture);
}

void LTexture::setColor(Uint8 r, Uint8 g, Uint8 b)
{
    SDL_SetTextureColorMod(texture, r, g, b);
}

void LTexture::render(
        SDL_Renderer *renderer,
        int x,
        int y,
        SDL_Rect *clip,
        double angle,
        SDL_Point *center,
        SDL_RendererFlip flip
)
{
    SDL_Rect renderRect = {
            x,
            y,
            clip ? clip->w : width * 2,
            clip ? clip->h : height * 2
    };

    SDL_RenderCopyEx(renderer, texture, clip, &renderRect, angle, center, flip);
}


void LTexture::setBlendMode(SDL_BlendMode blendMode)
{
    SDL_SetTextureBlendMode(texture, blendMode);
}

void LTexture::setAlpha(Uint8 alpha)
{
    SDL_SetTextureAlphaMod(texture, alpha);
}
