#include <iostream>
#include <vector>
#include <memory>
#include "Player.h"
#include "Map.h"

class Game {
public:
    Game() : players(), gameMap(std::make_shared<Map>()) {}
    
    void addPlayer(const std::string& name) {
        players.push_back(std::make_unique<Player>(name));
    }

    void displayPlayers() const {
        std::cout << "Players in the game:\n";
        for (const auto& player : players) {
            std::cout << player->getName() << "\n";
        }
    }

    void run() {
        // Example of using an algorithm (std::for_each) on players
        std::for_each(players.begin(), players.end(), [](const auto& player) {
            player->move();
        });
    }

private:
    std::vector<std::unique_ptr<Player>> players;
    std::shared_ptr<Map> gameMap;
};
