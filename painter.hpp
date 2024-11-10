#pragma once

#include "abstract_painter.hpp"
#include <iostream>
#include <vector>
#include <string>

// Clasa Painter care extinde AbstractPainter
class Painter : public AbstractPainter {
public:
    // Implementarea funcției pentru a desena o imagine
    virtual void DrawImage(Point topLeft, Point bottomRight, const std::vector<std::vector<char>>& image) override {
        std::cout << "Drawing image from (" << topLeft.x << ", " << topLeft.y << ") to (" 
                  << bottomRight.x << ", " << bottomRight.y << "):\n";
        for (const auto& row : image) {
            for (const auto& pixel : row) {
                std::cout << pixel;
            }
            std::cout << '\n';
        }
    }

    // Implementarea funcției pentru a scrie un text
    virtual void WriteText(Point position, const std::string& text) override {
        std::cout << "Writing text at (" << position.x << ", " << position.y << "): " << text << '\n';
    }
};
