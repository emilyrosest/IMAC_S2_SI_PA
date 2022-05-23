#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

#include "game.hpp"
#include "main.hpp"




class GamingInterface {

public :
    GamingInterface(Game* game) {
        GamingInterface::game = game;
        GamingInterface::map = new Map();
        game->map->initDecor(X, Y, H, W);
        for (int i = 0; i < MAX_DECOR_COUNT; i++){
            allDecor[i] = createAABB(Position(X[i], Y[i]), H[i], W[i]);

        }

        thomas_the_player = new Player(0., 0., 2., 4., Color(0.3, 0.4, 0.5), 1);
        thomas_the_winner = new Player(-20., 24., thomas_the_player->height, thomas_the_player->width, Color(1., 0., 0.), 0);
    }

    ~GamingInterface() {}

    void handleEvents();

    void update();

    void render();

    float X[MAX_DECOR_COUNT];
    float Y[MAX_DECOR_COUNT];
    float H[MAX_DECOR_COUNT];
    float W[MAX_DECOR_COUNT];

    bool isActive() {
        if (game->gaming()) {
            return true;
        }
        return false;
    }

    Player *thomas_the_player;

    Player *thomas_the_winner;

    Game* game;

private :
    AABB allDecor[MAX_DECOR_COUNT];

    Map* map;
};