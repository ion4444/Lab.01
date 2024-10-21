#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Map.hpp"
#include <iostream>

class Player {
private:
    int x;       // Coordonata x a jucătorului
    int y;       // Coordonata y a jucătorului
    int score;   // Scorul jucătorului

public:
    // Constructor pentru a inițializa poziția de început a jucătorului
    Player(int startX, int startY);

    // Constructor de copiere
    Player(const Player& other);

    // Operator de atribuire
    Player& operator=(const Player& other);

    // Operator de comparație egalitate
    bool operator==(const Player& other) const;

    // Mută jucătorul în funcție de input
    void move(char direction, const Map &map);

    // Verifică dacă jucătorul a intrat în coliziune cu hrana
    void checkFoodCollision(Map &map);

    // Funcții de acces pentru coordonatele jucătorului și scor
    int getX() const { return x; }
    int getY() const { return y; }
    int getScore() const { return score; }
};

#endif
