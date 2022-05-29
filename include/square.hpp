#pragma once
#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include <random>

#include "colors.hpp"
#include "position.hpp"


class Square {
public :


    Position position;
    
    Color color;

    float height;
    float width; 
    int filled;

    float x;
    float y;

    Square(float x, float y, float h, float w, Color c, int filled): x(x), y(y), height(h), width(w), color(c), filled(filled){};

    void drawSquare();


private :


};