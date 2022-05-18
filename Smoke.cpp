#include "Smoke.hpp"

void Smoke::draw()
{
    SDL_RenderCopy(gRenderer, assets, &srcRect, &destRect); 
}