#pragma once
#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include <random>

#include "colors.hpp"
#include "position.hpp"


class Square {
public :

    //Square() {};

    Position position;
    Color color;

    float height;
    float width; 
    int filled;

    //Square(Position p, float h, float w, Color c, int filled): position (p), height(h), width(w), color(c), filled(filled){};

    Square(float x, float y, float h, float w, Color c, int filled): position(x, y), height(h), width(w), color(c), filled(filled){};

    void drawSquare();


private :

    //si on a un niveau avec plusieurs rectangles a deplacer :
    //bool selected;

};