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
        
        Uint32 startTime = SDL_GetTicks(); /* Recuperation du temps au debut de la boucle */
    
        
        game->swap();
        game->refresh();
        
        
        /* Calcul du temps ecoule */
        Uint32 elapsedTime = SDL_GetTicks() - startTime;
        /* Si trop peu de temps s'est ecoule, on met en pause le programme */
        if(elapsedTime < FRAMERATE_MILLISECONDS) 
        {
            SDL_Delay(FRAMERATE_MILLISECONDS - elapsedTime);
        }
    }

    game->clean();

    return 1;
}
