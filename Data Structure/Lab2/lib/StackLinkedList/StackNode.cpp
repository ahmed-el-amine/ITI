#ifndef STACKNODE_C
#define STACKNODE_C

#include <iostream>

using namespace std;

template <class T>
class StackNode
{
public:
    T data;
    StackNode<T> *prev;
    StackNode(T data)
    {
        this->data = data;
        prev = NULL;
    }
};

#endif