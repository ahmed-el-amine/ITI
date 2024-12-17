#ifndef NODE_H
#define NODE_H

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
        this->next = nullptr;
        this->prev = nullptr;
    }
};

#endif