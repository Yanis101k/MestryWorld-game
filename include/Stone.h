#ifndef STONE_H
#define STONE_H

#include "InanimateEntity.h"

class Stone : public InanimateEntity {
public:
    Stone(int x, int y);
    void display() const override;
    std::string getType() const override;
};

#endif
