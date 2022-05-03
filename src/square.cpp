#include <SDL2/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "../include/square.hpp"

Quad Square::thomas_the_square;


Color createColor(float r, float g, float b) {
    Color newColor;
    newColor.r = r;
    newColor.g = g;
    newColor.b = b;
    return newColor;
}

Position createPosition(float x, float y) {
    Position newPosition;
    newPosition.x = x;
    newPosition.y = y;
    return newPosition;
}

Quad createQuad(Position p, float h, float w, Color c, int filled) {
    Quad newSquare;
    newSquare.position = p;
    newSquare.height = h;
    newSquare.weight = w;
    newSquare.color = c;
    newSquare.filled = filled;
    return newSquare;
}

void drawQuad(Quad quad) {
    float x = quad.position.x;
    float y = quad.position.y;
    float h = quad.height;
    float w = quad.weight;

    float r = quad.color.r;
    float g = quad.color.g;
    float b = quad.color.b;
    
    if(quad.filled) {
        glBegin(GL_QUADS);
    }
    else {
        glBegin(GL_LINE_LOOP); 
    }

    glColor3f(r, g, b);
    glVertex2f( x , y);
    glVertex2f( x + w , y);
    glVertex2f( x + w , y + h);
    glVertex2f( x , y + h);
    glEnd();
}





/*
void Square::drawSquare(int filled) {

    float x = getXStartingCoordinate();
    float y = getYstartingCoordinate();
    float h = getHeight();
    float w = getWeight();

    float r = this->color.r;
    float g = this->color.g;
    float b = this->color.b;

    if(filled) {
        glBegin(GL_QUADS);
    }
    else {
        glBegin(GL_LINE_LOOP); 
    }

    glColor3f(r, g, b);
    glVertex2f( x , y);
    glVertex2f( x + w , y);
    glVertex2f( x + w , y + h);
    glVertex2f( x , y + h);
    glEnd();
}
*/

