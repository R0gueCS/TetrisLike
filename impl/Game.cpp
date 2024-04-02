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
}

void Game::removePiecesByShape(Piece &matchedPiece, DoubleLinkedList &shapeList)
{
    shapeList.remove(matchedPiece);
}

void Game::checkAndRemoveMatches()
{
    // Obtenir la tête de la liste circulaire
    CircularLinkedList::Node *current = board.head;

    // Parcourir la liste circulaire
    do
    {
        // Obtenir les trois pièces consécutives
        CircularLinkedList::Node *next = current->next;   // 2nd piece
        CircularLinkedList::Node *next_next = next->next; // 3rd piece

        if (next_next == nullptr || next_next == board.head)
        {
            return;
        }

        // Vérifier si les trois pièces ont le même couleur
        if ((current->piece.getColorAsString() == next->piece.getColorAsString() &&
             next->piece.getColorAsString() == next_next->piece.getColorAsString()))
        {

            switch (current->piece.getColor())
            {
            case Color::RED:
                removePiecesByColor(current->piece, colorListRed);
                removePiecesByColor(next->piece, colorListRed);
                removePiecesByColor(next_next->piece, colorListRed);
                break;
            case Color::YELLOW:
                removePiecesByColor(current->piece, colorListYellow);
                removePiecesByColor(next->piece, colorListYellow);
                removePiecesByColor(next_next->piece, colorListYellow);
                break;
            case Color::GREEN:
                removePiecesByColor(current->piece, colorListGreen);
                removePiecesByColor(next->piece, colorListGreen);
                removePiecesByColor(next_next->piece, colorListGreen);
                break;
            case Color::BLUE:
                removePiecesByColor(current->piece, colorListBlue);
                removePiecesByColor(next->piece, colorListBlue);
                removePiecesByColor(next_next->piece, colorListBlue);
                break;
            }

            switch (current->piece.getShape())
            {
            case Shape::TRIANGLE:
                removePiecesByShape(current->piece, shapeListTriangle);
                break;
            case Shape::DIAMOND:
                removePiecesByShape(current->piece, shapeListDiamond);
                break;
            case Shape::CIRCLE:
                removePiecesByShape(current->piece, shapeListCircle);
                break;
            case Shape::SQUARE:
                removePiecesByShape(current->piece, shapeListSquare);
                break;
            }

            switch (next->piece.getShape())
            {
            case Shape::TRIANGLE:
                removePiecesByShape(next->piece, shapeListTriangle);
                break;
            case Shape::DIAMOND:
                removePiecesByShape(next->piece, shapeListDiamond);
                break;
            case Shape::CIRCLE:
                removePiecesByShape(next->piece, shapeListCircle);
                break;
            case Shape::SQUARE:
                removePiecesByShape(next->piece, shapeListSquare);
                break;
            }

            switch (next_next->piece.getShape())
            {
            case Shape::TRIANGLE:
                removePiecesByShape(next_next->piece, shapeListTriangle);
                break;
            case Shape::DIAMOND:
                removePiecesByShape(next_next->piece, shapeListDiamond);
                break;
            case Shape::CIRCLE:
                removePiecesByShape(next_next->piece, shapeListCircle);
                break;
            case Shape::SQUARE:
                removePiecesByShape(next_next->piece, shapeListSquare);
                break;
            }

            // Supprimer les trois pièces de la liste circulaire
            board.remove(current->piece);
            board.remove(next->piece);
            board.remove(next_next->piece);

            // Incrémenter le score
            score += 3;

            return;
        }

        // Vérifier si les trois pièces ont  la même forme
        if ((current->piece.getShapeAsString() == next->piece.getShapeAsString() &&
             next->piece.getShapeAsString() == next_next->piece.getShapeAsString()))
        {
            switch (current->piece.getShape())
            {
            case Shape::TRIANGLE:
                removePiecesByShape(current->piece, shapeListTriangle);
                removePiecesByShape(next->piece, shapeListTriangle);
                removePiecesByShape(next_next->piece, shapeListTriangle);
                break;
            case Shape::DIAMOND:
                removePiecesByShape(current->piece, shapeListDiamond);
                removePiecesByShape(next->piece, shapeListDiamond);
                removePiecesByShape(next_next->piece, shapeListDiamond);
                break;
            case Shape::CIRCLE:
                removePiecesByShape(current->piece, shapeListCircle);
                removePiecesByShape(next->piece, shapeListCircle);
                removePiecesByShape(next_next->piece, shapeListCircle);
                break;
            case Shape::SQUARE:
                removePiecesByShape(current->piece, shapeListSquare);
                removePiecesByShape(next->piece, shapeListSquare);
                removePiecesByShape(next_next->piece, shapeListSquare);
                break;
            }

            switch (current->piece.getColor())
            {
            case Color::RED:
                removePiecesByColor(current->piece, colorListRed);
                break;
            case Color::YELLOW:
                removePiecesByColor(current->piece, colorListYellow);
                break;
            case Color::GREEN:
                removePiecesByColor(current->piece, colorListGreen);
                break;
            case Color::BLUE:
                removePiecesByColor(current->piece, colorListBlue);
                break;
            }

            switch (next->piece.getColor())
            {
            case Color::RED:
                removePiecesByColor(next->piece, colorListRed);
                break;
            case Color::YELLOW:
                removePiecesByColor(next->piece, colorListYellow);
                break;
            case Color::GREEN:
                removePiecesByColor(next->piece, colorListGreen);
                break;
            case Color::BLUE:
                removePiecesByColor(next->piece, colorListBlue);
                break;
            }

            switch (next_next->piece.getColor())
            {
            case Color::RED:
                removePiecesByColor(next_next->piece, colorListRed);
                break;
            case Color::YELLOW:
                removePiecesByColor(next_next->piece, colorListYellow);
                break;
            case Color::GREEN:
                removePiecesByColor(next_next->piece, colorListGreen);
                break;
            case Color::BLUE:
                removePiecesByColor(next_next->piece, colorListBlue);
                break;
            }

            // Supprimer les trois pièces de la liste circulaire
            board.remove(current->piece);
            board.remove(next->piece);
            board.remove(next_next->piece);

            // Incrémenter le score
            score += 3;

            return;
        }

        current = current->next; // Passer à la pièce suivante

    } while (current != board.head); // Boucler jusqu'à ce que nous revenions à la tête de la liste circulaire
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
    Color color;

    switch (choice)
    {
    case 'r':
        colorList = &colorListRed;
        color = Color::RED;
        break;
    case 'y':
        colorList = &colorListYellow;
        color = Color::YELLOW;
        break;
    case 'g':
        colorList = &colorListGreen;
        color = Color::GREEN;
        break;
    case 'b':
        colorList = &colorListBlue;
        color = Color::BLUE;
        break;
    default:
        std::cout << "Invalid choice." << std::endl;
        return;
    }

    colorList->shiftLeft();
    board.shiftLeftByColor(color);
}

