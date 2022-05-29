#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdlib.h>
#include <stdio.h>

#include "../include/gamingInterface.hpp"

void GamingInterface::prepare() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glScalef(0.1, 0.1, 0.);
    
}

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
                //printf("clic en (%d, %d)\n", e.button.x, e.button.y);
                break;
                
            /* Touche clavier */
            case SDL_KEYDOWN:
                
                switch (e.key.keysym.sym) { // Quelle touche est appuyée ?
                    case SDLK_q:
                    case SDLK_LEFT:
                        if (!this->game->quadtree_1->colliBool(thomas_the_player->x, thomas_the_player->y, thomas_the_player->height, thomas_the_player->width)) {
                            thomas_the_player->updateThomasPosition(MOVE_LEFT);
                        }
                        break;

                    case SDLK_d:
                    case SDLK_RIGHT:
                        if (!this->game->quadtree_1->colliBool(thomas_the_player->x, thomas_the_player->y, thomas_the_player->height, thomas_the_player->width)) {
                            thomas_the_player->updateThomasPosition(MOVE_RIGHT);
                        }
                        break;

                    case SDLK_SPACE:
                    case SDLK_z:
                    case SDLK_UP:
                        if (!this->game->quadtree_1->colliBool(thomas_the_player->x, thomas_the_player->y, thomas_the_player->height, thomas_the_player->width)) {
                            
                            thomas_the_player->isOnTheFloor = this->game->quadtree_1->isOnTheFloor(thomas_the_player->x, thomas_the_player->y, thomas_the_player->height, thomas_the_player->width);
                            printf("isOnTheFloor = %d\n", thomas_the_player->isOnTheFloor);
                            thomas_the_player->updateThomasPosition(JUMP);
                            
                        }
                        break;

                    case SDLK_s:
                    case SDLK_DOWN:
                        if (!this->game->quadtree_1->colliBool(thomas_the_player->x, thomas_the_player->y, thomas_the_player->height, thomas_the_player->width)) {
                            thomas_the_player->updateThomasPosition(DOWN);
                        }
                        break;

                    case SDLK_RETURN:
                        //a enlever !!!!!
                        printf("ca veut ending \n");
                        game->changeInterfaceToEnding();
                        break; 
                    case SDLK_i:
                        if (game->getLevel() == 2) {
                            changePlayer();
                            printf(" ca change player ");
                        }
                        break; 
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
    
    camera(thomas_the_player->x, thomas_the_player->y);

    if (game->getLevel() == 1) {
        if (thomas_the_mover_1->win(*thomas_the_winner_1)) {
            game->levelUp();
            thomas_the_mover_1->x = 0.;
            thomas_the_mover_1->y = 0.;
            game->map->initLevel2(X2, Y2, H2, W2);
            for (int i = 0; i < MAX_DECOR_COUNT; i++){
            //allDecor[i] = createAABB(Position(X[i], Y[i]), H[i], W[i]);
                allDecor2[i] = createAABB(X2[i], Y2[i], H2[i], W2[i], colorbox);
            }
            printf("ca level up ");
        }
    } 
    if (game->getLevel() == 2) {
        /*
        if (thomas_the_mover_1->win(*thomas_the_winner_1)) {
            //thomas_the_mover_1 = new Player(thomas_the_winner_1->x, thomas_the_winner_1->y, thomas_the_mover_1->height, thomas_the_player->width, Color(1., 1., 1.), 1);
            drawBox(createAABB(thomas_the_winner_1->x, thomas_the_winner_1->y, thomas_the_winner_1->height, thomas_the_winner_1->width, Color(1., 1., 1.)));
            thomas_the_player = thomas_the_mover_2;
        } */
        if (thomas_the_mover_1->win(*thomas_the_winner_1) && thomas_the_mover_2->win(*thomas_the_winner_2)) { 
            game->changeInterfaceToEnding();
        }
    }
}

void GamingInterface::render() {
    if (game->getLevel() == 1) {
        for (int i = 0; i < MAX_DECOR_COUNT; i++) {
            drawBox((allDecor1[i]));
        }
    } 

    thomas_the_winner_1->drawPlayer();
    
    thomas_the_mover_1->drawPlayer();
    

    if (game->getLevel() == 2) {
        thomas_the_winner_2->drawPlayer();
        thomas_the_mover_2->drawPlayer();
        for (int i = 0; i < MAX_DECOR_COUNT; i++) {
            drawBox((allDecor2[i]));
        }

        if (thomas_the_mover_1->win(*thomas_the_winner_1)) {
            drawBox(createAABB(thomas_the_winner_1->x, thomas_the_winner_1->y, thomas_the_winner_1->height, thomas_the_winner_1->width, Color(1., 1., 1.)));
            thomas_the_player = thomas_the_mover_2;
        }

    }
}


void GamingInterface::camera(float x, float y) {
    if (thomas_the_player->x > 0) {
        glTranslatef(-x, 0., 0.);
    }
    if (thomas_the_player->x < 0) {
        glTranslatef(-x, 0., 0.);
    }
    if (thomas_the_player->y > 0) {
        glTranslatef(0., -y, 0.);
    }
    if (thomas_the_player->y < 0) {
        glTranslatef(0., y, 0.);
    }
}

void GamingInterface::changePlayer() {
    if (thomas_the_player == thomas_the_mover_1) {
        printf(" je suis le 1e ");
        thomas_the_player = thomas_the_mover_2;
        return;
    }
    if (thomas_the_player == thomas_the_mover_2) {
        printf(" je suis le 2e ");
        thomas_the_player = thomas_the_mover_1;
        return;
    }
}



