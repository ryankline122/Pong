#ifndef UTILS_H
#define UTILS_H

#include <SDL2/SDL.h>

bool isColliding(SDL_Rect object1, SDL_Rect object2);
void drawObject(SDL_Renderer *renderer, SDL_Rect object);
int generate_random_int(int min, int max);


enum class Direction{
            NONE,
            UP,
            DOWN,
            LEFT,
            RIGHT
        };

#endif
