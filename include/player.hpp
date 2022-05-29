#pragma once

#include "square.hpp"

const int MOVE_LEFT = 1;
const int MOVE_RIGHT = 2;
const int JUMP = 3;
const int DOWN = 4;
const int NONE = 0;

const int MOVE = 10;
const int RETURN = 20;



class Player:public Square{ 
public:

    //using Square::Square;

    //Player(){};

    //Player(float x, float y, float h, float w, Color color);
    Player(float x, float y, float h, float w, Color color, int filled);

    int floor = 0;
    int isOnTheFloor;

    void drawPlayer();

    void updateThomasPosition(int direction, float d);

    void jump(int floor);

    void down();

    bool win(Player winner);


    Position position;

private:

};