#include "Game.hpp"
#include <list>
#include <time.h>
using namespace std;


bool Game:: unlock_extinguish = false;
int Game:: extinguish_throw_count = 0;


bool Game::init()
{


	bool success = true;
	
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{


		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		gWindow = SDL_CreateWindow( "Office On Fire", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else 
		{
			
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
			if( gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
			
				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}
				if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
				{
					printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
					success = false;
				}
				
			}
		}
	}

	return success;
}

bool Game::loadMedia()

{
	//Loading success flag
	bool success = true;
    gTexture = loadTexture("first_floor.png"); 
	
	
	bgMusic = Mix_LoadMUS( "office_fire_BGM1.wav" );


	jeff_tex = loadTexture("jeff23.png");
	
	
	
	game_win_tex = loadTexture("you_won.png");
	game_over_tex = loadTexture("game_over.png");
	elevator_tex = loadTexture("elevator_first_floor.png");
	life_tex = loadTexture("jeff.png");
	firegas_tex = loadTexture("extinguish_fire1.png");
	menu_tex = loadTexture("MainScreen.png");
	fire_tex = loadTexture("flame_small.png");
	howtoplay_tex = loadTexture("how_to_play.png");
	smoke_tex = loadTexture("smoke.png");

	fire_extinguisher_tex = loadTexture("fire_extinguisher.png"); //extinguisher object that would enable us to use gas.

	apple_powerup_tex = loadTexture("apple_pup.png");  //apple powerup which would increase the health of our character.

	chair_obstacle_tex = loadTexture("chair_rs.png"); //chair obstacle which would decrease the health of our character.


	if (gTexture==NULL ||bgMusic == NULL || jeff_tex == NULL || firegas_tex == NULL || menu_tex == NULL || fire_tex== NULL || howtoplay_tex == NULL) 
    {
        printf("Unable to run due to error: %s\n",SDL_GetError());
        success =false;
    }

	return success;
}

void Game::close()
{
	gTexture=NULL;
	SDL_DestroyTexture(gTexture);
	SDL_DestroyTexture(game_win_tex);
	SDL_DestroyTexture(game_over_tex);
	SDL_DestroyTexture(elevator_tex);
	SDL_DestroyTexture(jeff_tex);
	SDL_DestroyTexture(firegas_tex);
	SDL_DestroyTexture(menu_tex);
	SDL_DestroyTexture(fire_tex);
	SDL_DestroyTexture(howtoplay_tex);
	SDL_DestroyTexture(smoke_tex);

	SDL_DestroyTexture(chair_obstacle_tex);
	SDL_DestroyTexture(apple_powerup_tex);

	//Destroy window
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;

	//free music
	Mix_FreeMusic( bgMusic );
    bgMusic = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

SDL_Texture* Game::loadTexture( std::string path ) //basically converting image to surface to texture
{
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL)
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}

		SDL_FreeSurface( loadedSurface );
	}

	return newTexture;
}

void Game:: DrawAllObjects() //Drawing objects according to the running game
{
    SDL_SetRenderDrawColor( gRenderer, 255, 255, 255, 255 );
    SDL_RenderClear(gRenderer);
   
	
	list<Elevator*>::iterator ev;

   	list<Fire*>::iterator it;

	list<Apple_PowerUp*>::iterator ap;

	list<Chair_Obstacle*>::iterator ch;

	list<FireExtinguisher*>::iterator fe;

	switch(game_status)
	{
		case MENU:
			SDL_RenderCopy(gRenderer, menu_tex, NULL, NULL); //draws menu image
			break;

		case HOWTOPLAY:
			SDL_RenderCopy(gRenderer, howtoplay_tex, NULL, NULL); 
			break;

		case PLAY:
			textureBG.drawBackground(gRenderer); 	// It is drawing background here
			stats->draw();					// It is drawing health x 3 here
			for (list<FireGas*>::const_iterator iter = this->gases.begin(),end = this->gases.end();iter != end;++iter)
			{
				
				(*iter)->draw();			// It is drawing gas here
			}
			for (it = fireS.begin(); it != fireS.end(); it++)
			{		
				(*it)->draw(); 				// It is drawing fire here
			}

			for (ap = apple_p.begin(); ap != apple_p.end(); ap++)
			{		
				(*ap)->draw(); 				// It is drawing apples here.
			}

			for (ch = chair_c.begin(); ch != chair_c.end(); ch++)
			{		
				(*ch)->draw(); 				// It is drawing chair here.
			}

			for (fe = fire_e.begin(); fe != fire_e.end(); fe++)
			{		
				(*fe)->draw(); 				// It is drawing fire extinguisher here.
			}
			for (ev = elevator_ev.begin(); ev != elevator_ev.end(); ev++)
			{		
				(*ev)->draw(); 				// Drawing elevator for navigating from one level to another (one floor of the building to another)
			}
			//apple_p->draw();

			for (list<Smoke*>::const_iterator iter = this->smokevanish.begin(),end = this->smokevanish.end();iter != end;++iter)
			{ 
				(*iter)->draw();			// It is drawing the somking effect after the fire is gone
				smokevanish.erase(iter++); 
				
			}
			player_jeff -> draw(); 				// It is drawing player(jeff) here
			break;

			
			

		case GAMEOVER:
			SDL_RenderCopy(gRenderer, game_over_tex, NULL, NULL);
			break;
		case WIN:
			SDL_RenderCopy(gRenderer, game_win_tex, NULL, NULL);
			break;
	}
    SDL_RenderPresent(gRenderer);
}

