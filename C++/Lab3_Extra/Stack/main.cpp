#include <iostream>
#include "./MyStack.cpp"

using namespace std;

int main()
{

    MyStack a;
    MyStack b;

    a.Push(1);
    b.Push(2);

    a == b;
    a > b;
    a >= b;

    callByValue(a);
    callByRef(a);

    // cout << a.ElementAt(0);

    // --------------

    // MyStack b = a.getDeepCopy();

    // cout << a.getData()[0] << endl;
    // cout << b.getData()[0] << endl;

    // b.Push(1);
    // b.Push(2);

    // cout << a.getData()[0] << endl;
    // cout << b.getData()[0] << endl;

    // cout << ((a == b) ? "True" : "False");
    // cout << ((a > b) ? "True" : "False");
    // cout << ((a >= b) ? "True" : "False");
    // a + 5;

    // a.Insert(0, 3);
    // a.Insert(1, 4);
    // a.Insert(2, 6);
    // a.RemoveAt(1);
    // a.RemoveAt(1);

    // a.Push(1);
    // a.AddRange(new int[3]{10, 20, 30}, 3);
    // a.AddRange(new int[3]{10, 20, 30}, 3);
    // a.Push(2);
    // a.Insert(7, 5);
    // a.Push(3);
    // a.Push(4);
    // a.Push(4);
    // a.Push(4);
    // a.Push(4);
    // a.Push(4);
    // a.Push(5);
    // a.Push(6);
    // a.Push(7);
    // a.Pop();
    // a.Clear();

    // cout
    //     << "\n----------------------\n";
    // cout << "Length " << a.Count() << endl;
    // for (int i = 0; i < a.Count(); i++)
    // {
    //     cout << a.getData()[i] << endl;
    // }

    // int *i = new int[1];

    // i[0] = 10;

    // cout << i[0] << endl;

    // i = new int[2];

    // cout << i[0] << endl;

    return 0;
}