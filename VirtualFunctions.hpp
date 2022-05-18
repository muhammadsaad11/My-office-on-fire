#include <SDL.h>
#pragma once
using namespace std;

class VirtualFunctions
{
public:
    virtual void draw();
    virtual void update();
    virtual void InputHandle(SDL_Event e);
};