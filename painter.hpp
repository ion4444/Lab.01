#pragma once

#include "abstract_painter.hpp"

// Clasa Painter care extinde AbstractPainter
class Painter : public AbstractPainter {
public:
    // Implementarea funcției pentru a desena o imagine
    virtual void DrawImage(Point topLeft, Point bottomRight, char** image) override;

    // Implementarea funcției pentru a scrie un text
    virtual void WriteText(Point position, char* text) override;
};
