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
                        thomas_the_player->updateThomasPosition(MOVE_LEFT);
                        //collision3(MOVE_LEFT);
                        break;

                    case SDLK_d:
                    case SDLK_RIGHT:
                        thomas_the_player->updateThomasPosition(MOVE_RIGHT);
                        //collision3(MOVE_RIGHT);
                        /*
                        for (int i = 0; i < this->game->quadtree->search2(thomas_the_player->x, thomas_the_player->y)->getBoxCount(); i++) {
                            if (collision2(this->game->quadtree->searchAABB(thomas_the_player->x, thomas_the_player->y)[i])) {
                                thomas_the_player->updateThomasPosition(MOVE_LEFT);
                                printf( "retour gauche ");
                            }
                        }*/
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
            game->map->initLevel2(X2, Y2, H2, W2);
            for (int i = 0; i < MAX_DECOR_COUNT; i++){
            //allDecor[i] = createAABB(Position(X[i], Y[i]), H[i], W[i]);
                allDecor2[i] = createAABB(X2[i], Y2[i], H2[i], W2[i], colorbox);
            }
            printf("ca level up ");
        }
    } 
    if (game->getLevel() == 2) {
        if (thomas_the_mover_1->win(*thomas_the_winner_1) && thomas_the_mover_2->win(*thomas_the_winner_2)) { 
            game->changeInterfaceToEnding();
        }
    }

    
    //collision3(MOVE_RIGHT);

/*
    for (int i = 0; i < this->game->quadtree->search2(thomas_the_player->x, thomas_the_player->y)->getBoxCount(); i++) {
        if (collisionRight(this->game->quadtree->searchAABB(thomas_the_player->x, thomas_the_player->y)[i])) {
            thomas_the_player->updateThomasPosition(MOVE_LEFT);
            printf("collision droite ");
        } else { printf(" pas collision "); }
    }
  */
    //printf(" %d ", this->game->quadtree->search(Position(thomas_the_player->x, thomas_the_player->y))->getBoxCount());

/*
    if (thomas_the_player->win(*thomas_the_winner)) {
        game->changeInterfaceToEnding();
    }


    if (thomas_the_mover_1->win(*thomas_the_winner_1)) {
        game->changeInterfaceToEnding();
    }
    */
/*
   for (int i = 0; i < this->game->quadtree->search2(thomas_the_player->x, thomas_the_player->y)->getBoxCount(); i++) {
        if (collision2(this->game->quadtree->searchAABB(thomas_the_player->x, thomas_the_player->y)[i])) {
            //thomas_the_player->updateThomasPosition(MOVE_LEFT);
            printf("collision ");
        } else { printf(" pas collision, "); }
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
        this->game->quadtree->insertAllDecor(allDecor1);
    } 

    thomas_the_winner_1->drawPlayer();
    
    thomas_the_mover_1->drawPlayer();
    

    if (game->getLevel() == 2) {
        thomas_the_winner_2->drawPlayer();
        thomas_the_mover_2->drawPlayer();
        this->game->quadtree->insertAllDecor(allDecor2);
    }

    //printf("quadtree %d ", (int)this->game->quadtree->search((Position(thomas_the_player->x, thomas_the_player->y)))->boxes[0]->position.x);
    /*    
    if (!collision()) {
        printf("pas de collision");
    }
    if (collision()) {
        //printf(" collision ");
    }
*/
    //tests
    //printf(" %f ", this->game->quadtree->search(Position(thomas_the_player->x, thomas_the_player->y))->getTopLeft().x);
    //printf( " %f, %f ", thomas_the_player->x, thomas_the_player->y);

    //testQuadTree();

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



//---------------------------------
//tests de collision






bool GamingInterface::collisionTop(AABB* box) {
    if (thomas_the_player->y + thomas_the_player->height > box->y) {
        return false;
    }
    return true;
}
bool GamingInterface::collisionBottom(AABB* box) {
    if (thomas_the_player->y > box->y + box->height) {
        return false;
    }
    return true;
}
bool GamingInterface::collisionRight(AABB* box) {
    
    if (thomas_the_player->x + thomas_the_player->width < box->x && thomas_the_player->y > box->y + box->height) {
        return false; 
    }
    return true;
    /*
   if (thomas_the_player->x + thomas_the_player->width > box->x && thomas_the_player->x + thomas_the_player->width < box->x + box->weight) {
       return true;
   }
   return false;
   */
}
bool GamingInterface::collisionLeft(AABB* box) {
    if (thomas_the_player->x > box->x + box->width) {
        return false; 
    }
    return true;
}

bool GamingInterface::collision2(AABB* box) {
    return !(thomas_the_player->x > box->x + box->width || thomas_the_player->x + thomas_the_player->width < box->x || thomas_the_player->y + thomas_the_player->height > box->y || thomas_the_player->y > box->y + box->height);
}


bool GamingInterface::collision() {
    QuadTree* quadTreeToTest = this->game->quadtree->search(Position(thomas_the_player->x, thomas_the_player->y));
    for (int i = 0; i < quadTreeToTest->getBoxCount(); i++) {
        if (( thomas_the_player->x >= quadTreeToTest->getAABB(i).position.x + quadTreeToTest->getAABB(i).width )      // trop à droite
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


void GamingInterface::collision3(int direction) {
    //printf(" ca rentre en fonction ");
    switch(direction) {
        case MOVE_LEFT :
            for (int i = 0; i < this->game->quadtree->search2(thomas_the_player->x, thomas_the_player->y)->getBoxCount(); i++) {
                printf(" ca rentre en for ");
                if (collision2(this->game->quadtree->searchAABB(thomas_the_player->x, thomas_the_player->y)[i])) {
                    thomas_the_player->updateThomasPosition(MOVE_RIGHT);
                    printf(" retour a gauche ");
                }
            }
            break;
        case MOVE_RIGHT :
            printf(" cas right ");
            printf(" %d ", this->game->quadtree->search2(thomas_the_player->x, thomas_the_player->y)->getBoxCount());
            for (int i = 0; i < this->game->quadtree->search2(thomas_the_player->x, thomas_the_player->y)->getBoxCount(); i++) {
                printf(" ca rentre en for ");
                if (collision2(this->game->quadtree->searchAABB(thomas_the_player->x, thomas_the_player->y)[i])) {
                    thomas_the_player->updateThomasPosition(MOVE_LEFT);
                }
            }
            break;
        case JUMP :
            break;
        default :
            break;
    }
}

void GamingInterface::testQuadTree() {
    QuadTree* nodeToTest = this->game->quadtree->search2(thomas_the_player->x, thomas_the_player->y);

    printf("boxCount = %d ", nodeToTest->getBoxCount());

    for (int i = 0; i < nodeToTest->getBoxCount(); i++) {
        printf(" %d, %d ", (int)nodeToTest->boxes[i]->x, (int)nodeToTest->boxes[i]->y);
    }
}

void GamingInterface::testSansQuadTree() {
    
}