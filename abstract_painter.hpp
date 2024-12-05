/**
 * @file abstract_painter.hpp
 * @brief Declarația clasei AbstractPainter.
 * 
 * Proiect: Game Framework  
 * Autor: [Baxanean Ionuț]  
 * Data: [5.12.2024]  
 * 
 * Clasa AbstractPainter definește interfața pentru funcționalitățile de desenare.
 */

#pragma once
#include <vector>
#include <string>

/**
 * @struct AbstractPainter
 * @brief Interfață pentru funcții de desenare și text.
 */
struct AbstractPainter {
    /**
     * @brief Desenează o imagine între două puncte.
     * @param topLeft Punctul de colț stânga sus.
     * @param bottomRight Punctul de colț dreapta jos.
     * @param image Reprezentarea imaginii sub formă de matrice de caractere.
     */
    virtual void DrawImage(Point topLeft, Point bottomRight, const std::vector<std::vector<char>>& image) = 0;

    /**
     * @brief Scrie text într-o poziție specificată.
     * @param position Poziția unde se scrie textul.
     * @param text Textul ce trebuie afișat.
     */
    virtual void WriteText(Point position, const std::string& text) = 0;

    /**
     * @brief Destructor virtual pentru gestionarea corectă a derivatelor.
     */
    virtual ~AbstractPainter() = default;
};
