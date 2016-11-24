#pragma once

#include <QString>

#include <SDL.h>

class LTexture
{
    public:
        LTexture(SDL_Renderer *renderer, const QString &path);
        ~LTexture();

        void setColor(Uint8 r, Uint8 g, Uint8 b);
        void render(SDL_Renderer *renderer, int x, int y, SDL_Rect *clip = nullptr);

        void setBlendMode(SDL_BlendMode blendMode);
        void setAlpha(Uint8 alpha);

    protected:
        SDL_Texture *texture;

        int width;
        int height;
};