#ifndef NODE_H
#define NODE_H

#include <iostream>

template <class T>
class Node
{
public:
    T data;
    Node *next;
    Node *prev;

    Node(T data)
    {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

#endif