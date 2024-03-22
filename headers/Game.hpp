#ifndef GAME_H
#define GAME_H

#include "DoubleLinkedList.hpp"
#include "CircularLinkedList.hpp"
#include "Piece.hpp"
#include <iostream> // std::cout, std::endl

class Game
{
private:
    DoubleLinkedList colorListRed, colorListYellow, colorListGreen, colorListBlue;          // Listes des couleurs
    DoubleLinkedList shapeListTriangle, shapeListDiamond, shapeListCircle, shapeListSquare; // Listes des formes
    CircularLinkedList board;                                                               // Plateau de jeu
    int score;

public:
    Game();
    void addPiece(Piece piece, bool insertAtHead); // Ajouter une pièce au plateau
    void shiftLeft();                              // Décaler les pièces vers la gauche sur le plateau
    void checkAndRemoveMatches();                  // Vérifier et supprimer les alignements de pièces
    void removePiecesByColor(Piece &matchedPiece, DoubleLinkedList &colorList);
    void removePiecesByShape(Piece &matchedPiece, DoubleLinkedList &shapeList);
    void displayBoard() const; // Afficher le plateau de jeu
    int getScore() const;      // Obtenir le score actuel
    void displayListsInfo() const;

private:
    void shiftByColor(); // Décalage par couleur
    void shiftByShape(); // Décalage par forme
};

#endif // GAME_H
