#include <GL/gl.h>
#include <GL/glu.h>
#include "../include/square.hpp"

//version sans position
void Square::drawSquare() {

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

//version avec position
/*
void Square::drawSquare() {

    if(this->filled) {
        glBegin(GL_QUADS);
    }
    else {
        glBegin(GL_LINE_LOOP); 
    }

    glColor3f(this->color.r, this->color.g, this->color.b);
    glVertex2f( this->position.x , this->position.y);
    glVertex2f( this->position.x + this->width , this->position.y);
    glVertex2f( this->position.x + this->width , this->position.y + this->height);
    glVertex2f( this->position.x , this->position.y + this->height);
    glEnd();
}
*/