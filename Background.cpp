#include "Background.hpp"

Background:: Background(){
    width = 1400;
    height = 600;
    background = NULL;
    temp_scrolling = 0;
}

Background:: ~Background(){
    SDL_DestroyTexture(background);
    width = height = temp_scrolling = 0;
}



void Background:: renderBackground(int x, int y, SDL_Renderer* gRenderer)
{
    SDL_Rect renderQuad = {x,y,width, height};
    SDL_RenderCopy(gRenderer, background, NULL, NULL);
}

void Background::drawBackground(SDL_Renderer* gRenderer)
{
    temp_scrolling -= 5;
    if (temp_scrolling < -width)
    {
        temp_scrolling = 0;
    }

    renderBackground(temp_scrolling, 0, gRenderer);
    renderBackground(temp_scrolling + width, 0, gRenderer);

}
void Background:: update(SDL_Renderer* gRenderer, SDL_Texture* ext_asst)
{
    background = ext_asst;
    SDL_RenderCopy(gRenderer, background, NULL, NULL);
}