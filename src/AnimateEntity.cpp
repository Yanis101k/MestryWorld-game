#include "../include/AnimateEntity.h"

AnimateEntity::AnimateEntity(int x, int y)
    : Entity(x, y), health(100) {}

AnimateEntity::~AnimateEntity() {}

int AnimateEntity::getHealth() const {
    return health;
}

void AnimateEntity::reduceHealth(int amount) {
    health -= amount;
    if (health < 0) health = 0;
}
