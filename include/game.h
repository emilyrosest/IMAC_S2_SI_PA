#pragma once

#include <iostream>

#include <SDL2/SDL.h>

class Game{

public :

class Game {
public:

    Game(const std::string title);

    ~Game();

    void init(const std::string title);

    
    void clean();

    void onWindowResized(void onWindowResized(unsigned int width, unsigned int height));

    //void refresh();

    void setRunning(bool newState) { isRunning = newState; }

    bool running() { return isRunning; };

    void setActivity(std::string newActivity) { activity = newActivity; };

    int gameLoop();


    /*bool exploring() {
        if (activity == "inExploration") {
            return true;
        }
        return false;
    };*/


    static SDL_Rendererrenderer;


   /* Dimensions initiales et titre de la fenetre */
    static const unsigned int WINDOW_WIDTH = 800;
    static const unsigned int WINDOW_HEIGHT = 600;


    /* Espace fenetre virtuelle */
    static const float GL_VIEW_SIZE = 150.;

    /* Nombre minimal de millisecondes separant le rendu de deux images */
    static const Uint32 FRAMERATE_MILLISECONDS = 1000 / 60;


    //static constexpr float SCALE_CAMERA = WINDOW_WIDTH / (float) 800;

    SDL_Event event;

private:
    bool isRunning = false;

    //std::string activity = "inStarter";

    SDL_Window *window;

};
