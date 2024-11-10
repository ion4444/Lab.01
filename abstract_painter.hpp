#pragma once

#include "map.hpp"  // Include fișierul map.hpp pentru a avea acces la clasa Map
#include <string>
#include <vector>
#include <memory>

// Clasa abstractă AbstractPainter
struct AbstractPainter {
    // Funcție virtuală pură pentru a desena o imagine
    virtual void DrawImage(Point topLeft, Point bottomRight, const std::vector<std::vector<char>>& image) = 0;

    // Funcție virtuală pură pentru a scrie un text
    virtual void WriteText(Point position, const std::string& text) = 0;

    // Destructor virtual pentru a asigura distrugerea corectă a derivatei
    virtual ~AbstractPainter() = default; 
};
