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
    if (head == nullptr)
        return;

    Node *current = head;
    do
    {
        if (current->piece == piece)
        {
            current->prev->next = current->next;
            current->next->prev = current->prev;
            if (current == head)
                head = current->next;
            if (current == tail)
                tail = current->prev;
            delete current;
            size--;
            return;
        }
        current = current->next;
    } while (current != head);
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
    if (head == nullptr)
        return;

    Node *current = head;
    do
    {
        std::cout << "Shape: " << static_cast<int>(current->piece.getShape()) << ", Color: " << static_cast<int>(current->piece.getColor()) << std::endl;
        current = current->next;
    } while (current != head);
}

int DoubleLinkedList::getSize() const
{
    return size;
}
