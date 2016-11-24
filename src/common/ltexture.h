#pragma once

#include <QString>

#include <SDL.h>
#include <SDL_ttf.h>

class LTexture
{
    public:
        LTexture(SDL_Renderer *renderer, const QString &path);
        LTexture(SDL_Renderer *renderer, TTF_Font *font, const QString &text, SDL_Color &color);
        ~LTexture();

        void setColor(Uint8 r, Uint8 g, Uint8 b);
        void render(
                SDL_Renderer *renderer,
                int x,
                int y,
                SDL_Rect *clip = nullptr,
                double angle = 0.0,
                SDL_Point *center = nullptr,
                SDL_RendererFlip flip = SDL_FLIP_NONE
        );

        void setBlendMode(SDL_BlendMode blendMode);
        void setAlpha(Uint8 alpha);

    protected:
        SDL_Texture *texture;

        int width;
        int height;
};