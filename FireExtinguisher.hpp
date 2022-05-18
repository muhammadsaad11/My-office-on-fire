#include<SDL.h>
#include<iostream>
#include "VirtualFunctions.hpp"
#pragma once


using namespace std;

class FireExtinguisher
{
    private:
        SDL_Renderer *gRenderer;
        SDL_Texture * assets;
        SDL_Rect srcRect;
        SDL_Rect destRect;

    public:
        FireExtinguisher(SDL_Renderer *renderer, SDL_Texture *asst);
        void draw();
        SDL_Rect get_srcRect();
        SDL_Rect get_destRect();
        
};
