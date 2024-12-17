#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include "./Node.h"

using namespace std;

template <class T>
class LinkedList
{
private:
    Node<T> *head;
    Node<T> *tail;

public:
    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    void add(T data)
    {
        Node<T> *newNode = new Node(data);

        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
            return;
        }

        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    void remove(T data)
    {
        Node *res = getNodeUsingData(data);
        if (res == nullptr)
        {
            return 0;
        }
        if (res == head)
        {
            if (res == tail)
            {
                head = tail = nullptr;
            }
            else
            {
                head = head->next;
                head->prev = nullptr;
            }
        }
        else if (res == tail)
        {
            tail = tail->prev;
            tail->next = nullptr;
        }
        else
        {
            Node *A = res->prev;
            Node *B = res->next;
            A->next = B;
            B->prev = A;
        }
        delete res;
    }

    void display()
    {
        Node<T> *current = head;
        if (current == nullptr)
        {
            cout << "List Is Empty";
            return;
        }

        while (current != nullptr)
        {
            cout << current->data << "\t";
            current = current->next;
        }
        cout << endl;
    }
    ~LinkedList()
    {
    }

private:
    Node<T> getNodeUsingData(T data)
    {
        Node<T> *current = head;
        if (current == nullptr)
        {
            return nullptr;
        }

        while (current != nullptr)
        {
            if (current->data == data)
            {
                return current;
            }
        }
        return nullptr;
    }
};

#endif