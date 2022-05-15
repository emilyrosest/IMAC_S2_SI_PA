#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdlib.h>
#include <stdio.h>

#include "game.hpp"
#include "main.hpp"

class GamingInterface {

public :
    GamingInterface(Game* game) {
        GamingInterface::game = game;
        GamingInterface::map = new Map();
    }

    ~GamingInterface() {}

    void handleEvents();

    void update();

    void render();

    bool isActive() {
        if (game->gaming()) {
            return true;
        }
        return false;
    }

private :
    Game* game;

    Map* map;
};