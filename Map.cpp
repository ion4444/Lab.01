#include "Map.hpp"
#include <iostream>

// Constructor to initialize the map
Map::Map() {
    // Initialize the map with empty spaces (' ') and walls ('#')
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1) {
                map[i][j] = '#';  // Boundary walls
            } else {
                map[i][j] = ' ';  // Empty space
            }
        }
    }
}

// Function to draw the map
void Map::drawMap(int playerX, int playerY, int score) const {
    // Print the current score
    std::cout << "Score: " << score << std::endl;

    // Iterate through the map and print it to the console
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (i == playerX && j == playerY) {
                std::cout << 'P';  // Print the player's position as 'P'
            } else {
                std::cout << map[i][j];  // Print the map element
            }
        }
        std::cout << std::endl;
    }
}

// Check if the given position is a wall
bool Map::isWall(int x, int y) const {
    if (x < 0 || x >= height || y < 0 || y >= width) {
        return true;  // Out of bounds is considered a wall
    }
    return map[x][y] == '#';  // Return true if the position is a wall ('#')
}

// Set the map element at (x, y)
void Map::setMapElement(int x, int y, char element) {
    if (x >= 0 && x < height && y >= 0 && y < width) {
        map[x][y] = element;  // Set the element at the given coordinates
    }
}
