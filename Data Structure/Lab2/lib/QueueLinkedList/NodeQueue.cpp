#ifndef NODEQUEUE_C
#define NODEQUEUE_C

#include <iostream>

using namespace std;

class NodeQueue
{
public:
    int data;
    NodeQueue *next;
    NodeQueue(int data)
    {
        this->data = data;
        next = NULL;
    }
};

#endif