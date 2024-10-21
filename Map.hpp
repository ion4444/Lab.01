#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <vector>

class Map {
private:
    static const int width = 20;  // Lățimea hărții
    static const int height = 10; // Înălțimea hărții
    char map[height][width];      // Harta ca matrice de caractere

public:
    // Constructor pentru a inițializa harta
    Map();
    Map(const Map& other);                   // Constructor de copiere
    Map& operator=(const Map& other);        // Operator de atribuire
    bool operator==(const Map& other) const; // Operator de comparație egalitate

    // Funcție pentru a desena harta
    void drawMap(int playerX, int playerY, int score) const;

    // Verifică dacă o poziție dată este un zid
    bool isWall(int x, int y) const;

    // Setează elementul hărții la (x, y)
    void setMapElement(int x, int y, char element);

    // Operatori de intrare/ieșire
    friend std::istream& operator>>(std::istream& in, Map& map);
    friend std::ostream& operator<<(std::ostream& out, const Map& map);
};

#endif
