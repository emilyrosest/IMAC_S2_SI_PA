#include <GL/gl.h>
#include <GL/glu.h>

#include "../include/map.hpp"


Map::Map() {
}







////////////////////////////////////AFFICHAGE TEXTURE ET FOND////////////////////////////////////////////////
/*
void Map::InitMap(){

    background = IMG_Load("assets/background.png");

    if (background == NULL){
        printf("erreur");
    }
    
    glGenTextures(1, &texture);

    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, background->w, background->h, 0, GL_RGBA, GL_UNSIGNED_BYTE, background->pixels);

    glBindTexture(GL_TEXTURE_2D, 0);

}
void Map::drawMap() {

    //changer le background de la fenetre

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture);

    glBegin(GL_QUADS);
            
        glTexCoord2f(0., 1.);
        glVertex2f(-50., 50.);

        glTexCoord2f(1., 1.);
        glVertex2f(50., 50.);

        glTexCoord2f(1., 0.);
        glVertex2f(50., -50.);

        glTexCoord2f(0., 0.);
        glVertex2f(-50., -50.);
    glEnd();


    glDisable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);
    
    //eventuellement plus tard mettre une texture en background


    //mettre en place le niveau, avec des drawSquare pour dessiner les plateformes/carres
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    
}
*/




