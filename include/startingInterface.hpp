#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdlib.h>
#include <stdio.h>

#include "game.hpp"


class StartingInterface {

public :
    StartingInterface(Game* game) {
        StartingInterface::game = game;

        StartingInterface::StartingBackground = IMG_Load("assets/debut.png"); //pas réussi à changer l'écran d'acceuil, erreur de segmentation
        initBackground();
    }

    ~StartingInterface() {

    }

    void handleEvents();

    void update();

    void render();

    void draw();

    bool isActive() {
        if (game->starting()) {
            return true;
        }
        return false;
    }

    void initBackground();

    void clean();

private :
    Game* game;

    SDL_Surface* StartingBackground;

    GLuint texture;

};