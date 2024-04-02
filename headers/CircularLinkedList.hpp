#ifndef CIRCULARLINKEDLIST_H
#define CIRCULARLINKEDLIST_H

#include <iostream> // std::cout, std::endl
#include "Piece.hpp"

class CircularLinkedList
{
private:
    int size;

public:
    struct Node
    {
        Piece piece;
        Node *next;
        Node(const Piece &piece) : piece(piece), next(nullptr) {}
    };
    Node *head;
    Node *tail; // Pointeur vers le dernier nœud
    CircularLinkedList();
    ~CircularLinkedList();
    void insertAtHead(const Piece &piece);
    void insertAtTail(const Piece &piece);
    void remove(const Piece &piece); // Modifier la signature de la fonction remove
    void shiftLeftByColor(Color color);
    void shiftLeftByShape(Shape shape);
    bool isEmpty() const;
    void display() const;
    int getSize() const;
};

#endif // CIRCULARLINKEDLIST_H
