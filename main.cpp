#include <iostream>
#include "headers/Game.hpp"

void displayPieceInfo(const Piece &piece)
{
    switch (piece.getColor())
    {
    case Color::RED:
        std::cout << "\033[31m" << piece.getShapeAsString() << "\033[0m " << std::flush;
        break;
    case Color::YELLOW:
        std::cout << "\033[33m" << piece.getShapeAsString() << "\033[0m " << std::flush;
        break;
    case Color::GREEN:
        std::cout << "\033[32m" << piece.getShapeAsString() << "\033[0m " << std::flush;
        break;
    case Color::BLUE:
        std::cout << "\033[34m" << piece.getShapeAsString() << "\033[0m " << std::flush;
        break;
    }
}

int main()
{
    Game game;

    char choice;
    do
    {
        std::cout << "==== Tetris-like Game ====" << std::endl;
        std::cout << "Score : " << game.getScore() << std::endl;
        std::cout << "Informations sur la pièce actuelle :" << std::endl;
        Piece newPiece = Piece::generateRandomPiece();
        displayPieceInfo(newPiece);
        std::cout << std::endl;
        game.displayListsInfo();
        std::cout << "1. Ajouter une pièce à gauche" << std::endl;
        std::cout << "2. Ajouter une pièce à droite" << std::endl;
        std::cout << "3. Décaler les pièces à gauche" << std::endl;
        std::cout << "4. Quitter" << std::endl;
        std::cout << "Choix : ";
        std::cin >> choice;

        switch (choice)
        {
        case '1':
        {
            std::cout << "Ajouter une pièce à gauche" << std::endl;
            game.addPiece(newPiece, true);

            break;
        }
        case '2':
        {
            std::cout << "Ajouter une pièce à droite" << std::endl;
            game.addPiece(newPiece, false);

            break;
        }
        case '3':
        {
            std::cout << "Décaler les pièces à gauche" << std::endl;
            game.shiftLeft();
            break;
        }
        case '4':
        {
            std::cout << "Au revoir !" << std::endl;
            return 0;
        }
        default:
        {
            std::cout << "Choix invalide. Veuillez saisir un choix valide." << std::endl;
            break;
        }
        }
        game.checkAndRemoveMatches();

    } while (choice != '4');

    return 0;
}
