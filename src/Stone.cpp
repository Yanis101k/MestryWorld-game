#include <iostream>
#include "Stone.h"

// Pass x and y to parent constructor
Stone::Stone(int x, int y) : InanimateEntity(x, y) {}

// Print the symbol for a stone
void Stone::display() const {
    std::cout << "S";
}

// Return the type of this entity
std::string Stone::getType() const {
    return "Stone";
}
