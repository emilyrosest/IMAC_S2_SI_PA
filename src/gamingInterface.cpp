#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdlib.h>
#include <stdio.h>

#include "../include/gamingInterface.hpp"


void GamingInterface::handleEvents() {
    SDL_Event e = game->e;
    while(SDL_PollEvent(&e)) {
        /* L'utilisateur ferme la fenetre : */
		if(e.type == SDL_QUIT) {
			game->setRunning(0);
			break;
		}
		
		if(	e.type == SDL_KEYDOWN && (e.key.keysym.sym == SDLK_ESCAPE)) {
			game->setRunning(0);
			break;
		}
            
        switch(e.type) 
        {
            case SDL_WINDOWEVENT:
                switch (e.window.event) 
                {
                    /* Redimensionnement fenetre */
                    case SDL_WINDOWEVENT_RESIZED:
                        game->onWindowResized(e.window.data1, e.window.data2);                
                        break;

                    default:
                        break; 
                }
                break;

            /* Clic souris */
            case SDL_MOUSEBUTTONUP:
                printf("clic en (%d, %d)\n", e.button.x, e.button.y);
                break;
                
            /* Touche clavier */
            case SDL_KEYDOWN:

                switch (e.key.keysym.sym) { // Quelle touche est appuyée ?
                    case SDLK_q:
                    case SDLK_LEFT:
                        game->thomas_the_player->updateThomasPosition(MOVE_LEFT);
                        printf("pret a bouger lol \n");
                        //printf("%f\n", this->thomas_the_player->position.x);
                        break;

                    case SDLK_d:
                    case SDLK_RIGHT:
                        game->thomas_the_player->updateThomasPosition(MOVE_RIGHT);
                        printf("pret a bouger lol \n");
                        //printf("%f\n", this->thomas_the_player->position.x);
                        break;
                    case SDLK_SPACE:
                    case SDLK_z:
                    case SDLK_UP:
                        game->thomas_the_player->updateThomasPosition(JUMP);
                        printf("pret a sauter\n");
                    default:
                        break;
                }
                break;
                    
            default:
                break;
        }
    }
}

void GamingInterface::update() {

}

void GamingInterface::render() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    game->thomas_the_player->drawPlayer();
    
    map->drawMap();
}