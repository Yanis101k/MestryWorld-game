#include "../include/Human.h"
#include "../include/Room.h"
#include <iostream>
#include <cstdlib>

Human::Human(int x, int y, const std::string& name)
    : AnimateEntity(x, y), name(name) {}

void Human::display() const {
    std::cout << "@";
}

std::string Human::getType() const {
    return "Human";
}

std::string Human::getName() const {
    return name;
}

void Human::move(Room& room) {
    int newX = x;
    int newY = y + 1;

    // Try to move right
    if (newY < Room::getWidth() && room.getEntityAt(newX, newY) == nullptr) {
        room.moveEntity(this, newX, newY);
    } else {
        // Try random adjacent cell
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
    }

    // Always lose 1 health on move attempt
    reduceHealth(1);
}

