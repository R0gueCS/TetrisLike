#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include <iostream> // Pour std::cout et std::endl
#include "Piece.hpp"

class DoubleLinkedList
{
private:
    // Nouvel attribut pour conserver une référence à la queue
    int size;

public:
    struct Node
    {
        Piece piece;
        Node *next;
        Node *prev;
        Node(const Piece &piece) : piece(piece), next(nullptr), prev(nullptr) {}
    };
    Node *head;
    Node *tail;
    DoubleLinkedList();
    ~DoubleLinkedList();
    void insertAtHead(const Piece &piece);
    void insertAtTail(const Piece &piece);
    void remove(Piece &piece);
    void shiftLeft(); // Nouvelle méthode pour le décalage à gauche
    bool isEmpty() const;
    void display() const;
    int getSize() const;
};

#endif // DOUBLELINKEDLIST_H
