#ifndef PIECE_H
#define PIECE_H

#include <cstdlib> // Pour utiliser la fonction rand()
#include <ctime>   // Pour initialiser le générateur de nombres aléatoires avec le temps actuel
#include <string>  // std::string

enum class Shape
{
    CIRCLE,
    TRIANGLE,
    DIAMOND,
    SQUARE
};
enum class Color
{
    RED,
    YELLOW,
    GREEN,
    BLUE
};

class Piece
{
public:
    Piece(Shape shape, Color color);
    Shape getShape() const;
    Color getColor() const;
    bool operator==(const Piece &other) const;

    static Piece generateRandomPiece()
    {
        // Initialiser le générateur de nombres aléatoires avec le temps actuel
        std::srand(static_cast<unsigned int>(std::time(nullptr)));

        // Générer aléatoirement une forme et une couleur
        Shape randomShape = static_cast<Shape>(std::rand() % 4);
        Color randomColor = static_cast<Color>(std::rand() % 4);

        // Créer et retourner une nouvelle pièce avec la forme et la couleur aléatoires
        return Piece(randomShape, randomColor);
    }

    std::string getShapeAsString() const;
    std::string getColorAsString() const;

private:
    Shape shape;
    Color color;
};

#endif // PIECE_H
