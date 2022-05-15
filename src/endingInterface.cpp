#include "../include/endingInterface.hpp"

#include "../include/square.hpp"
#include "../include/player.hpp"



void EndingInterface::handleEvents() {
    SDL_Event event = game->e;
    while(SDL_PollEvent(&event)) {
        /* L'utilisateur ferme la fenetre : */
		if(event.type == SDL_QUIT) {
			game->setRunning(0);
			break;
		}
		
		if(	event.type == SDL_KEYDOWN && (event.key.keysym.sym == SDLK_ESCAPE)) {
			game->setRunning(0);
			break;
		}
            
        switch(event.type) 
        {
            case SDL_WINDOWEVENT:
                switch (event.window.event) 
                {
                    /* Redimensionnement fenetre */
                    case SDL_WINDOWEVENT_RESIZED:
                        game->onWindowResized(event.window.data1, event.window.data2);                
                        break;

                    default:
                        break; 
                }
                break;

            /* Clic souris */
            case SDL_MOUSEBUTTONUP:
                printf("clic en (%d, %d)\n", event.button.x, event.button.y);
                break;
                    
            default:
                break;
        }
    }
}

void EndingInterface::update() {

}

void EndingInterface::initBackground() {
    if (EndingBackground == nullptr) {
        printf("erreur ");
    }
    
    glGenTextures(1, &texture);

    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, EndingBackground->w, EndingBackground->h, 0, GL_RGB, GL_UNSIGNED_BYTE, EndingBackground->pixels);

    glBindTexture(GL_TEXTURE_2D, 0);

}

void EndingInterface::draw() {
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture);

    glBegin(GL_QUADS);
            
        glTexCoord2f(0., 1.);
        glVertex2f(-1.2, -1.2);

        glTexCoord2f(1., 1.);
        glVertex2f(1.2, -1.2);

        glTexCoord2f(1., 0.);
        glVertex2f(1.2, 1.2);

        glTexCoord2f(0., 0.);
        glVertex2f(-1.2, 1.2);
    glEnd();


    glDisable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);
}

void EndingInterface::render() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();


    draw();  
    
}

void EndingInterface::clean() {
    SDL_FreeSurface(EndingBackground);
    glDeleteTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, 0);
}