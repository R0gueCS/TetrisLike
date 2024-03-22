#include "../headers/Game.hpp"

Game::Game() : score(0) {}

void Game::addPiece(Piece piece, bool insertAtHead)
{
    switch (piece.getColor())
    {
    case Color::RED:
        if (insertAtHead)
            colorListRed.insertAtHead(piece);
        else
            colorListRed.insertAtTail(piece);
        break;
    case Color::YELLOW:
        if (insertAtHead)
            colorListYellow.insertAtHead(piece);
        else
            colorListYellow.insertAtTail(piece);
        break;
    case Color::GREEN:
        if (insertAtHead)
            colorListGreen.insertAtHead(piece);
        else
            colorListGreen.insertAtTail(piece);
        break;
    case Color::BLUE:
        if (insertAtHead)
            colorListBlue.insertAtHead(piece);
        else
            colorListBlue.insertAtTail(piece);
        break;
    }

    switch (piece.getShape())
    {
    case Shape::TRIANGLE:
        if (insertAtHead)
            shapeListTriangle.insertAtHead(piece);
        else
            shapeListTriangle.insertAtTail(piece);
        break;
    case Shape::DIAMOND:
        if (insertAtHead)
            shapeListDiamond.insertAtHead(piece);
        else
            shapeListDiamond.insertAtTail(piece);
        break;
    case Shape::CIRCLE:
        if (insertAtHead)
            shapeListCircle.insertAtHead(piece);
        else
            shapeListCircle.insertAtTail(piece);
        break;
    case Shape::SQUARE:
        if (insertAtHead)
            shapeListSquare.insertAtHead(piece);
        else
            shapeListSquare.insertAtTail(piece);
        break;
    }

    // Ajoute la pièce au plateau de jeu
    if (insertAtHead)
        board.insertAtHead(piece);
    else
        board.insertAtTail(piece);
}

void Game::shiftLeft()
{
    char choice;
    std::cout << "Do you want to shift by color or by shape? (c/s): ";
    std::cin >> choice;
    if (choice == 'c')
    {
        shiftByColor();
    }
    else if (choice == 's')
    {
        shiftByShape();
    }
    else
    {
        std::cout << "Invalid choice." << std::endl;
    }
}

void Game::removePiecesByColor(Piece &matchedPiece, DoubleLinkedList &colorList)
{
    colorList.remove(matchedPiece);
    colorList.remove(matchedPiece);
    colorList.remove(matchedPiece);
}

void Game::removePiecesByShape(Piece &matchedPiece, DoubleLinkedList &shapeList)
{
    shapeList.remove(matchedPiece);
    shapeList.remove(matchedPiece);
    shapeList.remove(matchedPiece);
}

void Game::checkAndRemoveMatches()
{
    CircularLinkedList::Node *current = board.head;
    CircularLinkedList::Node *next = current->next;
    CircularLinkedList::Node *next_next = next->next;

    while (next_next != current)
    {
        if (current->piece.getShape() == next->piece.getShape() &&
            current->piece.getShape() == next_next->piece.getShape())
        {
            // Si trois pièces consécutives ont la même forme
            Piece matchedPiece = current->piece;
            board.remove(current->piece);
            board.remove(next->piece);
            board.remove(next_next->piece);

            switch (matchedPiece.getShape())
            {
            case Shape::TRIANGLE:
                removePiecesByShape(matchedPiece, shapeListTriangle);
                break;
            case Shape::DIAMOND:
                removePiecesByShape(matchedPiece, shapeListDiamond);
                break;
            case Shape::CIRCLE:
                removePiecesByShape(matchedPiece, shapeListCircle);
                break;
            case Shape::SQUARE:
                removePiecesByShape(matchedPiece, shapeListSquare);
                break;
            }

            score += 3;
        }
        if (current->piece.getColor() == next->piece.getColor() &&
            current->piece.getColor() == next_next->piece.getColor())
        {
            // Si trois pièces consécutives ont la même couleur
            Piece matchedPiece = current->piece;
            board.remove(current->piece);
            board.remove(next->piece);
            board.remove(next_next->piece);

            switch (matchedPiece.getColor())
            {
            case Color::RED:
                removePiecesByColor(matchedPiece, colorListRed);
                break;
            case Color::YELLOW:
                removePiecesByColor(matchedPiece, colorListYellow);
                break;
            case Color::GREEN:
                removePiecesByColor(matchedPiece, colorListGreen);
                break;
            case Color::BLUE:
                removePiecesByColor(matchedPiece, colorListBlue);
                break;
            }

            score += 3;
        }
        current = next;
        next = next_next;
        next_next = next_next->next;
    }
}

void Game::displayBoard() const
{
    board.display();
}

int Game::getScore() const
{
    return score;
}

void Game::shiftByColor()
{
    char choice;
    std::cout << "Do you want to shift by red, yellow, green, or blue? (r/y/g/b): ";
    std::cin >> choice;
    DoubleLinkedList *colorList = nullptr;
    switch (choice)
    {
    case 'r':
        colorList = &colorListRed;
        break;
    case 'y':
        colorList = &colorListYellow;
        break;
    case 'g':
        colorList = &colorListGreen;
        break;
    case 'b':
        colorList = &colorListBlue;
        break;
    default:
        std::cout << "Invalid choice." << std::endl;
        return;
    }
    colorList->shiftLeft();
}

void Game::shiftByShape()
{
    char choice;
    std::cout << "Do you want to shift by triangle, diamond, circle, or square? (t/d/c/s): ";
    std::cin >> choice;
    DoubleLinkedList *shapeList = nullptr;
    switch (choice)
    {
    case 't':
        shapeList = &shapeListTriangle;
        break;
    case 'd':
        shapeList = &shapeListDiamond;
        break;
    case 'c':
        shapeList = &shapeListCircle;
        break;
    case 's':
        shapeList = &shapeListSquare;
        break;
    default:
        std::cout << "Invalid choice." << std::endl;
        return;
    }
    shapeList->shiftLeft();
}

void Game::displayListsInfo() const
{

    std::cout << "Liste CircularLinkedList :" << std::endl;
    board.display();

    std::cout << "Listes de pièces :" << std::endl;
    std::cout << "Listes DoubleLinkedList par couleur :" << std::endl;

    std::cout << "Rouge : ";
    colorListRed.display(); // Supposons que vous avez une méthode display() dans votre classe DoubleLinkedList
    std::cout << std::endl;

    std::cout << "Jaune : ";
    colorListYellow.display();
    std::cout << std::endl;

    std::cout << "Vert : ";
    colorListGreen.display();
    std::cout << std::endl;

    std::cout << "Bleu : ";
    colorListBlue.display();
    std::cout << std::endl;

    std::cout << "Listes DoubleLinkedList par forme :" << std::endl;

    std::cout << "Triangle : ";
    shapeListTriangle.display();
    std::cout << std::endl;

    std::cout << "Losange : ";
    shapeListDiamond.display();
    std::cout << std::endl;

    std::cout << "Cercle : ";
    shapeListCircle.display();
    std::cout << std::endl;

    std::cout << "Carré : ";
    shapeListSquare.display();
    std::cout << std::endl;
}