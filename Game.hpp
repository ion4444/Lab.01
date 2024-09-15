// Game.hpp #ifndef GAME_HPP #define GAME_HPP

#include "Map.hpp" #include "Player.hpp"

class Game { private: Map gameMap; Player player; bool gameOver;

public: // Constructor to initialize the game Game();

// Main game loop
void run();

// Handle player input
void handleInput();

// Check if the game is over
bool isGameOver() const;
};

#endif
