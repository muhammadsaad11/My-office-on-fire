#include<SDL.h>
#include<iostream>
#include "VirtualFunctions.hpp"
#pragma once


using namespace std;

class Chair_Obstacle
{
    private:
        SDL_Renderer *gRenderer;
        SDL_Texture * assets;
        SDL_Rect srcRect = {0, 0 , 63, 100};
        SDL_Rect destRect = {800, 500, 63, 100};

    public:
        Chair_Obstacle(SDL_Renderer *renderer, SDL_Texture *asst); //Constructor
        void draw();
        void update(SDL_Rect, SDL_Rect, SDL_Texture*);
        void setsrcRect(SDL_Rect temp_Rect);
        void setdestRect(SDL_Rect temp_Rect);
        SDL_Rect get_srcRect();
        SDL_Rect get_destRect();
        
};
