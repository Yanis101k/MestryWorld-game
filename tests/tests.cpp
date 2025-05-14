#include <cassert>
#include <iostream>
#include "Stone.h"
#include "Room.h"

void testStone() {
    std::cout << "\n=== Running testStone() ===\n";

    // Create a stone at (1, 2)
    Stone s(1, 2);
    assert(s.getX() == 1);
    assert(s.getY() == 2);
    assert(s.getType() == "Stone");

    // Redirect output of display() to verify it prints 'S'
    std::cout << "Expected symbol: S | Actual: ";
    s.display();
    std::cout << "\n";

    // Set a valid position
    s.setPosition(4, 5);
    assert(s.getX() == 4);
    assert(s.getY() == 5);

    // Set an invalid position — should not change anything
    int oldX = s.getX();
    int oldY = s.getY();
    s.setPosition(15, 10); // invalid
    assert(s.getX() == oldX); // should remain unchanged
    assert(s.getY() == oldY);

    std::cout << "✅ testStone() passed.\n";
}

int main() {
    testStone();
    std::cout << "✅ All tests passed.\n";
    return 0;
}
