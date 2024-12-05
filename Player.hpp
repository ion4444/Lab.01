/**
 * @file player.hpp
 * @brief Declarația clasei Player.
 * 
 * Proiect: Game Framework  
 * Autor: [Baxanean Ionuț]  
 * Data: [05.12.24]  
 * 
 * Clasa Player reprezintă un jucător cu funcționalități de bază.
 */

#pragma once
#include <string>

/**
 * @class Player
 * @brief Reprezintă un jucător în cadrul jocului.
 */
class Player {
public:
    /**
     * @brief Constructorul clasei Player.
     * @param name Numele jucătorului.
     */
    explicit Player(const std::string& name);

    /**
     * @brief Simulează mișcarea jucătorului.
     */
    void move();

    /**
     * @brief Returnează numele jucătorului.
     * @return Numele jucătorului.
     */
    std::string getName() const;

private:
    std::string name; /**< Numele jucătorului. */
};
