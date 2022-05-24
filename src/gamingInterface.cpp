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

    //this->game->quadtree->insertAllDecor(allDecor);
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
                        thomas_the_player->updateThomasPosition(MOVE_LEFT);
                        break;

                    case SDLK_d:
                    case SDLK_RIGHT:
                        thomas_the_player->updateThomasPosition(MOVE_RIGHT);
                        break;
                    case SDLK_SPACE:
                    case SDLK_z:
                    case SDLK_UP:
                        thomas_the_player->updateThomasPosition(JUMP);
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
            printf("ca level up ");
        }
    } 
    if (game->getLevel() == 2) {
        if (thomas_the_mover_1->win(*thomas_the_winner_1) && thomas_the_mover_2->win(*thomas_the_winner_2)) { 
            game->changeInterfaceToEnding();
        }
    }

/*
    if (thomas_the_player->win(*thomas_the_winner)) {
        game->changeInterfaceToEnding();
    }


    if (thomas_the_mover_1->win(*thomas_the_winner_1)) {
        game->changeInterfaceToEnding();
    }
    */
}

void GamingInterface::render() {
    /*
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glScalef(0.1, 0.1, 0.);

    camera(thomas_the_player->x, thomas_the_player->y);
    */

    if (game->getLevel() == 1) {
        this->game->quadtree->insertAllDecor(allDecor);
    }

    thomas_the_winner_1->drawPlayer();
    
    thomas_the_mover_1->drawPlayer();
    

    if (game->getLevel() == 2) {
        thomas_the_winner_2->drawPlayer();
        thomas_the_mover_2->drawPlayer();
    }

    //printf("quadtree %d ", (int)this->game->quadtree->search((Position(thomas_the_player->x, thomas_the_player->y)))->boxes[0]->position.x);
        
    if (!collision()) {
        printf("pas de collision");
    }
    if (collision()) {
        //printf(" collision ");
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

bool GamingInterface::collision() {
    QuadTree* quadTreeToTest = this->game->quadtree->search(Position(thomas_the_player->x, thomas_the_player->y));
    for (int i = 0; i < quadTreeToTest->getBoxCount(); i++) {
        if (( thomas_the_player->x >= quadTreeToTest->getAABB(i).position.x + quadTreeToTest->getAABB(i).weight )      // trop à droite
        || (thomas_the_player->x + thomas_the_player->width <= quadTreeToTest->getAABB(i).position.x)) {// trop à gauche 
        return false;
        }
    } 
    return true; 
    /*
    for (int i = 0; i < quadTreeToTest->getBoxCount(); i++) {
        if (( thomas_the_player->x >= quadTreeToTest->getAABB(i).position.x + quadTreeToTest->getAABB(i).weight )      // trop à droite
        || (thomas_the_player->x + thomas_the_player->width <= quadTreeToTest->getAABB(i).position.x) // trop à gauche
        || (thomas_the_player->y >= quadTreeToTest->getAABB(i).position.y + quadTreeToTest->getAABB(i).height) // trop en bas
        || (thomas_the_player->y + thomas_the_player->height <= quadTreeToTest->getAABB(i).position.y)) {
        }
        return false;
    } 
    return true; 
    */
    /*
    this->game->quadtree->search((Position(thomas_the_player->x, thomas_the_player->y)))
    if((box2.position.x >= box1.position.x + box1.weight)      // trop à droite
     (box2.position.x + box2.weight <= box1.position.x) // trop à gauche
     (box2.position.y >= box1.position.y + box1.height) // trop en bas
    || (box2.position.y + box2.height <= box1.position.y))  // trop en haut
          return false; 
   else
          return true; 
          */
}
