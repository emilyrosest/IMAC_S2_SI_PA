#include <GL/gl.h>
#include <GL/glu.h>
#include "../include/player.hpp"



#include <iostream>


Player::Player(float x, float y, float h, float w, Color color, int filled):Square(x, y, h, w, color, filled){};


void Player::drawPlayer(){

    if(this->filled) {
        glBegin(GL_QUADS);
    }
    else {
        glBegin(GL_LINE_LOOP); 
    }

    glColor3f(this->color.r, this->color.g, this->color.b);
    glVertex2f( this->x , this->y);
    glVertex2f( this->x + this->width , this->y);
    glVertex2f( this->x + this->width , this->y + this->height);
    glVertex2f( this->x , this->y + this->height);
    glEnd();
}

void Player::updateThomasPosition(int direction, float d) {      

    switch (direction) {
        case MOVE_LEFT :
            this->x -= d;
            this->floor = this->y;
            break;

        case MOVE_RIGHT :
            this->x += d;
            this->floor = this->y;
            break;

        case JUMP :
            jump(this->floor);
            break;

        case DOWN :
            this->y -= d;
            break;

        case NONE :
            break;

        default:
            break;
    }
}


void Player::jump(int floor) {
    
    int dy = 0;
    dy += 2;
    if (this->y >= floor + 4){
        if(this->isOnTheFloor == 1){
            dy = -4;
        }  
    }
    this->y += dy;
}

void Player::down() {
    this->y -= 1;
}

bool Player::win(Player winner) {
    return (this->x == winner.x && this->y == winner.y);
}

  
