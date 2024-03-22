#include <iostream>
#include "headers/Game.hpp"

void displayPieceInfo(const Piece &piece)
{
    std::cout << "La pièce à insérer est de forme " << piece.getShapeAsString() << " et de couleur " << piece.getColorAsString() << std::endl;
}

int main()
{
    Game game;

    char choice;
    do
    {
        std::cout << "==== Tetris-like Game ====" << std::endl;
        std::cout << "Listes de pièces :" << std::endl;
        game.displayListsInfo();
        std::cout << "Informations sur la pièce actuelle :" << std::endl;
        displayPieceInfo(Piece::generateRandomPiece());
        std::cout << "1. Ajouter une pièce à gauche" << std::endl;
        std::cout << "2. Ajouter une pièce à droite" << std::endl;
        std::cout << "3. Décaler les pièces à gauche" << std::endl;
        std::cout << "4. Vérifier et supprimer les alignements de pièces" << std::endl;
        std::cout << "5. Afficher le plateau de jeu" << std::endl;
        std::cout << "6. Afficher le score" << std::endl;
        std::cout << "7. Quitter" << std::endl;
        std::cout << "Choix : ";
        std::cin >> choice;

        switch (choice)
        {
        case '1':
        {
            std::cout << "Ajouter une pièce à gauche" << std::endl;
            Piece newPiece = Piece::generateRandomPiece();
            displayPieceInfo(newPiece);
            game.addPiece(newPiece, true);
            break;
        }
        case '2':
        {
            std::cout << "Ajouter une pièce à droite" << std::endl;
            Piece newPiece = Piece::generateRandomPiece();
            displayPieceInfo(newPiece);
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
            std::cout << "Vérifier et supprimer les alignements de pièces" << std::endl;
            game.checkAndRemoveMatches();
            break;
        }
        case '5':
        {
            std::cout << "Plateau de jeu :" << std::endl;
            game.displayBoard();
            break;
        }
        case '6':
        {
            std::cout << "Score : " << game.getScore() << std::endl;
            break;
        }
        case '7':
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
    } while (choice != '7');

    return 0;
}
