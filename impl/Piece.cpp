#include "../headers/Piece.hpp"

Piece::Piece(Shape shape, Color color) : shape(shape), color(color) {}

Shape Piece::getShape() const
{
    return shape;
}

Color Piece::getColor() const
{
    return color;
}

bool Piece::operator==(const Piece &other) const
{
    return color == other.color && shape == other.shape;
}

std::string Piece::getShapeAsString() const
{
    switch (shape)
    {
    case Shape::CIRCLE:
        return "cercle";
    case Shape::TRIANGLE:
        return "triangle";
    case Shape::DIAMOND:
        return "losange";
    case Shape::SQUARE:
        return "carré";
    default:
        return "forme inconnue";
    }
}

std::string Piece::getColorAsString() const
{
    switch (color)
    {
    case Color::RED:
        return "Rouge";
    case Color::YELLOW:
        return "Jaune";
    case Color::GREEN:
        return "Vert";
    case Color::BLUE:
        return "Bleu";
    default:
        return "Couleur inconnue";
    }
}