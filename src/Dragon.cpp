#include "../include/Dragon.h"
#include "../include/Room.h"
#include <iostream>
#include <cstdlib>

Dragon::Dragon(int x, int y) : AnimateEntity(x, y) {}

void Dragon::display() const {
    std::cout << "#";
}

std::string Dragon::getType() const {
    return "Dragon";
}



void Dragon::move(Room& room) {
    for (int attempt = 0; attempt < 10; ++attempt) {
        int dx = std::rand() % 3 - 1;
        int dy = std::rand() % 3 - 1;
        int nx = x + dx;
        int ny = y + dy;
        if ((dx != 0 || dy != 0) &&
            nx >= 0 && nx < Room::getHeight() &&
            ny >= 0 && ny < Room::getWidth() &&
            room.getEntityAt(nx, ny) == nullptr) {
            room.moveEntity(this, nx, ny);
            break;
        }
    }

    int healthLoss = std::rand() % 6;
    reduceHealth(healthLoss);
}

