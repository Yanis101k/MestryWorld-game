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

