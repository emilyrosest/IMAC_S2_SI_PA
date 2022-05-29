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
                
                switch (e.key.keysym.sym) { 
                    case SDLK_q:
                    case SDLK_LEFT:
                        thomas_the_player->updateThomasPosition(MOVE_LEFT, 0.5);
                        move(MOVE_RIGHT);
                        break;

                    case SDLK_d:
                    case SDLK_RIGHT:
                        thomas_the_player->updateThomasPosition(MOVE_RIGHT, 0.5);
                        move(MOVE_LEFT);
                        break;

                    case SDLK_SPACE:
                    case SDLK_z:
                    case SDLK_UP:
                        thomas_the_player->isOnTheFloor = this->game->quadtree_1->isOnTheFloor(thomas_the_player->x, thomas_the_player->y, thomas_the_player->height, thomas_the_player->width);
                        printf("isOnTheFloor = %d\n", thomas_the_player->isOnTheFloor);
                        thomas_the_player->updateThomasPosition(JUMP, 0.5);
                        move(DOWN);
                        break;

                    case SDLK_s:
                    case SDLK_DOWN:
                        thomas_the_player->updateThomasPosition(DOWN, 0.5);
                        move(JUMP);
                        break;

                    case SDLK_RETURN: //raccourci ;D
                        printf("fini!\n");
                        game->changeInterfaceToEnding();
                        break; 

                    case SDLK_i:
                        if (game->getLevel() == 2) {
                            changePlayer();
                            printf(" changement de player! ");
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
            game->map->initLevel2(X2, Y2, H2, W2);
            for (int i = 0; i < MAX_DECOR_COUNT_2; i++){
                allDecor2[i] = createAABB(X2[i], Y2[i], H2[i], W2[i], colorbox);
            }
            this->game->quadtree_2->insertAllDecor(allDecor2);
            printf("level up! \n");


            thomas_the_player = thomas_the_mover_3;

        }
    } 
    if (game->getLevel() == 2) {
        if (thomas_the_mover_3->win(*thomas_the_winner_3) && thomas_the_mover_2->win(*thomas_the_winner_2)) { 
            game->changeInterfaceToEnding();
        }
    }
}

void GamingInterface::render() {
    if (game->getLevel() == 1) {
        glPushMatrix();
        for (int i = 0; i < MAX_DECOR_COUNT; i++) {
            drawBox((allDecor1[i]));
        }
        thomas_the_winner_1->drawPlayer();
        thomas_the_mover_1->drawPlayer();
        glPopMatrix();
    } 

    
    

    if (game->getLevel() == 2) {
        glPushMatrix();
        for (int i = 0; i < MAX_DECOR_COUNT_2; i++) {
            drawBox((allDecor2[i]));
        }

        thomas_the_winner_2->drawPlayer();
        thomas_the_mover_2->drawPlayer();

        thomas_the_winner_3->drawPlayer();
        thomas_the_mover_3->drawPlayer();

        glPopMatrix();

        if (thomas_the_mover_3->win(*thomas_the_winner_3)) {
            Square* goal = new Square(thomas_the_winner_3->x, thomas_the_winner_3->y, thomas_the_winner_3->height, thomas_the_winner_3->width, Color(1., 1., 1.), 1);
            goal->drawSquare();
            //drawBox(createAABB(thomas_the_winner_3->x, thomas_the_winner_3->y, thomas_the_winner_3->height, thomas_the_winner_3->width, Color(1., 1., 1.)));
            thomas_the_player = thomas_the_mover_2;
        }
        if (thomas_the_mover_2->win(*thomas_the_winner_2)) {
            Square* goal_2 = new Square(thomas_the_winner_2->x, thomas_the_winner_2->y, thomas_the_winner_2->height, thomas_the_winner_2->width, Color(1., 1., 1.), 1);
            goal_2->drawSquare();
            //drawBox(createAABB(thomas_the_winner_2->x, thomas_the_winner_2->y, thomas_the_winner_2->height, thomas_the_winner_2->width, Color(1., 1., 1.)));
            thomas_the_player = thomas_the_mover_3;
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
        glTranslatef(0., -y, 0.);
    }
}

void GamingInterface::changePlayer() {
    if (thomas_the_player == thomas_the_mover_3) {
        printf(" je suis le 1e ");
        thomas_the_player = thomas_the_mover_2;
        return;
    }
    if (thomas_the_player == thomas_the_mover_2) {
        printf(" je suis le 2e ");
        thomas_the_player = thomas_the_mover_3;
        return;
    }
}


void GamingInterface::move(int direction) {
    if (game->getLevel() == 1) {
        if (this->game->quadtree_1->colliBool(thomas_the_player->x, thomas_the_player->y, thomas_the_player->height, thomas_the_player->width)) {
            thomas_the_player->updateThomasPosition(direction, 0.5);
        } 
    }
    if (game->getLevel() == 2) {
        if (this->game->quadtree_2->colliBool(thomas_the_player->x, thomas_the_player->y, thomas_the_player->height, thomas_the_player->width)) {
            thomas_the_player->updateThomasPosition(direction, 0.5);
        } 
    }
}

