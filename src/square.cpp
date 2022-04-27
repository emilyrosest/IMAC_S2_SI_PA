#include <SDL2/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "../include/square.h"


void Square::drawSquare(int filled) {

    float x = getXStartingCoordinate();
    float y = getYstartingCoordinate();
    float h = getHeight();
    float w = getWeight();

    if(filled) 
    {
        glBegin(GL_QUADS);
            glColor3f(r, g, b);
            glVertex2f( x , y);
            glVertex2f( x + w , y);
            glVertex2f( x + w , y + h);
            glVertex2f( x , y + h);
            glVertex2f( x , y);
        
        glEnd();
    }
    else 
    {
        glBegin(GL_LINE_LOOP);
            glColor3f(r, g, b);
            glVertex2f( x , y);
            glVertex2f( x + w , y);
            glVertex2f( x + w , y + h);
            glVertex2f( x , y + h);
            glVertex2f( x , y);
        
        glEnd();
    }


}