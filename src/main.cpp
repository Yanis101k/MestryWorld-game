#include <iostream>
#include "../include/Room.h"
#include "../include/Room.h"
#include "../include/Human.h"
#include "../include/Monster.h"
#include "../include/Dragon.h"
#include "../include/Hole.h"
int main() {
    Room room;
    room.reset();  // Start with a fresh room setup

    int choice;

    while (true) {
        std::cout << "\n=== MysteryWorld Menu ===\n";
        std::cout << "1. Display Room\n";
        std::cout << "2. Move All Animated Entities\n";
        std::cout << "3. Display Entity State by Coordinates\n";
        std::cout << "4. Reset the Room\n";
        std::cout << "5. Finish\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear(); std::cin.ignore(1000, '\n');
            std::cout << "❌ Invalid input. Try again.\n";
            continue;
        }

        switch (choice) {
            case 1:
                room.display();
                break;

            case 2:
                room.moveAll();
                std::cout << "✅ All animated entities moved.\n";
                break;

            case 3: {
                int row, col;
                std::cout << "Enter row (0–9): ";
                std::cin >> row;
                std::cout << "Enter column (0–9): ";
                std::cin >> col;

                Entity* entity = room.getEntityAt(row, col);
                if (entity) {
                    std::cout << "Entity properties:\n";
                    std::cout << "Type: " << entity->getType() << "\n";

                    if (entity->getType() == "Human") {
                        Human* h = dynamic_cast<Human*>(entity);
                        std::cout << "Name: " << h->getName() << "\n";
                        std::cout << "Health: " << h->getHealth() << "\n";
                    }
                    else if (entity->getType() == "Monster") {
                        Monster* m = dynamic_cast<Monster*>(entity);
                        std::cout << "Health: " << m->getHealth() << "\n";
                    }
                    else if (entity->getType() == "Dragon") {
                        Dragon* d = dynamic_cast<Dragon*>(entity);
                        std::cout << "Health: " << d->getHealth() << "\n";
                    }
                    else if (entity->getType() == "Hole") {
                        Hole* h = dynamic_cast<Hole*>(entity);
                        std::cout << "Depth: " << h->getDepth() << "\n";
                    }
                } else {
                    std::cout << "No entity at (" << row << ", " << col << ")\n";
                }
                break;
            }

            case 4:
                room.reset();
                std::cout << "✅ Room has been reset.\n";
                break;

            case 5:
                std::cout << "👋 Exiting MysteryWorld. Goodbye!\n";
                return 0;

            default:
                std::cout << "❌ Invalid choice. Please enter 1–5.\n";
        }
    }

    return 0;
}
