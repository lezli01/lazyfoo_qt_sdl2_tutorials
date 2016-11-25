#pragma once

#include <SDL.h>

#include <ltexture.h>

enum LButtonState
{
    BUTTON_SPRITE_MOUSE_OUT = 0,
    BUTTON_SPRITE_MOUSE_OVER_MOTION = 1,
    BUTTON_SPRITE_MOUSE_DOWN = 2,
    BUTTON_SPRITE_MOUSE_UP = 3,
    BUTTON_SPRITE_TOTAL = 4
};

class LButton
{
    public:
        LButton();

        void handleEvent( SDL_Event* e );

        void setPos(int x, int y);
        void setSize(int w, int h);
        void render(SDL_Renderer *renderer, LTexture **texture);

    protected:
        SDL_Rect pos;
        LButtonState state;
};