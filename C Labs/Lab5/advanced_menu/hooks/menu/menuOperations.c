#ifndef MENU_OPERATION_C
#define MENU_OPERATION_C

#include "menu.h"
#include "../../entities/employee/employee.h"
#include "../../entities/employee/employee.c"
#include "../../utils/dialogMessages/dialogMessages.h"
#include "../../utils/dialogMessages/dialogMessages.c"
#include "../../lib/consoleColor.c"

void handleMenuOperations_Void(MenuItem menuItems[], int menuItemsSize, MenuOptions menuOptions)
{
    MenuItem menuItem = menuItems[menuOptions.selectedItemElement - 1];

    switch (menuItem.operation)
    {
        case OP_ADD_NEW_EMPLOYESS:
            addNewEmployeHandler_Void(menuItem);
            break;
        case OP_DISPLAY_EMPLOYESS:
            displayEmployes_Void(menuItem);
            break;
        case OP_EDIT_EMPLOYESS:
            editEmployes_Void(menuItem);
            break;
        case OP_SHOW_EXIT_CONFIRM:
            dialogMessageExitApp_Void();
            break;
        case OP_EXIT:
            clear();
            setTextColor(TC_LIGHTRED);
            printf("-------------------------------------- \n");
            printf("  You Have Exit From The App  \n");
            printf("-------------------------------------- \n");
            setTextColor(TC_WHITE);
            exit(0);
            break;
    }
}

#endif