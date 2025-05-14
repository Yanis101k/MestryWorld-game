#include <iostream>
#include "../include/Entity.h"
#include "../include/Room.h"

// Constructor
Entity::Entity(int x, int y) : x(x), y(y) {}

// Virtual destructor
Entity::~Entity() {}

// Getter for x
int Entity::getX() const {
    return x;
}

// Getter for y
int Entity::getY() const {
    return y;
}

// Set position with validation
void Entity::setPosition(int newX, int newY) {
    if (newX >= 0 && newX < Room::getHeight() && newY >= 0 && newY < Room::getWidth()) {
        x = newX;
        y = newY;
    } else {
        std::cerr << "Invalid position: (" << newX << ", " << newY << ")" << std::endl;
    }
}
