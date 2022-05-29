#include "../include/colors.hpp"
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>


Color::Color():r(0.5), g(0.3), b(0.8){}; //couleur par défaut est violet


Color::Color(float r, float g, float b) {
    this->r = r;
    this->g = g;
    this->b = b;
}


Color Color::initRandomColor(Color colorbox){
        //constexpr int MIN = 1;
    constexpr int MAX = 8;

    std::srand(std::time(nullptr));
    int random_color_index = rand() % MAX;

    if(random_color_index == 1){
        //rose
        //glColor3f(1, 0.5, 0.7);
        colorbox.r = 1.;
        colorbox.g = 0.5;
        colorbox.b = 0.7;
    }
    else if(random_color_index == 2){
        //rouge
        //glColor3f(1, 0, 0);
        colorbox.r = 1.;
        colorbox.g = 0.;
        colorbox.b = 0.;
    }
    else if(random_color_index == 3){
        //bleu
        //glColor3f(0.2, 0.5, 0.8);
        colorbox.r = 0.2;
        colorbox.g = 0.5;
        colorbox.b = 0.8;

    }
    else if(random_color_index == 4){
        //vert
        //glColor3f(0.2, 0.6, 0.2);
        colorbox.r = 0.2;
        colorbox.g = 0.6;
        colorbox.b = 0.2; 
        
    }
    else if(random_color_index == 5){
        //jaune
        //glColor3f(1., 1., 0.);
        colorbox.r = 1.;
        colorbox.g = 1.;
        colorbox.b = 0.; 
    }
    else if(random_color_index == 6){
        //orange
        //glColor3f(1., 0.5, 0.);
        colorbox.r = 1.;
        colorbox.g = 0.5;
        colorbox.b = 0.; 
        
    }
    else if(random_color_index == 7){
        //violet
        //glColor3f(0.4, 0., 0.6);
        colorbox.r = 0.4;
        colorbox.g = 0.;
        colorbox.b = 0.6; 
    }
    else{
        // blanc
        //glColor3f(1., 1., 1.);
        colorbox.r = 1.;
        colorbox.g = 1.;
        colorbox.b = 1.;
    }
    return colorbox;

}
    
