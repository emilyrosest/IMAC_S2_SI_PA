#include "../include/startingInterface.hpp"

#include "../include/square.hpp"
#include "../include/player.hpp"

Square squaretest = Square(0., 0., 10., 10., Color(0.4, 0.5, 0.2), 1);

void StartingInterface::handleEvents() {
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
                
            /* Touche clavier */
            case SDL_KEYDOWN:

                switch (event.key.keysym.sym) { // Quelle touche est appuyée ?
                    case SDLK_SPACE:
                    case SDLK_RETURN:
                        //initialiser les choses
                        printf("ca veut jouer \n");
                        //marche pas
                        //Game::thomas_the_player = new Player(0.0, 0.0, 2., 4., Color());
                        //QuadTree* quadtree = new QuadTree(Position(-20., 20.), Position(20., -20.));
                        clean();
                        game->changeInterfaceToGaming();
                        break;
                    default:
                        break;
                }
                break;
                    
            default:
                break;
        }
    }
}

void StartingInterface::update() {

}

void StartingInterface::initBackground() {
    if (StartingBackground == nullptr) {
        printf("erreur ");
    }
    
    glGenTextures(1, &texture);

    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, StartingBackground->w, StartingBackground->h, 0, GL_RGB, GL_UNSIGNED_BYTE, StartingBackground->pixels);

    glBindTexture(GL_TEXTURE_2D, 0);

}

void StartingInterface::draw() {
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

void StartingInterface::render() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    //squaretest.drawSquare();

    draw();  

    
}

void StartingInterface::clean() {
    SDL_FreeSurface(StartingBackground);
    glDeleteTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, 0);
}