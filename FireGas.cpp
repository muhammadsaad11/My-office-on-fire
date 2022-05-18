
#include "FireGas.hpp"
using namespace std;
#include<iostream>

FireGas::FireGas(SDL_Renderer *renderer, SDL_Texture *asst, SDL_Rect mover)
{
    gRenderer = renderer;
    assets = asst;
    destRect = mover;

    gas_angle = -3;  //changed by saad iqbal

    //adjusting the size of gas from fire extinguisher and position with the movement of player(jeff)

    destRect.y = mover.y + 110;
    destRect.x = mover.x + 120;

    destRect.w = 50;  //adjusting size of the gas
    destRect.h = 30;
}
void FireGas:: draw()
{
    SDL_RenderCopyEx(gRenderer, assets, &srcRect, &destRect, NULL, NULL, SDL_FLIP_NONE); //bullet drawn acc to pos of ship
}

//gives true if gas leaves screen without hitting any obstacle
bool FireGas:: getOutOfScreen()
{
    return OutOfScreen;
}


void FireGas:: update()
{
    if (destRect.y > -100) //checking if getting out of the screen completely
    { 
        destRect.y -= gas_angle;
        destRect.x += 15;
    }
    else
    {
        OutOfScreen = true;
    }       
}


SDL_Rect FireGas::get_destRect()
{
    return destRect;
}