#include "Fire.hpp"

Fire::Fire(SDL_Renderer *renderer, SDL_Texture *asst)
{
    gRenderer = renderer;
    assets = asst;
}


void Fire::update(SDL_Rect new_src, SDL_Rect new_dest, SDL_Texture* ext_asst)
{
    assets = ext_asst;
    srcRect = new_src;
    destRect = new_dest;
    SDL_RenderCopy(gRenderer, assets, &srcRect, &destRect);
}

// Getters
SDL_Rect Fire::get_srcRect()
{
    return srcRect;
}

SDL_Rect Fire::get_destRect()
{
    return destRect;
}

//Setters
void Fire::setsrcRect(SDL_Rect temp_Rect)
{
}
void Fire::setdestRect(SDL_Rect temp_Rect)
{
    destRect.x = temp_Rect.x;
    destRect.y = temp_Rect.y;
}
void Fire::draw()
{
    SDL_RenderCopy(gRenderer, assets, &srcRect, &destRect);
    
}