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
                        thomas_the_player->updateThomasPosition(MOVE_LEFT);
                        printf("pret a bouger lol \n");
                        //printf("%f\n", this->thomas_the_player->position.x);
                        break;

                    case SDLK_d:
                    case SDLK_RIGHT:
                        thomas_the_player->updateThomasPosition(MOVE_RIGHT);
                        printf("pret a bouger lol \n");
                        //printf("%f\n", this->thomas_the_player->position.x);
                        break;
                    case SDLK_SPACE:
                    case SDLK_z:
                    case SDLK_UP:
                        thomas_the_player->updateThomasPosition(JUMP);
                        printf("pret a sauter\n");
                        break;
                    case SDLK_RETURN:
                        //a enlever !!!!!
                        printf("ca veut ending \n");
                        game->changeInterfaceToEnding();
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
    if (thomas_the_player->win(*thomas_the_winner)) {
        game->changeInterfaceToEnding();
    }
}

void GamingInterface::render() {


//Essayer de le mettre dans une fonction à part
     /*
    AABB allDecor[MAX_DECOR_COUNT] = {
    createAABB(Position(-4., 5.), 1., 2.), 
    createAABB(Position(4., 7.), 3., 1.),
    createAABB(Position(-6., -3.), 2., 3.),
    createAABB(Position(-1., -7.), 4., 1.),
    createAABB(Position(8., 2.), 1., 2.),
    createAABB(Position(-8., 6.), 3., 3.),
    createAABB(Position(-8., -2.), 3., 2.),
    createAABB(Position(-6., 7.), 2., 2.),
    createAABB(Position(-7., 2.), 3., 1.),
    createAABB(Position(8., -2.), 1., 2.),
    createAABB(Position(-11., 9.), 3., 2.),
    createAABB(Position(-13., 13.), 2., 1.),
    createAABB(Position(-9., 9.), 2., 2.),
    createAABB(Position(-10., 10.), 1., 1.),
    createAABB(Position(-3., 4.), 2., 2.),
    createAABB(Position(-5., -6.), 1., 1.),
    createAABB(Position(-7., -5.), 2., 2.),
    createAABB(Position(-4., -9.), 1., 1.),
    createAABB(Position(-2., -4.), 1., 1.),
    createAABB(Position(-2., -6.), 1., 1.),
    createAABB(Position(-4., -7.), 1., 1.),
    createAABB(Position(-4., -8.), 1., 1.),
    createAABB(Position(-4., -10.), 1., 1.) 
    };
    */


    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    //glPushMatrix();

    glScalef(0.1, 0.1, 0.);

       

    //this->game->map->initDecor(&X[MAX_DECOR_COUNT], &Y[MAX_DECOR_COUNT], &H[MAX_DECOR_COUNT], &W[MAX_DECOR_COUNT]);
    
    
    //for (int j = 0; j < 23; j++){
      //  cout << X[j] << endl;
    //}
    

    /*for (int i = 0; i < MAX_DECOR_COUNT; i++){
        allDecor[i] = createAABB(Position(X[i], Y[i]), H[i], W[i]);
        //cout << X[i] << endl;
    }*/
    
   

    this->game->quadtree->insertAllDecor(allDecor);

    thomas_the_winner->drawPlayer();

    thomas_the_player->drawPlayer();

    //glPopMatrix();
}