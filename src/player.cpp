#include <GL/gl.h>
#include <GL/glu.h>
#include "../include/player.hpp"

#include <iostream>
//Player::Player(){};

//Player::Player(float x, float y, float h, float w, Color color):Square(position, 0.2, 0.4, Color(), 1), position({x,y}){};

Player::Player(float x, float y, float h, float w, Color color):Square(0.0, 0.0, 0.2, 0.4, Color(), 1){};


void Player::drawPlayer(){

    if(this->filled) {
        glBegin(GL_QUADS);
    }
    else {
        glBegin(GL_LINE_LOOP); 
    }

    //printf("%f\n", this->position.x);

    glColor3f(this->color.r, this->color.g, this->color.b);
    glVertex2f( this->position.x , this->position.y);
    glVertex2f( this->position.x + this->width , this->position.y);
    glVertex2f( this->position.x + this->width , this->position.y + this->height);
    glVertex2f( this->position.x , this->position.y + this->height);
    glEnd();
}

void Player::updateThomasPosition(int direction) {  
    float d;
    d = 0.1; // a changer
    switch (direction) {
        case MOVE_LEFT :
            this->position.x -= d;
            break;
        case MOVE_RIGHT :
            this->position.x += d;
            break;
        case JUMP :
            printf("pret a sauter \n");
            jump();
        default:
            break;
    }
}


void Player::jump() {
    //for (int i = 0; i < 2; i++) {
      //  Y += float(i)/1000. * SDL_GetTicks();
    //}
    //for (int i = 0; i < 2; i++) {
        //Y -= float(i)/100. * SDL_GetTicks();
    //}
    this->position.y += 0.1;
    //pas fini
}