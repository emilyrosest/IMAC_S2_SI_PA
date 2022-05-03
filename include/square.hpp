#pragma once
#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include <random>
//#include <iostream>


typedef struct Color {
    float r;
    float g;
    float b;
} Color;

typedef struct Position {
    float x;
    float y;
} Position;

typedef struct Quad {
    Position position;
    float height;
    float weight;
    Color color;
    int filled;
} Quad;

Color createColor(float r, float g, float b);
Position createPosition(float x, float y);
Quad createQuad(Position p, float h, float w, Color c, int filled);

void drawQuad(Quad quad);



class Square {
public :

    Square() {
        thomas_the_square = setThomas(0.2, 0.1);
    };

    ~Square() {};


    Quad setThomas(float x, float y) {
        Position position = createPosition(x, y);
        float h = 0.2;//rand() % 1 + 0.1;
        float w = 0.4;//rand() % 1 + 0.1;
        Color color = createColor(0.5, 0.3, 0.8);//createColor(rand() % 1 + 0.1, rand() % 1 + 0.1, rand() % 1 + 0.1);
        Quad thomas = createQuad(position, h, w, color, 1);
        return thomas;
    }

    static Quad thomas_the_square;

    //Square updateThomas(float x, float y) { return setThomas(x, y); };

    float getXStartingCoordinate() { return x_starting_pos; };

    float getYstartingCoordinate() { return y_starting_pos; };

    float getXPos() { return x_pos; };

    float getYPos() { return y_pos; };

    float getHeight() { return height; };

    float getWeight() { return weight; }; 

    void updateXPos(float x) { x_pos = x; };

    void updateYPos(float y) { y_pos = y; };


private :

    float height;
    float weight;
    float x_starting_pos;
    float y_starting_pos;
    float x_pos;
    float y_pos;
    float x_ending_pos;
    float y_ending_pos;
    Color color;

    //si on a un niveau avec plusieurs rectangles a deplacer :
    //bool selected;

};


/*
class Square {
    
public :

    Square(float h, float w, float x, float y, Color color) {
        this->height = h;
        this->weight = w;
        this->x_pos = x; //ou starting po
        this->y_pos = y;
        this->color = color;
    };

    ~Square() {};

    void SetCoordinates(int x, int y);

    float getXStartingCoordinate() { return x_starting_pos; };

    float getYstartingCoordinate() { return y_starting_pos; };

    float getXPos() { return x_pos; };

    float getYPos() { return y_pos; };

    float getHeight() { return height; };

    float getWeight() { return weight; }; 

    void drawSquare(int filled);


private :

    float height;
    float weight;
    float x_starting_pos;
    float y_starting_pos;
    float x_pos;
    float y_pos;
    float x_ending_pos;
    float y_ending_pos;
    Color color;

    //si on a un niveau avec plusieurs rectangles a deplacer :
    //bool selected;

}; */