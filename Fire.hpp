#include<SDL.h>
#include<iostream>
#include "VirtualFunctions.hpp"
#pragma once


using namespace std;

class Fire 
{
    protected:
        SDL_Renderer *gRenderer;
        SDL_Texture * assets;
        SDL_Rect srcRect = {0, 0 , 62, 77};
        SDL_Rect destRect = {370, 480, 62, 77}; 

    public:
        Fire(SDL_Renderer *renderer, SDL_Texture *asst); //Constructor
        void update(SDL_Rect, SDL_Rect, SDL_Texture*);
        void draw();
        void setsrcRect(SDL_Rect temp_Rect);
        void setdestRect(SDL_Rect temp_Rect);
        SDL_Rect get_srcRect();
        SDL_Rect get_destRect();
        
};
