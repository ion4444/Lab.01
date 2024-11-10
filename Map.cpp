#include <iostream>
#include <vector>
#include <string>
#include "Map.h"

Map::Map() {
    // Example of using STL containers in a map setup
    tiles = {"Grass", "Water", "Mountain"};
}

void Map::displayMap() const {
    std::cout << "Map tiles:\n";
    for (const auto& tile : tiles) {
        std::cout << tile << "\n";
    }
}
