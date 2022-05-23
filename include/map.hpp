#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdlib.h>
#include <stdio.h>


#include "square.hpp"
//#include "quadtree.hpp"


#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>


using namespace std;



class Map {
public :
    Map();

    //~Map() {};

    static const int MAP_WIDTH = 1000;

    static const int MAP_HEIGHT = 1000;
    

    void initDecor(float X[], float Y[], float H[], float W[]);

    void InitMap();

    void drawMap();

    //QuadTree *quadtree;

    //void cleanMap();

    //void handleEvents(); /à voir si besoin ici*/

private :
    
    SDL_Surface *background;

    GLuint texture;

};