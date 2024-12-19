#include <iostream>
#include "./lib/LinkedList.cpp"

#include <string.h>

using namespace std;

int main()
{
    LinkedList<int> list;

    cout << "Is List Empty " << (list.isEmpty() ? "[Yes Is Empty]" : "[No List Contains Data]") << endl;

    list.Add(1);
    list.Add(2);

    list.InsertAfter(3, 2);
    list.InsertBefore(1, 2);

    list.ForEach([](int element, int index)
                 { cout << "Index: " << index << ", Element: " << element << endl; });

    // list.Add(3);
    // list.Add(4); //
    // list.Add(5);
    // list.Add(6);

    // list.RemoveAt(3);
    // list.Remove();
    // try
    // {
    //     int deleteAt = 1;
    //     int data = list.ElementAt(deleteAt);

    //     cout << "Data At Element " << deleteAt << " = " << data << endl;
    // }
    // catch (const char *c)
    // {
    //     cout << "Error " << c << endl;
    // }

    // list.Remove();

    // cout << "List Count Is [" << list.Count() << "]" << endl;

    // cout << "Is List Empty " << (list.isEmpty() ? "[Yes Is Empty]" : "[No List Contains Data]") << endl;

    // list.Display();

    return 0;
}