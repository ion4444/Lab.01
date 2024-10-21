#pragma once

#include "point.hpp"

// Clasa abstractă AbstractPainter
struct AbstractPainter {
    // Funcție virtuală pură pentru a desena o imagine
    virtual void DrawImage(Point topLeft, Point bottomRight, char** image) = 0;

    // Funcție virtuală pură pentru a scrie un text
    virtual void WriteText(Point position, char* text) = 0;

    // Destructor virtual pentru a asigura distrugerea corectă a derivatei
    virtual ~AbstractPainter() = default; 
};
