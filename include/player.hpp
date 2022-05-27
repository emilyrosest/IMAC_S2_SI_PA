#pragma once

#include "square.hpp"

const int MOVE_LEFT = 1;
const int MOVE_RIGHT = 2;
const int JUMP = 3;
const int DOWN = 4;



class Player:public Square{ 
public:

    //using Square::Square;

    //Player(){};

    //Player(float x, float y, float h, float w, Color color);
    Player(float x, float y, float h, float w, Color color, int filled);

    void drawPlayer();

    void updateThomasPosition(int direction);

    void jump();

    void down();

    bool win(Player winner);


    Position position;

private:

};