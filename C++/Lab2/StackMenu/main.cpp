#include <iostream>
#include <cstring>
#include <unistd.h>
#include "./components/menu/menu.cpp"
#include "./components/stack/stack.cpp"

using namespace std;

int main()
{
    int StackSize = 0;
     while (StackSize <= 0)
    {
        setTextColor(TC_CYAN);
        printf("Enter Stack Size [Numbers Only] : ");
        setTextColor(TC_WHITE);

        char buffer[256];
        fgets(buffer, 256, stdin);
        StackSize = atoi(buffer);

        if (StackSize <= 0)
        {
            setTextColor(TC_RED);
            printf("Please Enter Valid Number \n");
            setTextColor(TC_WHITE);
        }
    }

    Stack st(StackSize);

    // st.push(createNewEmployee());
    // st.push(Employee(1, "Ahmed Mohamed"));

    st.display();

    MenuItem item1("Add To Stack", MenuItem::OP_ADD_NEW_EMPLOYESS);
    MenuItem item2("POP From Stack", MenuItem::OP_POP_EMPLOYESS);
    MenuItem item3("Display Stack", MenuItem::OP_DISPLAY_EMPLOYESS);
    MenuItem item4("Exit", MenuItem::OP_EXIT);

    Menu menu(4, st);

    menu.addMenuItem(item1);
    menu.addMenuItem(item2);
    menu.addMenuItem(item3);
    menu.addMenuItem(item4);

    menu.displayMenu();

    return 0;
}