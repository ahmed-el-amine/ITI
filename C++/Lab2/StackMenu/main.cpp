#include <iostream>
#include <cstring>
#include <unistd.h>
#include "./components/menu/menu.cpp"
#include "./components/stack/stack.cpp"
#include "./lib/handleInputs.cpp"
using namespace std;

int main()
{
    setTextColor(TC_CYAN);
    printf("Enter Stack Size Between 1 And 1,000 [Numbers Only] : ");
    setTextColor(TC_WHITE);

   int StackSize = 0;
    
    while (StackSize <= 0 || StackSize > 1000)
    {
        Input::NUMBER_STATE state = Input::getNumber();

        if (!state.isNumber || state.Number <= 0 || state.Number > 1000)
        {
            setTextColor(TC_RED);
            printf("Please Enter Valid Number Between 1 And 1,000 \n");
            setTextColor(TC_WHITE);
        }
        else 
        {
            StackSize = state.Number;
        }
    }
 
    Stack st(StackSize);

    st.display();

    MenuItem item1("Add To Stack", MenuItem::OP_ADD_NEW_EMPLOYESS);
    MenuItem item2("POP From Stack", MenuItem::OP_POP_EMPLOYESS);
    MenuItem item3("Display Stack", MenuItem::OP_DISPLAY_EMPLOYESS);
    MenuItem item4("Exit", MenuItem::OP_SHOW_EXIT_CONFIRM);

    Menu menu(4, st);

    menu.addMenuItem(item1);
    menu.addMenuItem(item2);
    menu.addMenuItem(item3);
    menu.addMenuItem(item4);

    menu.displayMenu();

    return 0;
}