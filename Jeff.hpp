#include <SDL.h>
#include "FireGas.hpp"
#include "Background.hpp" 
#include <string>
#include <list>

#pragma once

using namespace std;
class Jeff : public VirtualFunctions 
{
    private:
        SDL_Renderer * gRenderer;
        SDL_Texture * assets;
        double angle = 0;
        SDL_Rect srcRect = {0, 0, 152, 272};   
        SDL_Rect destRect = {0, 322, 152, 272}; 

    public:
        Jeff(SDL_Renderer*, SDL_Texture*, SDL_Texture*);
        void movePlayer(char move, bool pressed);
        void draw();
        void update(SDL_Texture*);
        void makeMove(char move, bool pressed);
        SDL_Rect *get_destRect();
        int get_angle();
        void set_destRect(int);

};