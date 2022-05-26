#include <GL/gl.h>
#include <GL/glu.h>

#include "../include/map.hpp"



Map::Map() {
}


void Map::drawMap() {

}

void Map::initLevel1(float X1[], float Y1[], float H1[], float W1[]){
string filename("data/level1.txt");

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
                (X1[i]) = x;
                i+= 1;
            }    
            else if (lineIndex == 1){    
                y = stof(token);
                (Y1[j]) = y;
                j+= 1;
                
            }
            else if (lineIndex == 2){    
                h = stof(token);
                (H1[k]) = h;
                k+= 1;
            }
            else if (lineIndex == 3){   
                w = stof(token);
                (W1[l]) = w;
                l+= 1;
            }
            lineIndex++;
        }
    }

    input_file.close();
    //return EXIT_SUCCESS;
}

void Map::initLevel2(float X2[], float Y2[], float H2[], float W2[]){
string filename("data/level2.txt");

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
                (X2[i]) = x;
                i+= 1;
            }    
            else if (lineIndex == 1){    
                y = stof(token);
                (Y2[j]) = y;
                j+= 1;
                
            }
            else if (lineIndex == 2){    
                h = stof(token);
                (H2[k]) = h;
                k+= 1;
            }
            else if (lineIndex == 3){   
                w = stof(token);
                (W2[l]) = w;
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




