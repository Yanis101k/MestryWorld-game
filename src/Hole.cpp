
#include <iostream>
#include "../include/Hole.h"

// Constructor with depth validation
Hole::Hole(int x, int y, float depth)
    : InanimateEntity(x, y), depth((depth >= 0 && depth <= 20) ? depth : 0) {}

// Getter for depth
float Hole::getDepth() const {
    return depth;
}

// Display symbol for hole
void Hole::display() const {
    std::cout << "O";
}

// Return type of entity
std::string Hole::getType() const {
    return "Hole";
}
