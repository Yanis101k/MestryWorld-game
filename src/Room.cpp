#include <iostream>
#include "../include/Room.h"

Room::Room() {
    for (int i = 0; i < HEIGHT; ++i)
        for (int j = 0; j < WIDTH; ++j)
            grid[i][j] = nullptr;
}

Room::~Room() {
    for (int i = 0; i < HEIGHT; ++i)
        for (int j = 0; j < WIDTH; ++j)
            delete grid[i][j];  // clean up memory
}

int Room::getWidth() {
    return WIDTH;
}

int Room::getHeight() {
    return HEIGHT;
}

void Room::addEntity(Entity* entity) {
    int x = entity->getX();
    int y = entity->getY();
    if (x >= 0 && x < HEIGHT && y >= 0 && y < WIDTH && grid[x][y] == nullptr) {
        grid[x][y] = entity;
    } else {
        std::cerr << "Cannot place entity at (" << x << ", " << y << ")\n";
    }
}

void Room::display() const {
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            if (grid[i][j]) grid[i][j]->display();
            else std::cout << ".";
        }
        std::cout << "\n";
    }
}
