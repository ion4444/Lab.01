#include "Game.hpp"
#include <iostream>

// Constructor to initialize the game
Game::Game() : gameMap(), player(), gameOver(false) {
    // Initialize the game (set up the map, player position, etc.)
    std::cout << "Game initialized!" << std::endl;
}

// Main game loop
void Game::run() {
    while (!gameOver) {
        handleInput();  // Get user input
        // Add game logic here (like updating the map, moving the player, etc.)
        if (isGameOver()) {
            std::cout << "Game Over!" << std::endl;
            gameOver = true;
        }
    }
}

// Handle player input
void Game::handleInput() {
    char input;
    std::cout << "Enter input (w/a/s/d to move, q to quit): ";
    std::cin >> input;

    switch (input) {
        case 'w': player.moveUp(); break;
        case 'a': player.moveLeft(); break;
        case 's': player.moveDown(); break;
        case 'd': player.moveRight(); break;
        case 'q': gameOver = true; break;
        default: std::cout << "Invalid input!" << std::endl;
    }
}

// Check if the game is over
bool Game::isGameOver() const {
    // Add logic to check if the game is actually over (e.g., player wins, etc.)
    return gameOver;
}
