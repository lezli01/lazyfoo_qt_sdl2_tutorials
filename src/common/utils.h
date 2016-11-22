#pragma once

#include <QString>

#include <SDL.h>

SDL_Texture *loadTexture(SDL_Renderer *renderer, const QString &path, int *width = nullptr, int *height = nullptr);
