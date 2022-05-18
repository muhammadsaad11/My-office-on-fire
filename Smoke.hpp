#include<SDL.h>
#include<iostream>
#include"Fire.hpp"
#pragma once

//Inhereting the Fire class
class Smoke : public Fire
{
    SDL_Rect srcRect;
    int frame;

    public:
    Smoke (SDL_Renderer *renderer, SDL_Texture *asst, SDL_Rect dest) : Fire(renderer, asst) //Constructor
    {
        destRect = dest;
        srcRect = {0, 0, 48, 85};
    }
    void draw();
};