#include <GL/gl.h>
#include <GL/glu.h>
#include "../include/square.hpp"



void Square::drawSquare() {

    if(this->filled) {
        glBegin(GL_QUADS);
    }
    else {
        glBegin(GL_LINE_LOOP); 
    }

    printf("%f\n", this->position.x);

    glColor3f(this->color.r, this->color.g, this->color.b);
    glVertex2f( this->position.x , this->position.y);
    glVertex2f( this->position.x + this->width , this->position.y);
    glVertex2f( this->position.x + this->width , this->position.y + this->height);
    glVertex2f( this->position.x , this->position.y + this->height);
    glEnd();
}
