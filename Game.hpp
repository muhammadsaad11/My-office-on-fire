#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <list>
#include <time.h>
#include <SDL_mixer.h>
#include "Jeff.hpp"
#include "Fire.hpp"
#include "FireGas.hpp"
#include "Background.hpp"
#include "Smoke.hpp"
#include "Status.hpp"

#include "FireExtinguisher.hpp"
#include "ApplePowerUp.hpp"
#include "chair_obstacle.hpp"
#include "Elevator.hpp"

#include "VirtualFunctions.hpp"

using namespace std;

class Game{

    protected:
    //Screen dimension constants
    const int SCREEN_WIDTH = 1400;
    const int SCREEN_HEIGHT = 600;

    //The window we'll be rendering to
    SDL_Window* gWindow = NULL;

    //The window renderer
    SDL_Renderer* gRenderer = NULL;

    //Current displayed texture---(a 2d image maybe)
    SDL_Texture* game_over_tex = NULL;
    SDL_Texture* game_win_tex = NULL;
    SDL_Texture* elevator_tex = NULL;

    SDL_Texture* gTexture = NULL;
    SDL_Texture* jeff_tex = NULL;
    SDL_Texture* life_tex = NULL;
    SDL_Texture* firegas_tex = NULL;
    SDL_Texture* menu_tex = NULL;
    SDL_Texture* fire_tex = NULL;

    SDL_Texture* chair_obstacle_tex = NULL;
    SDL_Texture* apple_powerup_tex = NULL;
    SDL_Texture* fire_extinguisher_tex = NULL;

    SDL_Texture* howtoplay_tex = NULL;
    SDL_Texture* smoke_tex = NULL;
    Mix_Music *bgMusic = NULL;
    
    Jeff* player_jeff;
    list<Elevator*> elevator_ev;
    list<Fire*>fireS;
    list<FireGas*> gases;
    list<Smoke*> smokevanish;

    list<Chair_Obstacle*> chair_c;
    list<Apple_PowerUp*> apple_p;
    list<FireExtinguisher*> fire_e;

    Background textureBG;
    Status* stats;

public:

    bool init(); 
    bool loadMedia(); 
    void close(); 
    SDL_Texture* loadTexture( std::string path );
    void run();
    void DrawAllObjects();
    void UpdateObjects();
    bool HandleEvents(SDL_Event e);
    void init_levels();
    void CollisionDetection();

    static bool unlock_extinguish; //unlocking the extinguishing power
    static int extinguish_throw_count;  // how much throws can be done with a single extinguisher powerup;
    
    bool quit = false;
    enum game_states
    {
        MENU = 0,
        HOWTOPLAY = 1,
        PLAY = 2,
        GAMEOVER = 3,
        WIN = 4
    };
    int game_status = MENU;
    
    
};