// checks for collison between objects
void Game::CollisionDetection()
{
	int temp;
	SDL_Rect tempRect; // Rectangle to change for jeff
	SDL_Rect tempRect1; // Rectangle to change for fire
	SDL_Rect tempRect2; //Rectangle to change for chair
	SDL_Rect tempRect3; //Rectangle to change for Floor level 2
	const SDL_Rect S = *player_jeff->get_destRect(); // get current position of ship
	tempRect = {S.x, S.y + (S.h * 0.9), S.w, S.h * 0.1};
	for (list<Fire*>::const_iterator iter = this->fireS.begin(),end = this->fireS.end();iter != end;++iter)
	{
		const SDL_Rect A = (*iter)->get_destRect(); // get current position of fire
		tempRect1 = {A.x, A.y + (A.h * 0.9), A.w, A.h * 0.1};
		

		// Checking for collision between fire and gas here

		for (list<FireGas*>::const_iterator obj = this->gases.begin(),end = this->gases.end(); obj != end;++obj) //loop to check collision of egg with each nest
		{
			const SDL_Rect B =  (*obj) -> get_destRect(); // Getting current position of fire here
			if (SDL_HasIntersection(&A,&B))
			{ 
				gases.erase(obj++);  		// Gas goes away here
				fireS.erase(iter++); 	//Fire goes away here
				Smoke * a = new Smoke(gRenderer, smoke_tex, A);
				smokevanish.push_back(a);
			}
		}

		//Checking for collision between fire and person here

		if (SDL_HasIntersection(&tempRect1,&tempRect))
		{
			stats->decrementLife();		// Life decreases by 1
			fireS.erase(iter++);
		}
	}



	for (list<Apple_PowerUp*>::const_iterator iter = this->apple_p.begin(),end = this->apple_p.end();iter != end;++iter)
	{
		const SDL_Rect P = (*iter)->get_destRect(); //Getting current position of fire here

		//Checking for collision between person and apple here

		if (SDL_HasIntersection(&P,&S))
		{
			apple_p.erase(iter++);
			stats->incrementLife();	// life increases by 1
		}
	}

	for (list<FireExtinguisher*>::const_iterator iter = this->fire_e.begin(),end = this->fire_e.end();iter != end;++iter)
	{
		const SDL_Rect F = (*iter)->get_destRect(); //Getting current position of fire_extinguisher

		if (SDL_HasIntersection(&F,&S))
		{
			fire_e.erase(iter++);
			unlock_extinguish = true;
			extinguish_throw_count = 3;  //how many throws you get per extinguisher
			
			jeff_tex = loadTexture("jeff23_with_ext.png");
			player_jeff->update(jeff_tex);
		}
	}
	for (list<Elevator*>::const_iterator iter = this->elevator_ev.begin(),end = this->elevator_ev.end();iter != end;++iter)
	{
		const SDL_Rect ELV = (*iter)->get_destRect(); // get current position of fire_extinguisher
		tempRect3 = {ELV.x + (ELV.h * 0.6), ELV.y + (ELV.h * 0.5), ELV.w, ELV.h * 0.5};

		if (SDL_HasIntersection(&tempRect3,&S))
		{
			player_jeff->set_destRect(0);
			gTexture = loadTexture("background2.png");   //Changing level here
			fire_tex = loadTexture("big_fire.png");
			textureBG.update(gRenderer,gTexture);
			elevator_ev.front()->win_count += 1;
			if (elevator_ev.front()->win_count == 2)
			{
				//cout<<elevator_ev.front()->win_count<<endl; //Testing
				game_status = WIN;
			}
			elevator_tex = loadTexture("elevator_second_floor.png");

			elevator_ev.front()->update({0, 0 , 149, 399}, {1251, 200, 149, 399}, elevator_tex);
			fireS.front()->update({0, 0, 211, 77}, {570, 450, 211, 77}, fire_tex);
		}
	}
	for (list<Chair_Obstacle*>::const_iterator iter = this->chair_c.begin(), end = this->chair_c.end(); iter != end; ++iter)
	{
		const SDL_Rect C = (*iter)->get_destRect();
		tempRect2 = {C.x, C.y + (C.h * 0.8), C.w, C.h * 0.2};
		if (SDL_HasIntersection(&tempRect2, &tempRect))
		{
			chair_c.erase(iter++);
			stats->decrementLife();
		}
	}
	temp = stats->get_life();
	if (temp == 0)
	{
		// cout << "hello!" << endl; //Testing
		game_status = GAMEOVER;
	}
	

}

