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
