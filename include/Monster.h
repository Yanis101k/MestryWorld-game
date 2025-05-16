#ifndef MONSTER_H
#define MONSTER_H

#include "AnimateEntity.h"

class Monster : public AnimateEntity {
private:
    int strength;

public:
    Monster(int x, int y, int strength);
    void display() const override;
    std::string getType() const override;
    int getStrength() const ; 
    void move(class Room& room) override;
};

#endif
