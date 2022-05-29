#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>

#include "square.hpp"

using namespace std;


class Map {
public :
    Map();

    static const int MAP_WIDTH = 1000;

    static const int MAP_HEIGHT = 1000;
    
    void initLevel1(float X1[], float Y1[], float H1[], float W1[]);

    void initLevel2(float X2[], float Y2[], float H2[], float W2[]);

    void InitMap();


private :
    
    SDL_Surface *background;

    GLuint texture;

};