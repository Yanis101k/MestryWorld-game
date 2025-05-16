#include "../include/Monster.h"
#include "../include/Room.h"
#include <iostream>
#include <cstdlib>

Monster::Monster(int x, int y, int strength)
    : AnimateEntity(x, y), strength((strength >= 0 && strength <= 5) ? strength : 0) {}


void Monster::display() const {
    std::cout << "*";
}

std::string Monster::getType() const {
    return "Monster";
}

int Monster::getStrength() const {
    return strength ; 
}


void Monster::move(Room& room) {
    const int directions[4][2] = {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}
    };

    for (int d = 0; d < 4; ++d) {
        int nx = x + directions[d][0] * strength;
        int ny = y + directions[d][1] * strength;

        if (nx >= 0 && nx < Room::getHeight() &&
            ny >= 0 && ny < Room::getWidth() &&
            room.getEntityAt(nx, ny) == nullptr) {
            room.moveEntity(this, nx, ny);
            reduceHealth(strength);
            return;
        }
    }

    // Else: move to random adjacent
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
            reduceHealth(1);
            return;
        }
    }
}

