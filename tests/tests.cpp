#include <cassert>
#include <iostream>
#include "../include/Stone.h"
#include "../include/Hole.h"
#include "../include/Room.h"
#include "../include/AnimateEntity.h"
#include "../include/Human.h"
#include "../include/Dragon.h"
#include "../include/Monster.h"

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

void testResetRoom() {
    std::cout << "\n=== Running testResetRoom() ===\n";

    Room room;
    room.reset();
    room.display();

    std::cout << "✅ testResetRoom() finished.\n";
}

void testHuman(){
    std::cout <<"\n=== Runing testHumane() ===\n"; 
    Human h( 2 , 3 , "yanis" ) ;

    assert( h.getX() == 2 ) ;
    assert( h.getY() == 3 ) ; 
    assert( h.getName() == "yanis") ; 
    assert( h.getHealth() == 100 ) ; 
    assert( h.getType() == "Human") ; 

    h.reduceHealth( 50 ) ; 

    assert( h.getHealth() == 50 ) ;
    
    h.reduceHealth(60) ; 
    assert( h.getHealth() == 0 ) ; 
    

    // Redirect output of display() to verify it prints 'S'
    std::cout << "Expected symbol: @ | Actual: ";
    h.display();
    std::cout << "\n";
    
    std::cout << "\n === ✅ Humane class test passed  " ; 
}

void testDragon(){

    std::cout <<"\n=== Runing testHumane() ===\n" ; 
    Dragon d( 7 , 8 ) ; 
    
    assert( d.getX() == 7 ) ; 
    assert( d.getY() == 8 ) ;
    assert( d.getHealth() == 100 ) ; 
    assert( d.getType() == "Dragon" ) ; 
    
    
    d.reduceHealth( 50 ) ; 

    assert( d.getHealth() == 50 ) ;
    
    d.reduceHealth(60) ; 
    assert( d.getHealth() == 0 ) ; 

    // Redirect output of display() to verify it prints 'S'
    std::cout << "Expected symbol: # | Actual: ";
    d.display();
    std::cout << "\n";
    
    std::cout << "\n === ✅ Dragon class test passed  " ; 

}

void testMonster(){

    std::cout <<"\n=== Runing testHumane() ===\n" ; 
    Monster m( 6, 8 , 9 ) ; 
    
    assert( m.getX() == 6 ) ; 
    assert( m.getY() == 8 ) ;
    assert( m.getStrength() == 0 ) ; 
    assert( m.getHealth() == 100 ) ; 
    assert( m.getType() == "Monster" ) ; 
    

    
    m.reduceHealth( 50 ) ; 

    assert( m.getHealth() == 50 ) ;
    
    m.reduceHealth(60) ; 
    assert( m.getHealth() == 0 ) ; 

    // Remirect output of misplay() to verify it prints 'S'
    std::cout << "Expectem symbol: * | Actual: ";
    m.display();
    std::cout << "\n";
    
    std::cout << "\n === ✅ Dragon class test passed  " ; 

}

void testMovement() {
    std::cout << "\n=== Running testMovement() ===\n";

    Room room;

    // Create and place a Human
    Human* h = new Human(2, 2, "Harold");
    room.addEntity(h);

    // Create and place a Dragon
    Dragon* d = new Dragon(3, 3);
    room.addEntity(d);

    // Create and place a Monster
    Monster* m = new Monster(4, 4, 3);
    room.addEntity(m);

    std::cout << "Room before movement:\n";
    room.display();

    // Move each entity
    h->move(room);
    d->move(room);
    m->move(room);

    std::cout << "\nRoom after movement:\n";
    room.display();

    // Print healths after movement
    std::cout << "\nHealths:\n";
    std::cout << "Human (Harold): " << h->getHealth() << "\n";
    std::cout << "Dragon: " << d->getHealth() << "\n";
    std::cout << "Monster: " << m->getHealth() << "\n";

    std::cout << "✅ testMovement() completed.\n";
}

void testMoveAll() {
    std::cout << "\n=== Running testMoveAll() ===\n";

    Room room;
    room.reset();  // places 3 Humans, 3 Monsters, 2 Dragons
    std::cout << "Before movement:\n";
    room.display();

    room.moveAll();

    std::cout << "\nAfter movement:\n";
    room.display();
    std::cout << "✅ testMoveAll() completed.\n";
}

int main(){
     
    testStone();
    testHole();
    testRoomBasic();
    testResetRoom();
    testHuman();
    testMonster();
    testDragon();
    testMovement();
    testMoveAll();
}