#ifndef ROOM_H
#define ROOM_H

#include "Entity.h"

class Room {
private:
    static const int WIDTH = 10;
    static const int HEIGHT = 10;

    Entity* grid[HEIGHT][WIDTH];

public:
    Room();
    ~Room();

    static int getWidth();
    static int getHeight();

    void addEntity(Entity* entity);
    Entity* getEntityAt(int x, int y) const;
    void moveEntity(Entity* entity, int newX, int newY);
    void display() const;
    void reset();  // Later
};

#endif

