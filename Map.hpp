#pragma once
#include <vector>
#include <string>

class Map {
public:
    Map();
    void displayMap() const;

private:
    std::vector<std::string> tiles;
};
