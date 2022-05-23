#include <GL/gl.h>
#include <GL/glu.h>

#include "../include/map.hpp"



Map::Map() {
}


void Map::drawMap() {

}

void Map::initDecor(float X[], float Y[], float H[], float W[]){
string filename("/home/elise/Documents/Square_Dash/data/map.txt");

    string line;
    float x;
    float y;
    float h;
    float w;
   

    ifstream input_file(filename);
    if (!input_file.is_open()) {
        cerr << "Could not open the file - '" << filename << "'" << endl;
        //return EXIT_FAILURE;
    }
    
    int i = 0;
    int j = 0;
    int k = 0;
    int l  = 0;


    while (getline(input_file, line)){

        istringstream iss(line);
        string token;
        int lineIndex = 0;
        

        while (iss >> token) {
            if (lineIndex == 0){    
                x = stof(token);
                (X[i]) = x;
                i+= 1;
            }    
            else if (lineIndex == 1){    
                y = stof(token);
                (Y[j]) = y;
                j+= 1;
                
            }
            else if (lineIndex == 2){    
                h = stof(token);
                (H[k]) = h;
                k+= 1;
            }
            else if (lineIndex == 3){   
                w = stof(token);
                (W[l]) = w;
                l+= 1;
            }
            lineIndex++;
        }
    }

    input_file.close();
    //return EXIT_SUCCESS;
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