void Game::shiftByShape()
{
    char choice;
    std::cout << "Do you want to shift by triangle, diamond, circle, or square? (t/d/c/s): ";
    std::cin >> choice;
    DoubleLinkedList *shapeList = nullptr;
    Shape shape;

    switch (choice)
    {
    case 't':
        shapeList = &shapeListTriangle;
        shape = Shape::TRIANGLE;
        break;
    case 'd':
        shapeList = &shapeListDiamond;
        shape = Shape::DIAMOND;
        break;
    case 'c':
        shapeList = &shapeListCircle;
        shape = Shape::CIRCLE;
        break;
    case 's':
        shapeList = &shapeListSquare;
        shape = Shape::SQUARE;
        break;
    default:
        std::cout << "Invalid choice." << std::endl;
        return;
    }

    shapeList->shiftLeft();
    board.shiftLeftByShape(shape);
}

void Game::displayListsInfo() const
{

    std::cout << "Plateau :" << std::endl;
    board.display();

    std::cout << std::endl;

    std::cout << "---------------------Couleur--------------------------" << std::endl;

    std::cout << "\033[31mRouge: \033[0m";
    colorListRed.display(); // Supposons que vous avez une méthode display() dans votre classe DoubleLinkedList
    std::cout << std::endl;

    std::cout << "\033[33mJaune: \033[0m";
    colorListYellow.display();
    std::cout << std::endl;

    std::cout << "\033[32mVert: \033[0m";
    colorListGreen.display();
    std::cout << std::endl;

    std::cout << "\033[34mBleu: \033[0m";
    colorListBlue.display();
    std::cout << std::endl;

    std::cout << "-----------------------Forme------------------------" << std::endl;

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