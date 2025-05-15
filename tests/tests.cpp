#include <cassert>
#include <iostream>
#include "../include/Stone.h"
#include "../include/Hole.h"
#include "../include/Room.h"

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

void testHole() {
    std::cout << "\n=== Running testHole() ===\n";

    // Create a hole at (1, 2 , 6.5 )
    Hole h( 1 , 2 , 6.5 );
    assert(h.getX() == 1);
    assert(h.getY() == 2);
    assert( h.getDepth() == 6.5 ) ; 
    assert(h.getType() == "Hole");

    // Redirect output of display() to verify it prints 'S'
    std::cout << "Expected symbol: O | Actual: ";
    h.display();
    std::cout << "\n";

    // Set a valid position
    h.setPosition(4, 5);
    assert(h.getX() == 4);
    assert(h.getY() == 5);

    // Set an invalid position — should not change anything
    int oldX = h.getX();
    int oldY = h.getY();
    h.setPosition(15, 10); // invalid
    assert(h.getX() == oldX); // should remain unchanged
    assert(h.getY() == oldY);

    // try to create a hole with negative depth 
    Hole h1( 1 , 2 , -6 ) ;
    assert( h1.getDepth() == 0 ) ;  

    std::cout << "✅ testStone() passed.\n";
}

void testRoomBasic() {
    std::cout << "\n=== Running testRoomBasic() ===\n";

    Room room;
    room.addEntity(new Stone(1, 1));
    room.addEntity(new Hole(2, 3, 12));
    room.addEntity(new Hole(5, 5, 18));

    std::cout << "Displaying Room:\n";
    room.display();

    std::cout << "✅ testRoomBasic() passed.\n";
}

int main(){
    testRoomBasic() ; 
}