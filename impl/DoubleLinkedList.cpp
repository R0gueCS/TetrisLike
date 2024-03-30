#include "../headers/DoubleLinkedList.hpp"

DoubleLinkedList::DoubleLinkedList() : head(nullptr), tail(nullptr), size(0) {}

DoubleLinkedList::~DoubleLinkedList()
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

void DoubleLinkedList::insertAtHead(const Piece &piece)
{
    Node *newNode = new Node(piece);

    if (head == nullptr)
    {
        head = newNode;
        tail = newNode; // La queue pointe également vers le nouveau nœud
        head->next = head;
        head->prev = head;
    }
    else
    {
        newNode->next = head;
        newNode->prev = head->prev;
        head->prev->next = newNode;
        head->prev = newNode;
        head = newNode;
    }
    size++;
}

void DoubleLinkedList::insertAtTail(const Piece &piece)
{
    Node *newNode = new Node(piece);
    if (head == nullptr)
    {
        head = newNode;
        tail = newNode; // La queue pointe également vers le nouveau nœud
        head->next = head;
        head->prev = head;
    }
    else
    {
        newNode->next = head;
        newNode->prev = head->prev;
        head->prev->next = newNode;
        head->prev = newNode;
        tail = newNode; // Met à jour la queue pour pointer vers le nouveau nœud
    }
    size++;
}

void DoubleLinkedList::remove(Piece &piece)
{
    if (isEmpty())
    {
        std::cout << "List is empty. Nothing to remove." << std::endl;
        return;
    }

    Node *current = head;

    bool found = false;

    // Parcours de la liste pour trouver le nœud contenant la pièce à supprimer
    while (current != nullptr)
    {
        if (current->piece == piece) // Si la pièce est trouvée
        {
            found = true;
            break;
        }
        current = current->next;
    }

    if (!found) // Si la pièce n'est pas trouvée dans la liste
    {
        return;
    }

    // Si le nœud à supprimer est la tête de la liste
    if (current == head)
    {
        if (head->next == head)
        { // Cas où il n'y a qu'un seul élément dans la liste
            delete current;
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            head = head->next;
            head->prev = tail;
            tail->next = head;
            delete current;
        }
    }
    else if (current == tail)
    { // Si le nœud à supprimer est la queue de la liste
        tail = tail->prev;
        tail->next = head;
        head->prev = tail;
        delete current;
    }
    else
    { // Si le nœud à supprimer est au milieu de la liste
        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
    }

    size--; // Décrémentation de la taille de la liste
}

void DoubleLinkedList::shiftLeft()
{
    if (head == nullptr || head->next == head)
        return;

    Node *courant = head;
    Piece temp = head->piece;
    while (courant->next != head)
    {
        courant->piece = courant->next->piece;
        courant = courant->next;
    }

    tail->piece = temp;
}

bool DoubleLinkedList::isEmpty() const
{
    return head == nullptr;
}

void DoubleLinkedList::display() const
{
    if (size == 0 || head == nullptr)
        return;

    Node *current = head;
    do
    {
        std::cout << "[ " << current->piece.getShapeAsString() << " | " << current->piece.getColorAsString() << " ] ";
        current = current->next;
    } while (current != head);
}

int DoubleLinkedList::getSize() const
{
    return size;
}
