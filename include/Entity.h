#ifndef ENTITY_H
#define ENTITY_H

#include <string>

class Room; // Forward declaration

class Entity {
protected:
    int x;
    int y;

public:
    Entity(int x, int y);
    virtual ~Entity();

    int getX() const;
    int getY() const;
    void setPosition(int newX, int newY);

    virtual void display() const = 0;
    virtual std::string getType() const = 0;
};

#endif
