#include <SDL2/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "../include/map.hpp"
#include "../include/game.hpp"
#include "../include/square.hpp"

Square* thomas = nullptr;


//float X = X_STARTING_POS;
//float Y = Y_STARTING_POS;
float X=0.2;
float Y=0.;

//float H = 0.5;
//float W = 0.2;

//Color color = createColor(0.6, 0.5, 0.1);

Map::Map() {

}

void Map::drawMap() {
    //changer le background de la fenetre
    //eventuellement plus tard mettre une texture en background

    //mettre en place le niveau, avec des drawSquare pour dessiner les plateformes/carres
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    
    //Quad newThomas = createQuad(createPosition(X, Y), H, W, color, 1);
    //Quad newThomas = thomas->setThomas(X, Y);
    //drawQuad(newThomas);

    Square::thomas_the_square = thomas->setThomas(X, Y);
    drawQuad(Square::thomas_the_square);
    
}




void Map::updateThomasPosition(int direction) {  
    float d;
    d = 0.08; // a changer
    switch (direction) {
        case MOVE_LEFT :
            X -= d;
            break;
        case MOVE_RIGHT :
            X += d;
            break;
        case JUMP :
            printf("pret a sauter \n");
            jump();
        default:
            break;
    }
}

void Map::jump() {
    //for (int i = 0; i < 2; i++) {
      //  Y += float(i)/1000. * SDL_GetTicks();
    //}
    //for (int i = 0; i < 2; i++) {
        //Y -= float(i)/100. * SDL_GetTicks();
    //}
    Y += 0.1;
    //pas fini
}
