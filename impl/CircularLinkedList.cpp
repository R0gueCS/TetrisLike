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
        head = newNode;
        head->next = head;
        tail = head;
    }
    else
    {
        newNode->next = head->next;
        head->next = newNode;
        std::swap(head->piece, newNode->piece);
    }
    size++;
}

void CircularLinkedList::insertAtTail(const Piece &piece)
{
    Node *newNode = new Node(piece);
    if (head == nullptr)
    {
        head = newNode;
        head->next = head;
        tail = head;
    }
    else
    {
        newNode->next = head->next;
        head->next = newNode;
        tail = newNode;
    }
    size++;
}

void CircularLinkedList::remove(const Piece &piece)
{
    if (head == nullptr)
        return;

    Node *current = head;
    Node *previous = nullptr;

    do
    {
        if (current->piece == piece)
        {
            if (previous != nullptr)
            {
                previous->next = current->next;
            }
            else
            {
                head = current->next;
            }
            delete current;
            size--;
            return;
        }
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
    if (head == nullptr)
        return;

    Node *current = head;
    do
    {
        std::cout << "Shape: " << static_cast<int>(current->piece.getShape()) << ", Color: " << static_cast<int>(current->piece.getColor()) << std::endl;
        current = current->next;
    } while (current != head);
}

int CircularLinkedList::getSize() const
{
    return size;
}
