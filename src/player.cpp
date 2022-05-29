#include <GL/gl.h>
#include <GL/glu.h>
#include "../include/player.hpp"



#include <iostream>


//version sans positions (car ca mettait toujours la position a 0, 0)

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

void Player::updateThomasPosition(int direction) {  
    //float d;
    //d = 1; // a changer
    double v_grav, v_jump, v_air;
    v_grav = 0.08;
    v_jump = -4;
 
    v_air = 1.5;

    switch (direction) {
        case MOVE_LEFT :
            //this->x -= d;
            this->x -= v_air;
            break;

        case MOVE_RIGHT :
            //this->x += d;
            this->x += v_air;
            break;

        case JUMP :
            
            printf("floor : %d\n", this->floor);
            jump(this->floor);
            break;

        case DOWN :
            down();
            break;

        default:
            break;
    }
}


void Player::jump(int floor) {
    
    int dy = 0;
    dy += 1;

    if (this->y >= floor + 2){
        dy =  -2;
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
    this->y -= 2;
}

bool Player::win(Player winner) {
    return (this->x == winner.x && this->y == winner.y);
}

  






/*
bool Player::collisionTop(AABB* box) {
    if (thomas_the_player->y + thomas_the_player->height > box->y) {
        return false;
    }
    return true;
}
bool Player::collisionBottom(AABB* box) {
    if (thomas_the_player->y > box->y + box->height) {
        return false;
    }
    return true;
}
bool Player::collisionLeft(AABB* box) {
    if (thomas_the_player->x + thomas_the_player->width < box->x) {
        return false; 
    }
    return true;
}
bool Player::collisionRight(AABB* box) {
    if (thomas_the_player->x > box->x + box->weight) {
        return false; 
    }
    return true;
}

*/



//ici les fonctions avec position

/*

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

*/