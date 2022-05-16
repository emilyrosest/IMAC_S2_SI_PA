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

        thomas_the_player = new Player(0., 0., 2., 4., Color(0.3, 0.4, 0.5), 1);
        thomas_the_winner = new Player(5., 0., thomas_the_player->height, thomas_the_player->width, Color(1., 0., 0.), 0);
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

    Player *thomas_the_player;

    Player *thomas_the_winner;

private :
    Game* game;

    Map* map;
};