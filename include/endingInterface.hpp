#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdlib.h>
#include <stdio.h>

#include "game.hpp"


class EndingInterface {

public :
    EndingInterface(Game* game) {
        EndingInterface::game = game;

        EndingInterface::EndingBackground = IMG_Load("assets/elmer2.png");
        initBackground();
    }

    ~EndingInterface() {

    }

    void handleEvents();

    void update();

    void render();

    void draw();

    bool isActive() {
        if (game->ending()) {
            return true;
        }
        return false;
    }

    void initBackground();

    void clean();

private :
    Game* game;

    SDL_Surface* EndingBackground;

    GLuint texture;

};