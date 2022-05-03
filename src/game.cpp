#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdio.h>

#include "game.hpp"
#include "square.hpp"
#include "map.hpp"

Map *map = nullptr;

Game::Game() {
    /* Initialisation de la SDL */
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        const char* error = SDL_GetError();
        fprintf(stderr, "Erreur lors de l'intialisation de la SDL : %s\n", error);
        SDL_Quit();
        //return EXIT_FAILURE;
    }
    /* Ouverture d'une fenetre et creation d'un contexte OpenGL */
    
    {
        window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
        if(NULL == window) {
            const char* error = SDL_GetError();
            fprintf(stderr, "Erreur lors de la creation de la fenetre : %s\n", error);
            SDL_Quit();
            //return EXIT_FAILURE;
        }
    }
    
    {
            SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
            SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
            SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
        context = SDL_GL_CreateContext(window);
        if(NULL == context) 
        {
            const char* error = SDL_GetError();
            fprintf(stderr, "Erreur lors de la creation du contexte OpenGL : %s\n", error);
            SDL_DestroyWindow(window);
            SDL_Quit();
            //return EXIT_FAILURE;
        }
    }    
    onWindowResized(WINDOW_WIDTH, WINDOW_HEIGHT);

    //explorationInterface = new ExplorationInterface(this);
    //explorationInterface = new ExplorationInterface();
    //map = explorationInterface->getMap();

    isRunning = 1;
}

void Game::handleEvents() {
    while(SDL_PollEvent(&e)) {
        /* L'utilisateur ferme la fenetre : */
		if(e.type == SDL_QUIT) {
			setRunning(0);
			break;
		}
		
		if(	e.type == SDL_KEYDOWN && (e.key.keysym.sym == SDLK_q || e.key.keysym.sym == SDLK_ESCAPE)) {
			setRunning(0);
			break;
		}
            
        switch(e.type) 
        {
            case SDL_WINDOWEVENT:
                switch (e.window.event) 
                {
                    /* Redimensionnement fenetre */
                    case SDL_WINDOWEVENT_RESIZED:
                        onWindowResized(e.window.data1, e.window.data2);                
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
                //printf("touche pressee (code = %d)\n", e.key.keysym.sym);
                //map->handleEvents();
                switch (e.key.keysym.sym) { // Quelle touche est appuyée ?
                    case SDLK_q:
                    case SDLK_LEFT:
                        map->updateThomasPosition(MOVE_LEFT);
                        //printf("bouger");
                        printf("pret a bouger lol \n");
                        break;
                    case SDLK_d:
                    case SDLK_RIGHT:
                        map->updateThomasPosition(MOVE_RIGHT);
                        break;
                    case SDLK_SPACE:
                    case SDLK_z:
                    case SDLK_UP:
                        map->updateThomasPosition(JUMP);
                    //case SDLK_m:
                        //map->toggleCamera();
                        //break;
                    default:
                        break;
                }
                break;
                    
            default:
                break;
        }
    }
}

void Game::refresh() {
    //map->handleEvents();
    map->drawMap();
}

void Game::clean() {
    /* Liberation des ressources associees a la SDL */ 
    SDL_GL_DeleteContext(context);
    SDL_DestroyWindow(window);
    SDL_Quit();
    
    //return EXIT_SUCCESS;
}

void Game::onWindowResized(unsigned int width, unsigned int height) {
    static float aspectRatio;
    aspectRatio = width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if( aspectRatio > 1) 
    {
        gluOrtho2D(
        -GL_VIEW_SIZE / 2. * aspectRatio, GL_VIEW_SIZE / 2. * aspectRatio, 
        -GL_VIEW_SIZE / 2., GL_VIEW_SIZE / 2.);
    }
    else
    {
        gluOrtho2D(
        -GL_VIEW_SIZE / 2., GL_VIEW_SIZE / 2.,
        -GL_VIEW_SIZE / 2. / aspectRatio, GL_VIEW_SIZE / 2. / aspectRatio);
    }
}