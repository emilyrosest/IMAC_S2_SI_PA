#include "game.hpp"
//#include "map.hpp"

//#include "quadtree.hpp"

#include "startingInterface.hpp"
#include "gamingInterface.hpp"
#include "endingInterface.hpp"


#include <iostream>


SDL_Renderer *Game::renderer = nullptr;
//....
Map *map = nullptr;

StartingInterface* startingInterface = nullptr;
GamingInterface* gamingInterface = nullptr;
EndingInterface* endingInterface = nullptr;




Game::Game() {

    glScalef(0.1, 0.1, 0.);
   
    this->quadtree = new QuadTree(Position(-20., 20.), Position(20., -20.)); //faire un constructeur qui prend en pram ces valeurs
    


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
    
    SDL_GLContext context;
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

    startingInterface = new StartingInterface(this);
    gamingInterface = new GamingInterface(this);
    endingInterface = new EndingInterface(this);

    onWindowResized(WINDOW_WIDTH, WINDOW_HEIGHT);
    
    //Agrandir les mesures de la fenêtre
    //glScale(0.1, 0.1, 0.)

    isRunning = 1;
}



void Game::refresh() {
    //on va pouvoir suppr
    /*
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    this->thomas_the_player->drawPlayer();
    
    
    //SDL_GL_SwapWindow(window);
    map->drawMap(); */

    if (startingInterface->isActive()) {
        startingInterface->handleEvents();
        
        //startingInterface->update();
        startingInterface->render();
    }
    if (gamingInterface->isActive()) {
        
        gamingInterface->handleEvents();
        gamingInterface->update();
        gamingInterface->render();
    }
    if (endingInterface->isActive()) {
        endingInterface->handleEvents();
        endingInterface->update();
        endingInterface->render();
    }


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

