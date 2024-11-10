#include <iostream>
#include <string>
#include "Player.h"

Player::Player(const std::string& name) : name(name) {}

void Player::move() {
    std::cout << name << " is moving.\n";
}

std::string Player::getName() const {
    return name;
}
