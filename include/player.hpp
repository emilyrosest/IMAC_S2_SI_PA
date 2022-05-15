#pragma once

#include "square.hpp"

const int MOVE_LEFT = 1;
const int MOVE_RIGHT = 2;
const int JUMP = 3;



class Player:public Square{ 
public:

    //using Square::Square;

    //Player(){};

    
    Player(float x, float y, float h, float w, Color color);

    void drawPlayer();

    void updateThomasPosition(int direction);

    void jump();

    


    Position position;

private:

};