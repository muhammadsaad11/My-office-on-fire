#include<SDL.h>
#include<iostream>
#pragma once
using namespace std;

class Status
{
    private:
        SDL_Renderer * gRenderer = NULL;
        SDL_Texture * asset = NULL;
        SDL_Rect srcRect = {0, 0, 32, 64};
        SDL_Rect destRect[5] ;
        int life = 3; // Health x 3
    public:
        Status(SDL_Renderer*, SDL_Texture*); //Constructor
        void draw();
        int get_life();
        void decrementLife();
        void incrementLife();

};
