#pragma once
#include "abstract_painter.hpp"
#include <string>
#include <vector>

class Painter : public AbstractPainter {
public:
    virtual void DrawImage(Point topLeft, Point bottomRight, const std::vector<std::vector<char>>& image) override;
    virtual void WriteText(Point position, const std::string& text) override;
};
