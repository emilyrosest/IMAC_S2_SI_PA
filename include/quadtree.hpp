#ifndef QUADTREE_H
#include "position.hpp"
#include "colors.hpp"


typedef struct AABB {
    float x;
    float y;
    Position position;
    float height;
    float width; 
    Color color;
} AABB;



AABB createAABB(float x, float y, float h, float w, Color c);
void drawBox(AABB box);

bool collision(AABB box1, AABB box2);


const int MAX_DECOR_COUNT = 78;
const int MAX_DECOR_COUNT_2 = 108;


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

    QuadTree* search2(float x, float y);

    AABB** searchAABB(float x, float y);

    void colli(float x, float y, float h, float w);

    bool colliBool(float x, float y, float h, float w);
    int isOnTheFloor(float x, float y, float h, float w);


};

#endif
