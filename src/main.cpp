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

//Map *map = nullptr;

int main(int argc, char** argv) 
{
    game = new Game();

    //printf("begin\n");
    while(game->running()) {
        /* Recuperation du temps au debut de la boucle */
        Uint32 startTime = SDL_GetTicks();
    
        
        /* Echange du front et du back buffer : mise a jour de la fenetre */
        
        game->swap();
        game->handleEvents();
        game->refresh();
        

        //marche pas, erreur de segmentation lorsque affichage de texture
        //map->InitMap(); 
        //map->drawMap();

    
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
