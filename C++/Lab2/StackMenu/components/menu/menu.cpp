#include <iostream>
#include <cstring>
#include "../stack/stack.cpp"
#include "../../lib/defines.h"
#include "../../lib/consoleColor.cpp"
#include "../../lib/handleInputs.h"

using namespace std;

class MenuItem
{
public:
    enum MenuItemActions
    {
        OP_DO_NOTING = 0,
        OP_EXIT,
        OP_SHOW_EXIT_CONFIRM,
        OP_ADD_NEW_EMPLOYESS,
        OP_POP_EMPLOYESS,
        OP_DISPLAY_EMPLOYESS,
        OP_EDIT_EMPLOYESS,
    };

private:
    char *menuText;
    MenuItemActions action;

public:
    MenuItem() {};
    MenuItem(const char *text, MenuItemActions action = MenuItemActions::OP_DO_NOTING)
    {
        this->menuText = new char[strlen(text) + 1];
        this->action = action;
        strcpy(this->menuText, text);
    }

    char *getText()
    {
        return this->menuText;
    }

    MenuItemActions getActionType()
    {
        return this->action;
    }

    // ~MenuItem()
    // {
    //     delete[] menuText;
    // }
};

class Menu
{
private:
    int MenuSize;
    int MenuIndex;
    int FocusItemIndex;
    char IsPressEnter;
    MenuItem *menuItems;
    Stack *stack;

public:
    Menu(int MenuSize, Stack &stack)
    {
        this->menuItems = new MenuItem[MenuSize];
        this->MenuSize = MenuSize;
        this->MenuIndex = -1;
        this->FocusItemIndex = 1;
        this->IsPressEnter = 0;
        this->stack = &stack;
    }

    // addItem
    void addMenuItem(MenuItem menuItem)
    {
        if (this->MenuIndex >= this->MenuSize - 1)
            return;

        this->MenuIndex++;
        this->menuItems[this->MenuIndex] = menuItem;
    }

    // getMenuSize
    int getMenuSize()
    {
        return this->MenuIndex + 1;
    }

    // getMenuItems
    MenuItem *getMenuItems()
    {
        return this->menuItems;
    }

    // displayMenu
    void displayMenu()
    {
        this->printMenu();
        this->watchMenuControls_Void();
    }

    ~Menu()
    {
        delete[] menuItems;
    }

private:
    // printMenu
    void printMenu()
    {
        clearConsole();
        setTextColor(TC_WHITE);

        if (this->IsPressEnter)
        {
            this->handleMenuActions_Void();
        }
        else
        {
            for (int i = 0; i < this->getMenuSize(); i++)
            {
                MenuItem item = this->menuItems[i];

                if (this->FocusItemIndex == (i + 1))
                {
                    setTextColor(TC_CYAN);
                    cout << "➤ " << item.getText();
                }
                else
                {
                    setTextColor(TC_WHITE);
                    cout << item.getText();
                }

                cout << endl;
            }
        }

        setTextColor(TC_WHITE);
    }
    // watchMenuControls
    void watchMenuControls_Void()
    {
        char isRunning = 1;

        while (isRunning)
        {
            char keyChar = getKey_Char();

            switch (keyChar)
            {
                // Handling Change Selection Key
            case KEY_UP:
            case KEY_LEFT:
                this->FocusItemIndex = (this->FocusItemIndex <= 1 ? (this->getMenuSize()) : (this->FocusItemIndex - 1));
                break;
            case KEY_DOWN:
            case KEY_RIGHT:
                this->FocusItemIndex = (this->FocusItemIndex >= this->getMenuSize() ? 1 : (this->FocusItemIndex + 1));
                break;
            case KEY_HOME:
                this->FocusItemIndex = 1;
                break;
            case KEY_END:
                this->FocusItemIndex = this->getMenuSize();
                break;
                // Handling The Enter Key
            case KEY_ENTER:
                this->IsPressEnter = 1;
                break;
                // Handling Exit Or Back Key
            case KEY_Q:
            case KEY_ESC:
                if (this->IsPressEnter)
                {
                    this->IsPressEnter = 0;
                    break;
                }
                else
                {
                    // if (confirmExit > 0)
                    // {
                    //     confirmExitMessageMenu_Void();
                    // }
                    return;
                }
            }

            this->printMenu();
        }
    }

    // handleMenuActions
    void handleMenuActions_Void()
    {
        MenuItem item = this->menuItems[this->FocusItemIndex - 1];

        switch (item.getActionType())
        {
        case MenuItem::OP_ADD_NEW_EMPLOYESS:
        {
            if (this->stack->getStackSize() != this->stack->getStackLimit())
            {
                Employee emp = createNewEmployee();
                Stack::PUSH_STATUS status = this->stack->push(emp);
                if (status.STATE)
                {
                    setTextColor(TC_LIGHTCYAN);
                    cout << "This New Emp [" << status.PUSH_DATA.getID()  << "][" << status.PUSH_DATA.getName() << "] Was Added" << endl;
                    setTextColor(TC_WHITE);
                }
                else
                {
                    setTextColor(TC_LIGHTRED);
                    cout << "You have reached the maximum limit for adding more" << endl;
                    setTextColor(TC_WHITE);
                }
            }
            else
            {
                setTextColor(TC_LIGHTRED);
                cout << "You have reached the maximum limit for adding more" << endl;
                setTextColor(TC_WHITE);
            }
            break;
        }
        case MenuItem::OP_POP_EMPLOYESS:
        {
            Stack::POP_STATUS status = this->stack->pop();
            if (status.STATE)
            {
                setTextColor(TC_LIGHTRED);
                cout << "This Emp [" << status.POP_DATA.getName() << "] Was Deleted" << endl;
                setTextColor(TC_WHITE);
            }
            else
            {
                setTextColor(TC_LIGHTRED);
                cout << "Stack Is Empty" << endl;
                setTextColor(TC_WHITE);
            }

            break;
        }
        case MenuItem::OP_DISPLAY_EMPLOYESS:
            this->stack->display();
            break;
        case MenuItem::OP_EXIT:
            clearConsole();
            setTextColor(TC_LIGHTRED);
            printf("-------------------------------------- \n");
            printf("  You Have Exit From The App  \n");
            printf("-------------------------------------- \n");
            setTextColor(TC_WHITE);
            exit(0);
            break;
        }
    }
};
