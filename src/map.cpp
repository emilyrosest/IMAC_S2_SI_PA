#include <GL/gl.h>
#include <GL/glu.h>

#include "../include/map.hpp"



Map::Map() {
}


void Map::initLevel1(float X1[], float Y1[], float H1[], float W1[]){

string filename("data/newlevel1.txt");

    string line;
    float x;
    float y;
    float h;
    float w;
   

    ifstream input_file(filename);
    if (!input_file.is_open()) {
        cerr << "Could not open the file - '" << filename << "'" << endl;
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
}

void Map::initLevel2(float X2[], float Y2[], float H2[], float W2[]){

string filename("data/newlevel2.txt");

    string line;
    float x;
    float y;
    float h;
    float w;
   

    ifstream input_file(filename);
    if (!input_file.is_open()) {
        cerr << "Could not open the file - '" << filename << "'" << endl;
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
}
