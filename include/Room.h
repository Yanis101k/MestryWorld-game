#ifndef ROOM_H
#define ROOM_H

class Room {
private:
    static const int WIDTH = 10;   // Number of columns in the grid
    static const int HEIGHT = 10;  // Number of rows in the grid

public:
    // Getter for grid width (columns)
    static int getWidth();

    // Getter for grid height (rows)
    static int getHeight();
};

#endif
