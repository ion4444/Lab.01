#pragma once
#include <string>

class Player {
public:
    explicit Player(const std::string& name);
    void move();
    std::string getName() const;

private:
    std::string name;
};
