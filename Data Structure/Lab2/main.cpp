#include <iostream>

using namespace std;

#include "./lib/StackLinkedList/StackLinkedList.cpp"
#include "./lib/QueueLinkedList/QueueLinkedList.cpp"

int main()
{
    StackLinkedList<int> sLick;

    sLick.Add(1);
    sLick.Add(2);
    sLick.Add(3);
    sLick.Display();
    try
    {
        sLick.Remove();
        sLick.Remove();
        sLick.Remove();
    }
    catch (const char *c)
    {
        cout << c;
    }
    sLick.Display();

    QueueLinkedList qLick;

    qLick.enQueue(10);
    qLick.enQueue(20);
    qLick.enQueue(30);

    qLick.deQueue();

    qLick.Display();

    return 0;
}