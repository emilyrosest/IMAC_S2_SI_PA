#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
#include <iostream>

#include "quadtree.hpp"
#include "colors.hpp"

AABB createAABB(float x, float y, float h, float w, Color c) {
    AABB box;
    box.x = x;
    box.y = y;
    box.height = h;
    box.width = w;
    box.color = c;
    return box;
}

void drawBox(AABB box) {
    
    float x = box.x;
    float y = box.y;
    float h = box.height;
    float w = box.width;
    Color c = box.color;

    c = c.initRandomColor(box.color);
    
    glColor3f(c.r, c.g, c.b);
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
    if ((topLeft.x + bottomRight.x) / 2 >= box->x) {
        if ((topLeft.y + bottomRight.y) / 2 <= box->y) { 
            topLeftTree->insertBox(box);
        } else {
            bottomLeftTree->insertBox(box);
        }
    } else {
        if ((topLeft.y + bottomRight.y) / 2 <= box->y) {
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


void QuadTree::insertAllDecor(AABB aabb_decor[]) {
    for (int i = 0; i < MAX_DECOR_COUNT; i++) {
        insertBox(&(aabb_decor[i]));
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

QuadTree* QuadTree::search2(float x, float y) {
    if (isLeaf()) {
        return this;
    }
    if (!isLeaf()) {
        if ((topLeft.x + bottomRight.x) / 2 >= x) { 
            if ((topLeft.y + bottomRight.y) / 2 <= y) { 

                return topLeftTree->search2(x, y);
            } else {
                return bottomLeftTree->search2(x, y);
            }
        } else {
            if ((topLeft.y + bottomRight.y) / 2 <= y) {

                return topRightTree->search2(x, y);
            } else {
                return bottomRightTree->search2(x, y);
            }
        } 
    } 
    return nullptr;
}

AABB** QuadTree::searchAABB(float x, float y) {
        if (isLeaf()) {
        return this->boxes;
    }
    if (!isLeaf()) {
        if ((topLeft.x + bottomRight.x) / 2 >= x) { 
            if ((topLeft.y + bottomRight.y) / 2 <= y) { 

                return topLeftTree->searchAABB(x, y);
            } else {
                return bottomLeftTree->searchAABB(x, y);
            }
        } else {
            if ((topLeft.y + bottomRight.y) / 2 <= y) {

                return topRightTree->searchAABB(x, y);
            } else {
                return bottomRightTree->searchAABB(x, y);
            }
        } 
    } 
    return nullptr;
}


void QuadTree::colli(float x, float y, float h, float w) {

    QuadTree* nodeToTest = this->search2(x, y);

    printf("boxCount = %d \n ", nodeToTest->getBoxCount());

    for (int i = 0; i < nodeToTest->getBoxCount(); i++) {

        if (!(x + w < nodeToTest->boxes[i]->x || x > nodeToTest->boxes[i]->x + abs(nodeToTest->boxes[i]->width) || y + h < nodeToTest->boxes[i]->y || y > nodeToTest->boxes[i]->y + abs(nodeToTest->boxes[i]->height))) {
            printf(" %d : collision ", i);
        } 
        else { 
            printf (" %d : pas de collision ", i); 
        } 

    }
}

bool QuadTree::colliBool(float x, float y, float h, float w) {
    
    QuadTree* nodeToTest = this->search2(x, y);

    for (int i = 0; i < nodeToTest->getBoxCount(); i++) {

        if (!(x + w < nodeToTest->boxes[i]->x || x > nodeToTest->boxes[i]->x + abs(nodeToTest->boxes[i]->width) || y + h < nodeToTest->boxes[i]->y || y > nodeToTest->boxes[i]->y + abs(nodeToTest->boxes[i]->height))) {
            
            return true;

        } 
    } 

    return false;
}

int QuadTree::isOnTheFloor(float x, float y, float h, float w){

    QuadTree* nodeToTest = this->search2(x, y);

    int isOnTheFloor;

    for (int i = 0; i < nodeToTest->getBoxCount(); i++) {

        if (!( y + h <= nodeToTest->boxes[i]->y || y >= nodeToTest->boxes[i]->y + abs(nodeToTest->boxes[i]->height))) {

            isOnTheFloor = 1;
        }
        else{

            isOnTheFloor = 0;
        }
    }
    
    return isOnTheFloor;
}