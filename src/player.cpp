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
    //float d = 1.5;
    //d = 1;

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
            //printf("floor : %d\n", this->floor);
            jump(this->floor);
            //jump();
            //this->y += d;
            break;

        case DOWN :
            //down();
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

    printf("%d\n", dy);

    /*
    for (int i = 0; i < 2; i++) {
        this->y += float(i)/1000. * SDL_GetTicks();
    }
    
    for (int i = 0; i < 2; i++) {
        this->y -= float(i)/1200. * SDL_GetTicks();
    }
    //this->y += 2;
    */
    


    /*
    double v_y, v_grav;

    v_grav = 0.08;
    v_y = -4;

    
    int done;
    for (done = 0; !done; SDL_Delay(10)) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
            case SDL_QUIT:
                done = 1;
                break;
            
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym) {
                case SDLK_ESCAPE: 
                    done = 1; 
                    break;
            //direction en vol
                case SDLK_LEFT: 
                    this->x = -1.5; 
                    break;
                case SDLK_RIGHT: 
                    this->x = 1.5; 
                    break;
                }
                break;
            }  
        }                 
            

  
        // evolution de la position 
        //this->x += 1.5;
        this->y += v_y;
 
        //evolution de la vitesse 
        v_y += v_grav;

        
    //}
*/
}

void Player::down() {
    this->y -= 1;
}

bool Player::win(Player winner) {
    return (this->x == winner.x && this->y == winner.y);
}

  
