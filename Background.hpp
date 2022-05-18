#include <SDL.h>
#pragma once

class Background
{
    public:
        SDL_Texture* background;
        int width, height, temp_scrolling;
    
        Background();
        ~Background();
        
        void update(SDL_Renderer*, SDL_Texture*);
        void renderBackground(int, int, SDL_Renderer*);
        void drawBackground(SDL_Renderer*);



};  