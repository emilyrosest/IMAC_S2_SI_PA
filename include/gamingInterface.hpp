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

        game->map->initLevel1(X1, Y1, H1, W1);
        for (int i = 0; i < MAX_DECOR_COUNT; i++){
            allDecor1[i] = createAABB(X1[i], Y1[i], H1[i], W1[i], colorbox);
        }

        this->game->quadtree_1->insertAllDecor(allDecor1); 

        thomas_the_mover_1 = new Player(0., 0., 2., 4., Color(0.3, 0.4, 0.5), 1);

        thomas_the_winner_1 = new Player(-20., 24., thomas_the_mover_1->height, thomas_the_mover_1->width, Color(1., 1., 1.), 0);

        thomas_the_mover_2 = new Player(-8., 0., 3., 6., Color(0.7, 0.1, 0.5), 1);

        thomas_the_winner_2 = new Player(-17., 17., thomas_the_mover_2->height, thomas_the_mover_2->width, Color(1., 1., 1.), 0);

        thomas_the_mover_3 = new Player(0., 0., 2., 4., Color(0.3, 0.4, 0.5), 1);

        thomas_the_winner_3 = new Player(-25., 17., thomas_the_mover_3->height, thomas_the_mover_3->width, Color(1., 1., 1.), 0);

        thomas_the_player = thomas_the_mover_1;

    }

    ~GamingInterface() {}

    void prepare();

    void handleEvents();

    void update();

    void render();

    void camera(float x, float y);

    void changePlayer();

    void move(int direction);



    float X1[MAX_DECOR_COUNT];
    float Y1[MAX_DECOR_COUNT];
    float H1[MAX_DECOR_COUNT];
    float W1[MAX_DECOR_COUNT];

    Color colorbox;

    float X2[MAX_DECOR_COUNT_2];
    float Y2[MAX_DECOR_COUNT_2];
    float H2[MAX_DECOR_COUNT_2];
    float W2[MAX_DECOR_COUNT_2];

    bool isActive() {
        if (game->gaming()) {
            return true;
        }
        return false;
    }
  

    Player *thomas_the_mover_1;
    
    Player *thomas_the_winner_1;

    Player* thomas_the_mover_2;

    Player* thomas_the_winner_2;

    Player* thomas_the_mover_3;

    Player* thomas_the_winner_3;

    Player* thomas_the_player;

    Game* game;


private :

    AABB allDecor1[MAX_DECOR_COUNT];

    AABB allDecor2[MAX_DECOR_COUNT_2];

    Map* map;
};