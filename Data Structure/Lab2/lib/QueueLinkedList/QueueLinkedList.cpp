#ifndef QUEUELINKEDLIST_C
#define QUEUELINKEDLIST_C

#include <iostream>
#include "./NodeQueue.cpp"

using namespace std;

class QueueLinkedList
{
    NodeQueue *front;
    NodeQueue *rear;

public:
    QueueLinkedList()
    {
        rear = front = NULL;
    }

    void enQueue(int data)
    {
        NodeQueue *newNode = new NodeQueue(data);

        if (front == NULL && rear == NULL)
        {
            front = rear = newNode;
            return;
        }

        rear->next = newNode;
        rear = newNode;
    }

    int deQueue()
    {
        int data;
        if (front == NULL)
        {
            throw "Queue is Empty";
        }
        NodeQueue *tempQ = front;
        data = front->data;
        front = front->next;
        if (front == NULL)
        {
            rear == NULL;
        }

        delete tempQ;

        return data;
    }

    int GetFront()
    {
        if (front == NULL)
        {
            throw "Queue is Empty";
        }
        return front->data;
    }

    int GetRear()
    {
        if (rear == NULL)
        {
            throw "Queue is Empty";
        }
        return rear->data;
    }

    void Display()
    {
        NodeQueue *current = front;

        while (current != NULL)
        {
            cout << current->data << "\t";
            current = current->next;
        }
    }
};

#endif