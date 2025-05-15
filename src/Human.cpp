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


