#include "Elevator.hpp"

Elevator::Elevator(SDL_Renderer *renderer, SDL_Texture *asst)
{
    win_count = 0;
    gRenderer = renderer;
    assets = asst;
    srcRect = {0, 0 , 149, 399};
    destRect = {1251, 200, 149, 399}; 
}



// Getters
SDL_Rect Elevator::get_srcRect()
{
    return srcRect;
}

SDL_Rect Elevator::get_destRect()
{
    return destRect;
}

void Elevator::draw()
{
    SDL_RenderCopy(gRenderer, assets, &srcRect, &destRect);
    
}

void Elevator::update(SDL_Rect new_src, SDL_Rect new_dest, SDL_Texture* ext_asst)
{
    assets = ext_asst;
    srcRect = new_src;
    destRect = new_dest;
    SDL_RenderCopy(gRenderer, assets, &srcRect, &destRect);
}