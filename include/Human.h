#ifndef HUMAN_H
#define HUMAN_H

#include "AnimateEntity.h"
#include <string>

class Human : public AnimateEntity {
private:
    std::string name;

public:
    Human(int x, int y, const std::string& name);
    void display() const override;
    std::string getType() const override;
    //void move(class Room& room) override;

    std::string getName() const;
};

#endif
