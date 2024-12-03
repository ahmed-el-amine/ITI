#ifndef MENU_C
#define MENU_C

#include <stdio.h>
#include "menu.h"
#include "menuOperations.h"
#include "menuOperations.c"
#include "../../lib/consoleColor.c"
#include "../../lib/handleInputs.h"

void initMenu_Void(MenuItem menuItems[], int menuItemsSize, MenuOptions menuOptions, char confirmExit)
{
    // menuItems[0].dataHolder.employeeList[0].id = 999;
    showMenu_Void(menuItems, menuItemsSize, menuOptions);
    watchMenuControls_Void(menuItems, menuItemsSize, menuOptions, confirmExit);
}

void showMenu_Void(MenuItem menuItems[], int menuItemsSize, MenuOptions menuOptions)
{
    clear();

    if (menuOptions.selectedItemElement > 0)
    {
        handleMenuOperations_Void(menuItems, menuItemsSize, menuOptions);
    }
    else
    {
        for (int i = 0; i < menuItemsSize; i++)
        {
            MenuItem item = menuItems[i];

            if (item.topNote[0] != '\0')
            {
                setTextColor(TC_LIGHTGREEN);
                printf("Note:");
                setTextColor(TC_WHITE);
                printf(" %s \n", item.topNote);
            }

            if (menuOptions.focusedOption == (i + 1))
            {
                setTextColor(TC_CYAN);
                printf("➤ %s", item.menuText);
                if (item.focusNote[0] != '\0')
                {
                    setTextColor(TC_WHITE);
                    printf(" [?] %s", item.focusNote);
                }
                printf("\n");
            }
            else
            {
                setTextColor(TC_WHITE);
                printf("%s\n", item.menuText);
            }

            printf("\n");
        }

        setTextColor(TC_WHITE);
    }
}

void watchMenuControls_Void(MenuItem menuItems[], int menuItemsSize, MenuOptions menuOptions, char confirmExit)
{
    char isRunning = 1;

    while (isRunning)
    {
        char keyChar = getKey_Char();

        char isValidUserInputKey = 1;

        switch (keyChar)
        {
        // Handling Change Selection Key
        case KEY_UP:
        case KEY_LEFT:
            menuOptions.focusedOption = (menuOptions.focusedOption <= 1 ? (menuItemsSize) : (menuOptions.focusedOption - 1));
            break;
        case KEY_DOWN:
        case KEY_RIGHT:
            menuOptions.focusedOption = (menuOptions.focusedOption >= menuItemsSize ? 1 : (menuOptions.focusedOption + 1));
            break;
        case KEY_HOME:
            menuOptions.focusedOption = 1;
            break;
        case KEY_END:
            menuOptions.focusedOption = menuItemsSize;
            break;
            // Handling The Enter Key
        case KEY_ENTER:
            for (int i = 0; i < menuItemsSize; i++)
                if ((i + 1) == menuOptions.focusedOption)
                {
                    if (menuItems[i].operation != OP_DO_NOTING)
                    {
                        menuItems[i].isEnterdMenu = 1;
                        menuOptions.selectedItemElement = i + 1;
                    }
                }
                else
                    menuItems[i].isEnterdMenu = 0;
            break;
        // Handling Exit Or Back Key
        case KEY_Q:
        case KEY_ESC:
            if (menuOptions.selectedItemElement > 0)
            {
                menuOptions.selectedItemElement = 0;
                for (int i = 0; i < menuItemsSize; i++)
                    menuItems[i].isEnterdMenu = 0;
                break;
            }
            else
            {
                if (confirmExit > 0)
                {
                    confirmExitMessageMenu_Void();
                }
                return;
            }
        default:
            isValidUserInputKey = 0;
            break;
        }

        showMenu_Void(menuItems, menuItemsSize, menuOptions);
    }
}

void confirmExitMessageMenu_Void()
{
    setTextColor(TC_LIGHTRED);
    printf("------------------------------------------------------------------ \n");
    printf("  To Confirm Exit Press [ESC] One More Time Or [Any Key] To Cansel  \n");
    printf("------------------------------------------------------------------ \n");
    setTextColor(TC_WHITE);
}

#endif