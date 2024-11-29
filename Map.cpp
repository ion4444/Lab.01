#include "map.hpp"
#include <iostream>

Map::Map() {
    tiles = {"Grass", "Water", "Mountain"};
}

void Map::displayMap() const {
    std::cout << "Map tiles:\n";
    for (const auto& tile : tiles) {
        std::cout << tile << "\n";
    }
}
