#include "Game.hpp"

// Constructor to initialize the game
Game::Game() : gameMap(), player(), gameOver(false) {}

// Constructor de copiere
Game::Game(const Game& other) : gameMap(other.gameMap), player(other.player), gameOver(other.gameOver) {}

// Operator de atribuire
Game& Game::operator=(const Game& other) {
    if (this != &other) {
        gameMap = other.gameMap;
        player = other.player;
        gameOver = other.gameOver;
    }
    return *this;
}

// Operator de comparație egalitate
bool Game::operator==(const Game& other) const {
    return gameMap == other.gameMap && player == other.player && gameOver == other.gameOver;
}

// Main game loop
void Game::run() {
    // Implementare buclă principală
}

// Handle player input
void Game::handleInput() {
    // Implementare gestionare input
}

// Check if the game is over
bool Game::isGameOver() const {
    return gameOver;
}

// Operator de intrare
std::istream& operator>>(std::istream& in, Game& game) {
    // Citire gameMap și player din flux
    in >> game.gameMap >> game.player;
    return in;
}

// Operator de ieșire
std::ostream& operator<<(std::ostream& out, const Game& game) {
    // Afișare gameMap și player în flux
    out << game.gameMap << " " << game.player;
    return out;
}
