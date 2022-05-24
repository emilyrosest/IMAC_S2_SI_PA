#ifndef QUADTREE_H
#include "position.hpp"


typedef struct AABB {
    Position position;
    float height;
    float weight; //WIDTHHHHHHHH
} AABB;



AABB createAABB(Position p, float h, float w);
void drawBox(AABB box);

bool collision(AABB box1, AABB box2);

const int MAX_DECOR_COUNT = 20;


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

    AABB* boxesToTest[4];

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
