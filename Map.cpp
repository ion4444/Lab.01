#include "Map.hpp"

// Constructor pentru a inițializa harta
Map::Map() {
    // Inițializează harta cu spații goale (' ') și ziduri ('#')
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1) {
                map[i][j] = '#';  // Ziduri de margine
            } else {
                map[i][j] = ' ';  // Spațiu gol
            }
        }
    }
}

// Constructor de copiere
Map::Map(const Map& other) {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            map[i][j] = other.map[i][j];
        }
    }
}

// Operator de atribuire
Map& Map::operator=(const Map& other) {
    if (this != &other) {
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                map[i][j] = other.map[i][j];
            }
        }
    }
    return *this;
}

// Operator de comparație egalitate
bool Map::operator==(const Map& other) const {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (map[i][j] != other.map[i][j]) {
                return false;
            }
        }
    }
    return true;
}

// Funcție pentru a desena harta
void Map::drawMap(int playerX, int playerY, int score) const {
    // Afișează scorul curent
    std::cout << "Score: " << score << std::endl;

    // Iterează prin hartă și o afișează în consolă
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (i == playerX && j == playerY) {
                std::cout << 'P';  // Afișează poziția jucătorului ca 'P'
            } else {
                std::cout << map[i][j];  // Afișează elementul hărții
            }
        }
        std::cout << std::endl;
    }
}

// Verifică dacă poziția dată este un zid
bool Map::isWall(int x, int y) const {
    if (x < 0 || x >= height || y < 0 || y >= width) {
        return true;  // Ieșirea din limite este considerată zid
    }
    return map[x][y] == '#';  // Returnează true dacă poziția este un zid ('#')
}

// Setează elementul hărții la (x, y)
void Map::setMapElement(int x, int y, char element) {
    if (x >= 0 && x < height && y >= 0 && y < width) {
        map[x][y] = element;  // Setează elementul la coordonatele date
    }
}

// Operator de intrare
std::istream& operator>>(std::istream& in, Map& map) {
    for (int i = 0; i < Map::height; ++i) {
        for (int j = 0; j < Map::width; ++j) {
            in >> map.map[i][j];
        }
    }
    return in;
}

// Operator de ieșire
std::ostream& operator<<(std::ostream& out, const Map& map) {
    for (int i = 0; i < Map::height; ++i) {
        for (int j = 0; j < Map::width; ++j) {
            out << map.map[i][j];
        }
        out << std::endl;
    }
    return out;
}
