#include "../headers/CircularLinkedList.hpp"

CircularLinkedList::CircularLinkedList() : head(nullptr), tail(nullptr), size(0) {}

CircularLinkedList::~CircularLinkedList()
{
    if (head != nullptr)
    {
        Node *current = head->next;
        while (current != head)
        {
            Node *temp = current;
            current = current->next;
            delete temp;
        }
        delete head;
    }
}

void CircularLinkedList::insertAtHead(const Piece &piece)
{
    Node *newNode = new Node(piece);
    if (head == nullptr)
    {
        head = tail = newNode;
        head->next = head;
    }
    else
    {
        newNode->next = head;
        head = newNode;
        tail->next = head;
    }
    size++;
}

void CircularLinkedList::insertAtTail(const Piece &piece)
{
    Node *newNode = new Node(piece);
    if (head == nullptr)
    {
        head = tail = newNode;
        head->next = head;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
        tail->next = head;
    }
    size++;
}

void CircularLinkedList::remove(const Piece &pieceToRemove)
{
    if (isEmpty())
        return;

    Node *current = head;
    Node *previous = nullptr;

    do
    {
        if (current->piece == pieceToRemove)
        {
            // Le nœud courant contient la pièce à supprimer

            if (current == head && current == tail)
            {
                // Cas où il n'y a qu'un seul élément dans la liste
                head = nullptr;
                tail = nullptr;
            }
            else if (current == head)
            {
                // Cas où le nœud à supprimer est en tête de liste
                head = current->next;
                tail->next = head;
            }
            else if (current == tail)
            {
                // Cas où le nœud à supprimer est en fin de liste
                tail = previous;
                tail->next = head;
            }
            else
            {
                // Cas où le nœud à supprimer est au milieu de la liste
                previous->next = current->next;
            }

            // Libération de la mémoire occupée par le nœud supprimé
            delete current;
            size--;
            return;
        }

        // Passage au nœud suivant
        previous = current;
        current = current->next;

    } while (current != head);
}

void CircularLinkedList::shiftLeftByColor(Color color)
{
    if (head == nullptr) // Check if the list is empty
    {
        std::cout << "The list is empty." << std::endl;
        return;
    }

    Node *current = head;
    Node *firstPiece = nullptr;
    Node *firstPieceTemp = nullptr;
    Node *lastPiece = nullptr;

    // Find the first piece with the specified color
    while (current->next != head)
    {
        if (current->piece.getColor() == color)
        {
            firstPiece = current;
            break;
        }
        current = current->next;
    }

    firstPieceTemp = new Node(firstPiece->piece);
    std::cout << "First piece: " << firstPiece->piece.getShapeAsString() << " " << firstPiece->piece.getColorAsString() << std::endl; // Debugging

    // Find the last piece with the specified color

    current = head;
    while (current->next != head)
    {
        if (current->piece.getColor() == color)
        {
            lastPiece = current; // Update lastPiece when encountering a piece with the specified color
        }
        current = current->next;
    }

    std::cout << "Last piece: " << lastPiece->piece.getShapeAsString() << " " << lastPiece->piece.getColorAsString() << std::endl; // Debugging

    // If no piece with the specified color is found
    if (firstPiece == nullptr)
    {
        std::cout << "No piece with the specified color is found." << std::endl;
        return;
    }

    // Iterate through the list starting from the next piece after the first piece
    current = firstPiece->next;
    while (current != head)
    {
        if (current->piece.getColor() == color)
        {
            // Move the data of the current piece to the previous piece
            firstPiece->piece = current->piece;
            firstPiece = current;
        }
        current = current->next;
    }

    // Swap the data between the first and last pieces with the same color
    if (lastPiece != nullptr || firstPieceTemp != nullptr || lastPiece != firstPiece)
    {
        // Swap the shape
        Piece pieceTemp = firstPieceTemp->piece;
        firstPieceTemp->piece = lastPiece->piece;
        lastPiece->piece = pieceTemp;
    }
}

void CircularLinkedList::shiftLeftByShape(Shape shape)
{
    // if (head == nullptr) // Vérifier si la liste est vide
    // {
    //     std::cout << "La liste est vide." << std::endl;
    //     return;
    // }

    // Node *current = head;
    // do
    // {
    //     if (current->piece.getShape() == shape) // Vérifier si la pièce a la couleur spécifiée
    //     {
    //         current = current->next;
    //         continue; // Passer à l'itération suivante
    //     }

    //     current->piece.getShape();

    //     // Déplacer la pièce vers la gauche
    //     Node *temp = current;
    //     current = current->next;
    //     remove(temp->piece);       // Retirer la pièce actuelle
    //     insertAtTail(temp->piece); // Insérer la pièce à la fin
    // } while (current != head);     // Arrêter lorsque nous revenons à la tête
}

bool CircularLinkedList::isEmpty() const
{
    return head == nullptr;
}

void CircularLinkedList::display() const
{
    if (size == 0 || head == nullptr)
        return;

    Node *current = head;
    do
    {
        switch (current->piece.getColor())
        {
        case Color::RED:
            std::cout << "\033[31m" << current->piece.getShapeAsString() << "\033[0m " << std::flush;
            break;
        case Color::YELLOW:
            std::cout << "\033[33m" << current->piece.getShapeAsString() << "\033[0m " << std::flush;
            break;
        case Color::GREEN:
            std::cout << "\033[32m" << current->piece.getShapeAsString() << "\033[0m " << std::flush;
            break;
        case Color::BLUE:
            std::cout << "\033[34m" << current->piece.getShapeAsString() << "\033[0m " << std::flush;
            break;
        }
        // std::cout << "[ " << current->piece.getShapeAsString() << " | " << current->piece.getColorAsString() << " ] ";
        current = current->next;
    } while (current != head);
}

int CircularLinkedList::getSize() const
{
    return size;
}
