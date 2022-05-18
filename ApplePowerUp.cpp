#include "ApplePowerUp.hpp"

Apple_PowerUp::Apple_PowerUp(SDL_Renderer *renderer, SDL_Texture *asst)
{
    gRenderer = renderer;
    assets = asst;
    srcRect = {0, 0 , 44, 43};
    destRect = {650, 400, 44, 43}; 
}


void Apple_PowerUp::update(SDL_Rect new_src, SDL_Rect new_dest, SDL_Texture* ext_asst)
{
    assets = ext_asst;
    srcRect = new_src;
    destRect = new_dest;
    SDL_RenderCopy(gRenderer, assets, &srcRect, &destRect);
}

// Getters
SDL_Rect Apple_PowerUp::get_srcRect()
{
    return srcRect;
}

SDL_Rect Apple_PowerUp::get_destRect()
{
    return destRect;
}

void Apple_PowerUp::draw()
{
    SDL_RenderCopy(gRenderer, assets, &srcRect, &destRect);
    
    
}