#include <SDL2/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <stdio.h>

#include "main.hpp"
#include "game.hpp"


Game* game = nullptr;


int main(int argc, char** argv) 
{
    game = new Game();


    while(game->running()) {
        
        Uint32 startTime = SDL_GetTicks();
    
        game->swap();

        game->refresh();
        
        Uint32 elapsedTime = SDL_GetTicks() - startTime;

        if(elapsedTime < FRAMERATE_MILLISECONDS) 
        {
            SDL_Delay(FRAMERATE_MILLISECONDS - elapsedTime);
        }
    }

    game->clean();

    return 1;
}
