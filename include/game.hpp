#pragma once
#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include <GL/gl.h>
#include <GL/glu.h>

//#include "square.hpp"
#include "player.hpp"
#include "quadtree.hpp"
#include "map.hpp"

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

    //void handleEvents();

    void onWindowResized(unsigned int width, unsigned int height);

    /* Dimensions initiales et titre de la fenetre */
    static const unsigned int WINDOW_WIDTH = 800;
    static const unsigned int WINDOW_HEIGHT = 600;
    
    //Renderer

    SDL_Event e;

    static SDL_Renderer *renderer;

    Player *thomas_the_player;

    QuadTree *quadtree_1;
    QuadTree *quadtree_2;

    Map *map;

    bool starting() {
        if (activity == 0) {
            return true;
        }
        return false;
    }

    bool gaming() {
        if (activity == 1) {
            return true;
        }
        return false;
    }

    bool ending() {
        if (activity == 10) {
            return true;
        }
        return false;
    }

    void setActivity (int newActivity) { activity = newActivity; };

    void changeInterfaceToGaming() { setActivity(1); };

    void levelUp() { level = 2; };

    int getLevel() { return level; };

    void changeInterfaceToEnding() { setActivity(10); };


private :

    int isRunning = 0;

    SDL_Window* window;

    SDL_GLContext context;

    int activity = 0;

    int level = 1;
};

//Starting = 0
//Gaming = 1 (level 1), 2 (level 2)
//Ending = 10