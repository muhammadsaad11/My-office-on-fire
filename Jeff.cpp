#include "Jeff.hpp"
#include <iostream>
using namespace std;

Jeff::Jeff(SDL_Renderer *renderer, SDL_Texture *asst, SDL_Texture *bulletOn ) {
   gRenderer = renderer;
   assets = asst;
}

void Jeff::draw()
{
    SDL_RenderCopyEx(gRenderer, assets, &srcRect, &destRect, angle, NULL, SDL_FLIP_NONE);
}


void Jeff:: update(SDL_Texture* ext_asst)
{
    assets = ext_asst;
    SDL_RenderCopyEx(gRenderer, assets, &srcRect, &destRect, angle, NULL, SDL_FLIP_NONE);
}

// Keyboard input handling and actions performed here
void Jeff::movePlayer(char move , bool pressed)
{
    if (move == 'u') //Moving down don't be confused with the 'u' and 'd'
    {
        if (destRect.y >= 310)
        {
            destRect.y = 309;
        }
        destRect.y += 25;

    }
    else if (move == 'd') //Moving up
    {
        if (destRect.y <= 275)
        {
            destRect.y = 274;
        }
        destRect.y -= 25;
    }
    else if (move == 'l') //Moving left
    {
        destRect.x -= 20;
    }
    else if (move == 'r')
    {
        destRect.x += 20; //Moving right
    }
}

void Jeff::makeMove(char move, bool pressed)
{
   
}

SDL_Rect * Jeff::get_destRect()
{
    return &destRect;
}

int Jeff::get_angle()
{
    return angle;
}

void Jeff::set_destRect(int temp_Rect_x)
{
    destRect.x = temp_Rect_x;
}