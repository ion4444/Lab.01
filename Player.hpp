// Player.hpp #ifndef PLAYER_HPP #define PLAYER_HPP

class Player { public: int x, y; // Player's position int score; // Player's score

// Constructor to initialize the player's starting position
Player(int startX, int startY);

// Move the player based on input
void move(char direction, const class Map &map);

// Check if the player has collided with food
void checkFoodCollision(class Map &map);
};

#endif
