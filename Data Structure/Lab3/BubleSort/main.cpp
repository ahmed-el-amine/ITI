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
            cout << current->data << "\t";
            current = current->prev;
        }
        cout << endl;
    }

    /// @brief Bubble Sort the Linked List by swapping data
    void BubbleSort()
    {
        if (tail == NULL || tail->prev == NULL)
            return; // No need to sort if the list is empty or has one element

        bool swapped;

        do
        {
            swapped = false;
            StackNode<T> *current = tail;

            while (current->prev != NULL)
            {
                if (current->data < current->prev->data)
                {
                    swap(current->data, current->prev->data);
                    swapped = true;
                }
                current = current->prev;
            }

        } while (swapped);
    }
};

int main()
{
    StackLinkedList<int> list;

    // Add test data to the list
    list.Add(4);
    list.Add(1);
    list.Add(3);
    list.Add(5);
    list.Add(2);

    // Display the list before sorting
    cout << "Before Sort List:" << endl;
    list.Display();

    // Sort the list
    list.BubbleSort();

    // Display the list after sorting
    cout << "After Sort List:" << endl;
    list.Display();

    return 0;
}