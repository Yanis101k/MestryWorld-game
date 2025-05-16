#include <iostream>
#include "../include/Room.h"
#include <cstdlib>   // for rand()
#include <ctime>     // for time()
#include "../include/Stone.h"
#include "../include/Hole.h"
#include "../include/Human.h"
#include "../include/Monster.h"
#include "../include/Dragon.h"


Room::Room() {
    for (int i = 0; i < HEIGHT; ++i)
        for (int j = 0; j < WIDTH; ++j)
            grid[i][j] = nullptr;
}

Room::~Room() {
    for (int i = 0; i < HEIGHT; ++i)
        for (int j = 0; j < WIDTH; ++j)
            delete grid[i][j];  // clean up memory
}

int Room::getWidth() {
    return WIDTH;
}

int Room::getHeight() {
    return HEIGHT;
}

void Room::addEntity(Entity* entity) {
    int x = entity->getX();
    int y = entity->getY();
    if (x >= 0 && x < HEIGHT && y >= 0 && y < WIDTH && grid[x][y] == nullptr) {
        grid[x][y] = entity;
    } else {
        std::cerr << "Cannot place entity at (" << x << ", " << y << ")\n";
    }
}

void Room::display() const {
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            if (grid[i][j]) grid[i][j]->display();
            else std::cout << ".";
        }
        std::cout << "\n";
    }
}

// Return a pointer to the entity at a specific location (or nullptr)
Entity* Room::getEntityAt(int x, int y) const {
    if (x >= 0 && x < HEIGHT && y >= 0 && y < WIDTH) {
        return grid[x][y];
    }
    return nullptr;  // out-of-bounds access
}

// Move the entity to a new valid cell and update grid positions
void Room::moveEntity(Entity* entity, int newX, int newY) {
    int oldX = entity->getX();
    int oldY = entity->getY();

    // Safety: check if target is in bounds and empty
    if (newX >= 0 && newX < HEIGHT &&
        newY >= 0 && newY < WIDTH &&
        grid[newX][newY] == nullptr) {
        
        // Move entity
        grid[oldX][oldY] = nullptr;
        grid[newX][newY] = entity;
        entity->setPosition(newX, newY);
    } else {
        std::cerr << "❌ moveEntity: Invalid or occupied position (" << newX << ", " << newY << ")\n";
    }
}


void Room::reset() {
    // Clear old grid
    for (int i = 0; i < HEIGHT; ++i)
        for (int j = 0; j < WIDTH; ++j) {
            delete grid[i][j];
            grid[i][j] = nullptr;
        }

    // Seed random only once (do this in constructor ideally, or leave for now)
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    // Helper lambda to get random empty position
    auto getRandomEmptyPosition = [&]() {
        int x, y;
        do {
            x = std::rand() % HEIGHT;
            y = std::rand() % WIDTH;
        } while (grid[x][y] != nullptr);
        return std::make_pair(x, y);
    };

    // Place 2 Stones
    for (int i = 0; i < 2; ++i) {
        auto [x, y] = getRandomEmptyPosition();
        addEntity(new Stone(x, y));
    }

    // Place 2 Holes (depth 0–20)
    for (int i = 0; i < 2; ++i) {
        auto [x, y] = getRandomEmptyPosition();
        int depth = std::rand() % 21;
        addEntity(new Hole(x, y, depth));
    }

    
}