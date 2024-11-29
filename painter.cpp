#include "painter.hpp"
#include <iostream>

void Painter::DrawImage(Point topLeft, Point bottomRight, const std::vector<std::vector<char>>& image) {
    std::cout << "Drawing image...\n";
    for (const auto& row : image) {
        for (const auto& pixel : row) {
            std::cout << pixel;
        }
        std::cout << '\n';
    }
}

void Painter::WriteText(Point position, const std::string& text) {
    std::cout << "Writing text at (" << position.x << ", " << position.y << "): " << text << '\n';
}
