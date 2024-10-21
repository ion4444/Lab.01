#include "Player.hpp"
#include "Map.hpp"
#include <iostream>

// Constructor pentru a inițializa poziția de început a jucătorului
Player::Player(int startX, int startY) : x(startX), y(startY), score(0) {
    // Inițializează poziția și scorul jucătorului
}

// Constructor de copiere
Player::Player(const Player& other) : x(other.x), y(other.y), score(other.score) {}

// Operator de atribuire
Player& Player::operator=(const Player& other) {
    if (this != &other) {
        x = other.x;
        y = other.y;
        score = other.score;
    }
    return *this;
}

// Operator de comparație egalitate
bool Player::operator==(const Player& other) const {
    return (x == other.x) && (y == other.y) && (score == other.score);
}

// Mută jucătorul în funcție de input
void Player::move(char direction, const Map &map) {
    // Stochează noua poziție pe baza direcției de input
    int newX = x;
    int newY = y;

    switch (direction) {
        case 'w': newX--; break;  // Mutați în sus
        case 'a': newY--; break;  // Mutați la stânga
        case 's': newX++; break;  // Mutați în jos
        case 'd': newY++; break;  // Mutați la dreapta
        default:
            std::cout << "Direcție invalidă!" << std::endl;
            return;
    }

    // Verifică dacă noua poziție nu este un zid
    if (!map.isWall(newX, newY)) {
        x = newX;
        y = newY;
    } else {
        std::cout << "Ai lovit un zid! Nu poți să te muți acolo." << std::endl;
    }
}

// Verifică dacă jucătorul a intrat în coliziune cu hrana
void Player::checkFoodCollision(Map &map) {
    // Presupunând că 'F' reprezintă hrana pe hartă
    if (map.map[x][y] == 'F') {
        score += 10;  // Crește scorul
        map.setMapElement(x, y, ' ');  // Îndepărtează hrana de pe hartă
        std::cout << "Hrana colectată! Scor: " << score << std::endl;
    }
}

// Operator de intrare
std::istream& operator>>(std::istream& in, Player& player) {
    in >> player.x >> player.y >> player.score;
    return in;
}

// Operator de ieșire
std::ostream& operator<<(std::ostream& out, const Player& player) {
    out << "Player Position: (" << player.getX() << ", " << player.getY() << ") Score: " << player.getScore();
    return out;
}
