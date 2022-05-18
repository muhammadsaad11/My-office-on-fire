#include "game.hpp"

int main(int argc, char *argv[]){ 
    Game game;
    srand((unsigned)time(0));
    // Start up SDL and create window
    if( !game.init() ){
		printf( "Failed to initialize!\n" );
        return 0;
	}
    if( !game.loadMedia() ){
        printf( "Failed to load media!\n" );
        return 0;
    }
    game.run();
    game.close();

    return 0;
}


// g++ *.cpp -IC:\mingw_dev_lib\include\SDL2 -LC:\mingw_dev_lib\lib -w -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf

