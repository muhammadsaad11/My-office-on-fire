#include "VirtualFunctions.hpp"
#include <SDL.h>
#pragma once

class FireGas: public VirtualFunctions
{
    private:
        SDL_Renderer * gRenderer;
        SDL_Texture * assets;
        double gas_angle = 0;                                      //changed by saad
        SDL_Rect srcRect = {0, 0, 411, 150};
        SDL_Rect destRect;
        bool OutOfScreen ;
        int speed = 15; 
    public:
        FireGas(SDL_Renderer*, SDL_Texture*, SDL_Rect);
        void draw();
        void update();
        bool getOutOfScreen();
        SDL_Rect get_destRect();
};