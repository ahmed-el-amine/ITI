#ifndef STACKLINKEDLIST_C
#define STACKLINKEDLIST_C

#include <iostream>
#include "./StackNode.cpp"

using namespace std;

template <class T>
class StackLinkedList
{
    StackNode<T> *tail;

public:
    StackLinkedList()
    {
        tail = NULL;
    }

    void Add(T data)
    {
        StackNode<T> *newNode = new StackNode<T>(data);

        if (tail == NULL)
        {
            tail = newNode;
            return;
        }

        newNode->prev = tail;
        tail = newNode;
    }

    /// @brief Remove Last Element Return Removed Data
    /// @return
    T Remove()
    {
        if (tail == NULL)
            throw "No Data In List";

        StackNode<T> *tempTail = tail;

        tail = tail->prev;

        T data = tempTail->data;

        delete tempTail;

        return data;
    }

    /// @brief Return Last Element In List
    /// @return
    T Peek()
    {
        if (tail == NULL)
        {
            throw "No Data In List";
        }
        return tail->data;
    }

    void Display()
    {
        StackNode<T> *current = tail;

        while (current != NULL)
        {
            cout << current->data << endl;
            current = current->prev;
        }
    }
};

#endif