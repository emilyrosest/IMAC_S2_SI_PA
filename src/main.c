#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdio.h>

//include les nouveaux fichiers!!
#include "game.h"
#include "square.h"

Square* newSquare = nullptr;

static const unsigned int WINDOW_WIDTH = 800;
static const unsigned int WINDOW_HEIGHT = 800;


int main(int argc, char** argv)
{
    // Initialisation de la SDL
    if(-1 == SDL_Init(SDL_INIT_VIDEO)) {
        fprintf(stderr, "Impossible d'initialiser la SDL. Fin du programme.\n");
        return EXIT_FAILURE;
    }

    // Creation de la fenetre SDL
    SDL_Window* window = SDL_CreateWindow("Square Dash", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    if(window == NULL) {
        fprintf(stderr, "Impossible de créer la fenêtre. Fin du programme.\n");
        return EXIT_FAILURE;
    }

    SDL_Surface* surface = SDL_GetWindowSurface(window);
    if(surface == NULL) {
        fprintf(stderr, "Impossible d'ouvrir la fenetre. Fin du programme.\n");
        return EXIT_FAILURE;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
    if(renderer == NULL) {
        fprintf(stderr, "Impossible de créer le renderer. Fin du programme.\n");
        return EXIT_FAILURE;
    }

    // Fonctions pour jouer
    printf("%d", test());
     //test d'afficher un square
    newSquare = Square::Square(1, 10., 10., 10., 10., 1., 0., 0.);
    newSquare->drawSquare();


    int loop = 1;
    while(loop) {

        SDL_RenderClear(renderer);
        //SDL_RenderCopy(renderer, texture, NULL, NULL);
        SDL_RenderPresent(renderer);

        SDL_Event e;
        while(SDL_PollEvent(&e)) {
            if(e.type == SDL_QUIT) {
                loop = 0;
                break;
            }
        }
    }

    SDL_Quit();

    return EXIT_SUCCESS;
}