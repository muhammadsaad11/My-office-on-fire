#include "Status.hpp"



Status::Status(SDL_Renderer *renderer, SDL_Texture *asst)
{
    gRenderer = renderer;
    asset = asst;
    destRect[0] = {30, 30, 32, 64};
    destRect[1] = {70, 30, 32, 64};
    destRect[2] = {110, 30, 32, 64};
    destRect[3] = {150, 30, 32, 64};
    destRect[4] = {190, 30, 32, 64};
}

void Status::draw()
{
    for(int i = 0; i < life; i++)
    {
        SDL_RenderCopy( gRenderer, asset, &srcRect, &destRect[i]);
    }
}

void Status::decrementLife()
{
    life -= 1;
}

void Status::incrementLife()
{
    life += 1;
}

int Status::get_life()
{
    return life;
}