#ifndef HOLE_H
#define HOLE_H

#include "InanimateEntity.h"

class Hole : public InanimateEntity {
private:
    float depth;  // Depth of the hole (0 to 20)

public:
    Hole(int x, int y, float depth);
    float getDepth() const;

    void display() const override;
    std::string getType() const override;
};

#endif
