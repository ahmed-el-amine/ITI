#ifndef LinkedList_H
#define LinkedList_H

#include <iostream>
#include "Node.cpp"

using namespace std;

template <class T>
class LinkedList
{
private:
    Node<T> *head;
    Node<T> *tail;
    T maxIndex;

public:
    LinkedList() : head(NULL), tail(NULL), maxIndex(-1) {}

    /// @brief Add data to the end of list
    /// @param data
    void Add(T data)
    {
        Node<T> *newNode = new Node<T>(data);
        maxIndex++;
        if (isEmpty())
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    /// @brief Insert a new node after the first occurrence of afterData
    void InsertAfter(T newData, T afterData)
    {
        Node<T> *current = head;
        while (current != NULL)
        {
            if (current->data == afterData)
            {
                Node<T> *newNode = new Node<T>(newData);
                newNode->next = current->next;
                newNode->prev = current;

                if (current->next != NULL)
                    current->next->prev = newNode;
                else
                    tail = newNode;

                current->next = newNode;
                maxIndex++;
                return;
            }
            current = current->next;
        }

        throw "Element not found";
    }

    /// @brief Insert a new node before the first occurrence of beforeData
    void InsertBefore(T newData, T beforeData)
    {
        Node<T> *current = head;
        while (current != NULL)
        {
            if (current->data == beforeData)
            {
                Node<T> *newNode = new Node<T>(newData);
                newNode->next = current;
                newNode->prev = current->prev;

                if (current->prev != NULL)
                    current->prev->next = newNode;
                else
                    head = newNode;

                current->prev = newNode;
                maxIndex++;
                return;
            }
            current = current->next;
        }
        throw "Element not found";
    }

    /// @brief remove last element from list
    void Remove()
    {
        if (isEmpty())
            return;

        maxIndex--;
        // if this element is last element is the list
        if (head == tail)
        {
            delete head;
            head = NULL;
            tail = NULL;
        }
        // if there is more elements
        else
        {
            Node<T> *tempTail = tail;

            tail = tail->prev;
            tail->next = NULL;

            delete tempTail;
        }
    }

    /// @brief this method takes index and then return value at this index
    /// @param index
    /// @return return data at selected index or throw Out Of Range Exception
    T ElementAt(int index)
    {
        // if list is empty
        if (isEmpty() || index > maxIndex)
            throw "Out Of Range";

        Node<T> *tempHead = head;
        T cureentIndex = -1;
        while (tempHead != NULL)
        {
            cureentIndex++;
            if (index == cureentIndex)
            {
                return tempHead->data;
            }
            tempHead = tempHead->next;
        }

        throw "Unexpected Error";
    }

    /// @brief this method remove data at index Throw Error Out Of Range is index not exist
    /// @param index
    void RemoveAt(int index)
    {
        // if list is empty
        if (isEmpty() || index > maxIndex)
            throw "Out Of Range";

        // if index == 0 remove first element
        if (index == 0)
        {
            Node<T> *firstElement = head;

            head = head->next;
            head->prev = NULL;

            delete firstElement;
        }
        // if index == Count() - 1 remove last element
        else if (index == (Count() - 1))
        {
            Node<T> *lastElement = tail;

            tail = tail->prev;
            tail->next = NULL;

            delete lastElement;
        }
        // has prev element and next element
        // then loop throw all elements and get selected one
        else
        {
            Node<T> *curentElement = head;
            int cureentIndex = -1;
            while (curentElement != NULL)
            {
                cureentIndex++;
                if (index == cureentIndex)
                {
                    Node<T> *prevElement = curentElement->prev;
                    Node<T> *nextElement = curentElement->next;

                    prevElement->next = nextElement;
                    nextElement->prev = prevElement;

                    delete curentElement;
                    // stop the loop
                    curentElement = NULL;
                }
                else
                {
                    curentElement = curentElement->next;
                }
            }
        }

        maxIndex--;
    }

    /// @brief Executes a callback function for each element in the list.
    /// @param callback A function that takes a single parameter of type T.
    void ForEach(void (*callback)(T))
    {
        Node<T> *current = head;
        while (current != NULL)
        {
            callback(current->data);
            current = current->next;
        }
    }

    /// @brief Executes a callback function for each element and its index in the list.
    /// @param callback A function that takes two parameters: the element (T) and its index (int).
    void ForEach(void (*callback)(T, int))
    {
        Node<T> *current = head;
        int index = 0;
        while (current != NULL)
        {
            callback(current->data, index);
            current = current->next;
            index++;
        }
    }

    /// @brief Display All Elements
    void Display()
    {
        Node<T> *tempHead = head;

        while (tempHead != NULL)
        {
            cout << tempHead->data << endl;
            tempHead = tempHead->next;
        }
    }

    /// @brief return the cout of elements in the list
    int Count()
    {
        return (maxIndex + 1);
    }

    /// @brief return 1 if empty and 0 if has data
    int isEmpty()
    {
        return (head == NULL ? 1 : 0);
    }
};

#endif