#pragma once
#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include <GL/gl.h>
#include <GL/glu.h>

//#include "square.hpp"
#include "player.hpp"

static const char WINDOW_TITLE[] = "Square Dash";

/* Espace fenetre virtuelle */
static const float GL_VIEW_SIZE = 2.;

class Game {
public :

    Game();

    //~Game(){};

    void setRunning(int newState) { isRunning = newState; }

    int running() { return isRunning; };

    void clean();

    void refresh();

    void swap() { SDL_GL_SwapWindow(window); };

    void handleEvents();

    void onWindowResized(unsigned int width, unsigned int height);

    /* Dimensions initiales et titre de la fenetre */
    static const unsigned int WINDOW_WIDTH = 800;
    static const unsigned int WINDOW_HEIGHT = 600;
    
    //Renderer

    SDL_Event e;

    static SDL_Renderer *renderer;

    Player *thomas_the_player;

private :

    int isRunning = 0;

    SDL_Window* window;

    SDL_GLContext context;
};
