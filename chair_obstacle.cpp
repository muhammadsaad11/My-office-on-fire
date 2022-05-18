#include "chair_obstacle.hpp"

Chair_Obstacle::Chair_Obstacle(SDL_Renderer *renderer, SDL_Texture *asst)
{
    gRenderer = renderer;
    assets = asst;
}


void Chair_Obstacle::update(SDL_Rect new_src, SDL_Rect new_dest, SDL_Texture* ext_asst)
{
    assets = ext_asst;
    srcRect = new_src;
    destRect = new_dest;
    SDL_RenderCopy(gRenderer, assets, &srcRect, &destRect);
}
//setters
void Chair_Obstacle::setsrcRect(SDL_Rect temp_Rect)
{
}
void Chair_Obstacle::setdestRect(SDL_Rect temp_Rect)
{
    destRect.x = temp_Rect.x;
    destRect.y = temp_Rect.y;
}

// Getters
SDL_Rect Chair_Obstacle::get_srcRect()
{
    return srcRect;
}

SDL_Rect Chair_Obstacle::get_destRect()
{
    return destRect;
}

void Chair_Obstacle::draw()
{
    SDL_RenderCopy(gRenderer, assets, &srcRect, &destRect);
    
    
}