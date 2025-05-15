#ifndef ANIMATE_ENTITY_H
#define ANIMATE_ENTITY_H

#include "Entity.h"

class AnimateEntity : public Entity {
protected:
    int health;

public:
    AnimateEntity(int x, int y);
    virtual ~AnimateEntity();

    int getHealth() const;
    void reduceHealth(int amount);

    //virtual void move(class Room& room) = 0; // pure virtual
};

#endif
