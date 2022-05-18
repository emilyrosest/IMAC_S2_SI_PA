#ifndef QUADTREE_H
#include "position.hpp"


typedef struct AABB {
    Position position;
    float height;
    float weight;
} AABB;



AABB createAABB(Position p, float h, float w);
void drawBox(AABB box);

bool collision(AABB box1, AABB box2);

//AABB Array (voir si dansun fichier à part)
const int MAX_DECOR_COUNT = 23;
/*
AABB allDecor[MAX_DECOR_COUNT] = {
    createAABB(Position(-4., 5.), 1., 2.), 
    createAABB(Position(4., 7.), 3., 1.),
    createAABB(Position(-6., -3.), 2., 3.),
    createAABB(Position(-1., -7.), 4., 1.),
    createAABB(Position(8., 2.), 1., 2.),
    createAABB(Position(-8., 6.), 3., 3.),
    createAABB(Position(-8., -2.), 3., 2.),
    createAABB(Position(-6., 7.), 2., 2.),
    createAABB(Position(-7., 2.), 3., 1.),
    createAABB(Position(8., -2.), 1., 2.),
    createAABB(Position(-11., 9.), 3., 2.),
    createAABB(Position(-13., 13.), 2., 1.),
    createAABB(Position(-9., 9.), 2., 2.),
    createAABB(Position(-10., 10.), 1., 1.),
    createAABB(Position(-3., 4.), 2., 2.),
    createAABB(Position(-5., -6.), 1., 1.),
    createAABB(Position(-7., -5.), 2., 2.),
    createAABB(Position(-4., -9.), 1., 1.),
    createAABB(Position(-2., -4.), 1., 1.),
    createAABB(Position(-2., -6.), 1., 1.),
    createAABB(Position(-4., -7.), 1., 1.),
    createAABB(Position(-4., -8.), 1., 1.),
    createAABB(Position(-4., -10.), 1., 1.) 
}; */



class QuadTree {


public : 

    Position topLeft;
    Position bottomRight;

    int boxCount;

    AABB* boxes[50];

    QuadTree* topLeftTree;
    QuadTree* topRightTree;
    QuadTree* bottomLeftTree;
    QuadTree* bottomRightTree;

    QuadTree(Position topL, Position botR) {
            
        topLeftTree = nullptr;
        topRightTree = nullptr;
        bottomLeftTree = nullptr;
        bottomRightTree = nullptr;
        topLeft = topL;
        bottomRight = botR;
        boxCount = 0;
    }

    ~QuadTree() {
        if (topLeftTree != nullptr) {
            delete topLeftTree;
        }
        if (topRightTree != nullptr) {
            delete topRightTree;
        }
        if (bottomLeftTree != nullptr) {
            delete bottomLeftTree;
        }
        if (bottomRightTree != nullptr) {
            delete bottomRightTree;
        }

    }

    Position getTopLeft() { return topLeft; };
    Position getBottomRight() { return bottomRight; };

    void initNodes();

    bool isLeaf();

    void insertAtGoodPlace(AABB* box);

    void insertBox(AABB* box);

    void insertAllDecor(AABB aabb_decor[]);

    void drawLine();

    int getBoxCount() { return boxCount; };

    AABB getAABB(int i) { return *boxes[i]; };

    QuadTree* search(Position pos);

};

#endif
