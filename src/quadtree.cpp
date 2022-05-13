#include <GL/gl.h>
#include <GL/glu.h>

#include "quadtree.hpp"


AABB createAABB(Position p, float h, float w) {
    AABB box;
    box.position = p;
    box.height = h;
    box.weight = w;
    return box;
}

void drawBox(AABB box) {
    float x = box.position.x;
    float y = box.position.y;
    float h = box.height;
    float w = box.weight;

    glBegin(GL_QUADS);
    glVertex2f( x , y);
    glVertex2f( x + w , y);
    glVertex2f( x + w , y + h);
    glVertex2f( x , y + h);
    glEnd();
}


void QuadTree::initNodes() {
    if (topLeftTree == nullptr) {
        topLeftTree = new QuadTree(Position(topLeft.x, topLeft.y), Position((bottomRight.x + topLeft.x) /2, (bottomRight.y + topLeft.y) /2));
    }
    if (topRightTree == nullptr) {
        topRightTree = new QuadTree(Position((bottomRight.x + topLeft.x) /2, topLeft.y), Position(bottomRight.x, (bottomRight.y + topLeft.y) /2));
    }
    if (bottomLeftTree == nullptr) {
        bottomLeftTree = new QuadTree(Position(topLeft.x, (bottomRight.y + topLeft.y) /2), Position((bottomRight.x + topLeft.x) /2, bottomRight.y));
    }
    if (bottomRightTree == nullptr) {
        bottomRightTree = new QuadTree(Position((bottomRight.x + topLeft.x) /2, (bottomRight.y + topLeft.y) /2), Position(bottomRight.x, bottomRight.y));
    }
    //drawLine();
}

bool QuadTree::isLeaf() {
    return (topLeftTree == nullptr && topRightTree == nullptr && bottomLeftTree == nullptr && bottomRightTree == nullptr);
}

void QuadTree::drawLine() {
    glBegin(GL_LINES); 
        glVertex2f((topLeft.x + bottomRight.x) / 2, topLeft.y);
        glVertex2f((topLeft.x + bottomRight.x) / 2, bottomRight.y);
    glEnd();
    glBegin(GL_LINES); 
        glVertex2f(topLeft.x, (topLeft.y + bottomRight.y) / 2);
        glVertex2f(bottomRight.x, (topLeft.y + bottomRight.y) / 2);
    glEnd();
}

void QuadTree::insertAtGoodPlace(AABB* box) {
    if ((topLeft.x + bottomRight.x) / 2 >= box->position.x) {
        if ((topLeft.y + bottomRight.y) / 2 <= box->position.y) { 
            topLeftTree->insertBox(box);
        } else {
            bottomLeftTree->insertBox(box);
        }
    } else {
        if ((topLeft.y + bottomRight.y) / 2 <= box->position.y) {
            topRightTree->insertBox(box);
        } else {
            bottomRightTree->insertBox(box);
        }
    } 
}

void QuadTree::insertBox(AABB* box) {

    if (isLeaf() && boxCount < 4) {
        boxes[boxCount] = box;
        boxCount++;
        drawBox(*box);
        return;
    } 

    if (isLeaf() && boxCount > 3) {
        initNodes();
        for (int i = 0; i < boxCount; i++) { 
            insertAtGoodPlace(boxes[i]);
        } 
    
        for (int i = 0; i < boxCount; i++) {
            boxes[i] = nullptr;
        } 
        boxCount = 0; 
        return;
    } 
    if (!isLeaf()) {
        insertAtGoodPlace(box);
    } 
}

//Peut-être le bouger si besoin
void QuadTree::insertAllDecor() {
    for (int i = 0; i < MAX_DECOR_COUNT; i++) {
        insertBox(&allDecor[i]);
    }
}

QuadTree* QuadTree::search(Position pos) {
    if (isLeaf()) {
        return this;
    }
    if (!isLeaf()) {
        if ((topLeft.x + bottomRight.x) / 2 >= pos.x) { 
            if ((topLeft.y + bottomRight.y) / 2 <= pos.y) { 

                return topLeftTree->search(pos);
            } else {
                return bottomLeftTree->search(pos);
            }
        } else {
            if ((topLeft.y + bottomRight.y) / 2 <= pos.y) {

                return topRightTree->search(pos);
            } else {
                return bottomRightTree->search(pos);
            }
        } 
    } 
    return nullptr;
}