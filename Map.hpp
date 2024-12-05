/**
 * @file map.hpp
 * @brief Definiția clasei Map.
 * 
 * Proiect: Game Framework  
 * Autor: [Baxanean Ionuț]  
 * Data: [12.05.24]  
 * 
 * Clasa Map gestionează structura hărții jocului și funcționalitățile asociate.
 */

#pragma once
#include <vector>
#include <string>

/**
 * @class Map
 * @brief Reprezintă o hartă de joc utilizând tile-uri.
 */
class Map {
public:
    /**
     * @brief Constructorul clasei Map.
     * Initializează structura de date a hărții.
     */
    Map();

    /**
     * @brief Afișează conținutul hărții.
     */
    void displayMap() const;

private:
    std::vector<std::string> tiles; /**< Tile-urile ce compun harta. */
};
