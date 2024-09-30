#include "Player.hpp"
#include "Map.hpp"
#include <iostream>

// Constructor to initialize the player's starting position
Player::Player(int startX, int startY) : x(startX), y(startY), score(0) {
    // Initialize player's position and score
}

// Move the player based on input
void Player::move(char direction, const Map &map) {
    // Store the new position based on the input direction
    int newX = x;
    int newY = y;

    switch (direction) {
        case 'w': newX--; break;  // Move up
        case 'a': newY--; break;  // Move left
        case 's': newX++; break;  // Move down
        case 'd': newY++; break;  // Move right
        default:
            std::cout << "Invalid direction!" << std::endl;
            return;
    }

    // Check if the new position is not a wall
    if (!map.isWall(newX, newY)) {
        x = newX;
        y = newY;
    } else {
        std::cout << "Hit a wall! Can't move there." << std::endl;
    }
}

// Check if the player has collided with food
void Player::checkFoodCollision(Map &map) {
    // Assuming that 'F' represents food on the map
    if (map.map[x][y] == 'F') {
        score += 10;  // Increase score
        map.setMapElement(x, y, ' ');  // Remove the food from the map
        std::cout << "Food collected! Score: " << score << std::endl;
    }
}
