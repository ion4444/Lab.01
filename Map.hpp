// Map.hpp #ifndef MAP_HPP #define MAP_HPP

class Map { public: static const int width = 20; static const int height = 10; char map[height][width]; // 2D array for the game map

// Constructor to initialize the map
Map();

// Function to draw the map
void drawMap(int playerX, int playerY, int score) const;

// Check if the given position is a wall
bool isWall(int x, int y) const;

// Set the map element at (x, y)
void setMapElement(int x, int y, char element);
};

#endif
