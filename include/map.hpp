#pragma once
#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdio.h>

#include "main.hpp"
#include "square.hpp"
#include "game.hpp"

const int MOVE_LEFT = 1;
const int MOVE_RIGHT = 2;
const int JUMP = 3;

//float X_STARTING_POS = 0.2; // a changer
//float Y_STARTING_POS = 0.;


class Map {
public :
    Map();

    ~Map() {};

    static const int MAP_WIDTH = 1000;

    static const int MAP_HEIGHT = 1000;

    void drawMap();

    void loadPlayer();

    void handleEvents();

    void updateThomasPosition(int direction);

    void jump();


private :
    Square* thomas;
};