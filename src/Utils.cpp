#include <SDL2/SDL.h>
#include "headers/Utils.hpp"
#include <iostream>
#include <random>

bool isColliding(SDL_Rect rect1, SDL_Rect rect2) {
    int left1 = rect1.x;
    int right1 = rect1.x + rect1.w;
    int top1 = rect1.y;
    int bottom1 = rect1.y + rect1.h;

    int left2 = rect2.x;
    int right2 = rect2.x + rect2.w;
    int top2 = rect2.y;
    int bottom2 = rect2.y + rect2.h;

    // check for intersection
    if (left1 < right2 && right1 > left2 && top1 < bottom2 && bottom1 > top2) {
        return true;
    }

    return false;
}

void drawObject(SDL_Renderer *renderer, SDL_Rect object){
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &object);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
}


int generate_random_int(int min, int max){
    std::random_device rd;
    std::mt19937 gen(rd());
    
    std::uniform_int_distribution<> dis(min, max);

    int number = dis(gen);

    return number;


}




