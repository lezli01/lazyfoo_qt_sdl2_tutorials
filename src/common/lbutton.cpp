#include "lbutton.h"

LButton::LButton()
{
    state = BUTTON_SPRITE_MOUSE_UP;
}

void LButton::handleEvent(SDL_Event *e)
{
    //If mouse event happened
    if( e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP )
    {
        //Get mouse position
        int x, y;
        SDL_GetMouseState( &x, &y );
        //Check if mouse is in button
        bool inside = true;

        //Mouse is left of the button
        if( x < pos.x )
        {
            inside = false;
        }
            //Mouse is right of the button
        else if( x > pos.x + 320 )
        {
            inside = false;
        }
            //Mouse above the button
        else if( y < pos.y )
        {
            inside = false;
        }
            //Mouse below the button
        else if( y > pos.y + 240 )
        {
            inside = false;
        }
        //Mouse is outside button
        if( !inside )
        {
            state = BUTTON_SPRITE_MOUSE_OUT;
        }

        //Mouse is inside button
        else
        {
            //Set mouse over sprite
            switch( e->type )
            {
                case SDL_MOUSEMOTION:
                    state = BUTTON_SPRITE_MOUSE_OVER_MOTION;
                    break;

                case SDL_MOUSEBUTTONDOWN:
                    state = BUTTON_SPRITE_MOUSE_DOWN;
                    break;

                case SDL_MOUSEBUTTONUP:
                    state = BUTTON_SPRITE_MOUSE_UP;
                    break;
            }
        }
    }
}

void LButton::setPos(int x, int y)
{
    pos.x = x;
    pos.y = y;
}

void LButton::setSize(int w, int h)
{
    pos.w = w;
    pos.h = h;
}

void LButton::render(SDL_Renderer *renderer, LTexture **texture)
{
    texture[state]->setSize(pos.w, pos.h);
    texture[state]->render(renderer, pos.x, pos.y);
}
