#ifndef INANIMATE_ENTITY_H
#define INANIMATE_ENTITY_H

#include "Entity.h"

class InanimateEntity : public Entity {
public:
    InanimateEntity(int x, int y) : Entity(x, y) {}
    virtual ~InanimateEntity() = default;
};

#endif