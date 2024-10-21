#ifndef GAME_HPP
#define GAME_HPP

#include "Map.hpp"
#include "Player.hpp"
#include <iostream>

class Game {
private:
    Map gameMap;
    Player player;
    bool gameOver;

public:
    // Constructor to initialize the game
    Game();
    Game(const Game& other);             // Constructor de copiere
    Game& operator=(const Game& other);  // Operator de atribuire
    bool operator==(const Game& other) const; // Operator de comparație egalitate

    // Main game loop
    void run();

    // Handle player input
    void handleInput();

    // Check if the game is over
    bool isGameOver() const;

    // Operatori de intrare/ieșire
    friend std::istream& operator>>(std::istream& in, Game& game);
    friend std::ostream& operator<<(std::ostream& out, const Game& game);
};

#endif
