#pragma once

#include <iostream>


class Square {
    
    public :
        Square(int id,
        float h,
        float w,
        float x,
        float y,
        float r,
        float g,
        float b) {

            Square newSquare;

            newSquare.height = h;
            newSquare.weight = w;
            newSquare.x_starting_pos = x;
            newSquare.y_starting_pos = y;
            newSquare.r = r;
            newSquare.g = g;
            newSquare.b = b;

            return newSquare;
        };

        ~Square() {};

        void SetCoordinates(int x, int y);

        int getId() { return id; };

        float getXStartingCoordinate() { return x_starting_pos; };

        float getYstartingCoordinate() { return y_starting_pos; };

        float getHeight() { return height; };

        float getWeight() { return weight; }; 

        void drawSquare(int filled);


    private :
        int id;

        float height;
        float weight;
        float x_starting_pos;
        float y_starting_pos;
        float x_ending_pos;
        float y_ending_pos;
        float r;
        float g;
        float b;

        bool selected;

};