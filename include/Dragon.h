#ifndef DRAGON_H
#define DRAGON_H

#include "AnimateEntity.h"

class Dragon : public AnimateEntity {
public:
    Dragon(int x, int y);
    void display() const override;
    std::string getType() const override;
    void move(class Room& room) override;
};

#endif
