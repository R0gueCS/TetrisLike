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
