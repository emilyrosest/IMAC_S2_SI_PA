#pragma once
#include <iostream>
#include <random>
#include <ctime>

class Color {
public:

    Color();

    Color(float r, float g, float b);

    Color initRandomColor(Color colorbox);
    
    //void chooseRandomColor(Color color);

    float r;
    float g;
    float b;

private:

};



   
