#include <SDL2/SDL.h>

#include "../include/square.h"



void Square::drawSquare() {
    if(filled) 
    {
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(0.0, 0.0);
    }
    else 
    {
        glBegin(GL_LINE_STRIP);
    }

    float x = getXStartingCoordinate();
    float y = getYstartingCoordinate();
    float h = getHeight();
    float w = getWeight();

    glVertex2f( x , y);
    glVertex2f( x + w , y);
    glVertex2f( x + w , y + h);
    glVertex2f( x , y + h);
    glVertex2f( x , y);

    glEnd();
}