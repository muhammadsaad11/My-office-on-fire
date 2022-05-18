#include<SDL.h>
#include<iostream>
#include "VirtualFunctions.hpp"
#pragma once


using namespace std;

class Elevator
{
    protected:
    SDL_Renderer *gRenderer;
    SDL_Texture * assets;
    SDL_Rect srcRect;
    SDL_Rect destRect;

    public:
        int win_count;
        Elevator(SDL_Renderer *renderer, SDL_Texture *asst); //Constructor
        void draw();
        void update(SDL_Rect, SDL_Rect, SDL_Texture*);
        SDL_Rect get_srcRect();
        SDL_Rect get_destRect();
        
};
