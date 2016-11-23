#pragma once

#include <QString>

#include <SDL.h>

class LTexture
{
    public:
        LTexture(SDL_Renderer *renderer, const QString &path);
        ~LTexture();

        void render(SDL_Renderer *renderer, int x, int y, SDL_Rect *clip = nullptr);

    protected:
        SDL_Texture *texture;

        int width;
        int height;
};