//Updating objects according to the running game state
void Game:: UpdateObjects()
{
	list<Fire*>::iterator it;
	switch(game_status)
	{
		case MENU:
			break;

		case PLAY:

			CollisionDetection();
			
			//Updating gas position here
			for (list<FireGas*>::const_iterator iter = this->gases.begin(),end = this->gases.end();iter != end;++iter)
			{
				(*iter)->update();
			}
			if (extinguish_throw_count <=0)
			{
				jeff_tex = loadTexture("jeff23.png");
				player_jeff->update(jeff_tex);
			}
			break;
	}
}


//Event Handling
bool Game:: HandleEvents(SDL_Event e)
{
	while( SDL_PollEvent( &e ) != 0 )
	{
		
		switch(game_status)
		{
			case MENU:
				if( e.type == SDL_QUIT )
				{
					quit = true;
				}
				else if(e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT)
				{
					int xMouse, yMouse;
					SDL_GetMouseState(&xMouse,&yMouse);
					if ((xMouse >= 720 && xMouse <= 900) &&  ( yMouse >= 160 && yMouse <= 230))
					{
						game_status = PLAY ; //NewGame clicked
					}
					else if((xMouse >= 720 && xMouse <= 900) && ( yMouse>=250 && yMouse <= 320))
					{ 
						game_status = HOWTOPLAY; 
					}

				}
				break;
			case HOWTOPLAY:
				if( e.type == SDL_QUIT )
				{
					quit = true;
				}
				else if(e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT)
				{
					int xMouse, yMouse;
					SDL_GetMouseState(&xMouse,&yMouse);
					if( (xMouse >= 0 && xMouse <= 32) && ( yMouse>=0 && yMouse <= 34 ))
					{ 
						game_status = MENU; 
					}
				}
				break;

			case PLAY:
				if( e.type == SDL_QUIT )
				{
					quit = true;
				}
				if(e.type == SDL_KEYDOWN)
				{
					switch (e.key.keysym.sym)
					{
					case SDLK_s:
						player_jeff->movePlayer('u',1); // moving down
						break;

					case SDLK_w:
						player_jeff->movePlayer('d',1); //moving up
						break;

					case SDLK_a:
						player_jeff->movePlayer('l',1);
						break;

					case SDLK_d:
						player_jeff->movePlayer('r',1);
						break;
						
					case SDLK_SPACE: //Adding gas in the extinguisher here with the maximum of three charges

						if (unlock_extinguish == true and extinguish_throw_count > 0)
						{
							FireGas* g = new FireGas(gRenderer, firegas_tex, *player_jeff->get_destRect());
							gases.push_back(g);
							extinguish_throw_count --;
							break;
						} 
						
					}
				}
			case GAMEOVER:
				if( e.type == SDL_QUIT )
				{
					quit = true;
				}
			case WIN:
				if( e.type == SDL_QUIT )
				{
					quit = true;
				}
				break;

		}
	}
	return false;
}






void Game::init_levels()
{

	for (int i=0; i<1; i++)
	{
		Fire* s = new Fire(gRenderer, fire_tex);
		fireS.push_back(s);

		Fire* s1 = new Fire(gRenderer, fire_tex);
		s1->setdestRect({600, 440, 62, 77});
		fireS.push_back(s1);

		Fire* s2 = new Fire(gRenderer, fire_tex);
		s2->setdestRect({600, 520, 62, 77});
		fireS.push_back(s2);



		Apple_PowerUp* appup = new Apple_PowerUp(gRenderer, apple_powerup_tex);
		apple_p.push_back(appup);

		Chair_Obstacle* chairob = new Chair_Obstacle(gRenderer, chair_obstacle_tex);
		chair_c.push_back(chairob);

		Chair_Obstacle* chairob1 = new Chair_Obstacle(gRenderer, chair_obstacle_tex);
		chairob1->setdestRect({900, 422, 63, 100});
		chair_c.push_back(chairob1);
		 
	}
	for (int j = 0; j<1; j++)
	{
		FireExtinguisher* fiex = new FireExtinguisher(gRenderer, fire_extinguisher_tex);
		fire_e.push_back(fiex);
	}
	Elevator* elev = new Elevator(gRenderer, elevator_tex);
	elevator_ev.push_back(elev);
}
		
void Game::run()
{
	player_jeff = new Jeff(gRenderer, jeff_tex, firegas_tex);

	

	stats = new Status(gRenderer, life_tex);
	textureBG.background = gTexture;
	init_levels();

    SDL_RenderClear( gRenderer ); //Clear the entire screen 
	bool paused = false;

	SDL_Event e;
	while( !quit )
	{
		HandleEvents(e);
		UpdateObjects();
		DrawAllObjects();
		
		//for music
		if( Mix_PlayingMusic() == 0 )
		{
			Mix_PlayMusic( bgMusic, 1 );
		}
		
		SDL_Delay(50);	//causes sdl engine to delay for specified miliseconds//delay for seconds so the window doesn't just disappear.

	}

}

