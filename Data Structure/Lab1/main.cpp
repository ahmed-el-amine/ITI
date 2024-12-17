#include <iostream>
#include <string.h>
#include "./LinkedList.h"
#include <any>

using namespace std;

int main()
{
    LinkedList<string> l;
    l.add("Ahmed");
    l.add("Mohamed");
    l.add("Osama");

    l.display();
    l.remove("Ahmed");
    l.display();

    return 0;
}