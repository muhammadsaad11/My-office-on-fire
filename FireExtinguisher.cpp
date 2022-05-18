#include "FireExtinguisher.hpp"

FireExtinguisher::FireExtinguisher(SDL_Renderer *renderer, SDL_Texture *asst)
{
    gRenderer = renderer;
    assets = asst;
    srcRect = {0, 0 , 40, 67};
    destRect = {200, 300, 40, 67}; 
}



// Getters
SDL_Rect FireExtinguisher::get_srcRect()
{
    return srcRect;
}

SDL_Rect FireExtinguisher::get_destRect()
{
    return destRect;
}

void FireExtinguisher::draw()
{
    SDL_RenderCopy(gRenderer, assets, &srcRect, &destRect);
    
}