#ifndef MENU_H
#define MENU_H

#include "../../lib/defines.h"
#include "../../entities/employee/employee.h"

typedef struct {
    Employee *employeeList;
    Employee employeeToEdit;
} 
DataHolder;

typedef enum
{
    OP_DO_NOTING = 0,
    OP_EXIT,
    OP_SHOW_EXIT_CONFIRM,
    OP_ADD_NEW_EMPLOYESS,
    OP_DISPLAY_EMPLOYESS,
    OP_EDIT_EMPLOYESS,
}
MenuOperations;

typedef struct
{
    char topNote[100];
    char focusNote[100];
    char menuText[100];
    char isEnterdMenu;
    MenuOperations operation;
    DataHolder dataHolder;
} 
MenuItem;

typedef struct
{
    unsigned char focusedOption;
    unsigned char selectedItemElement;
} 
MenuOptions;

void confirmExitMessageMenu_Void();
void initMenu_Void(MenuItem menuItems[], int menuItemsSize, MenuOptions menuOptions, char confirmExit);
void showMenu_Void(MenuItem menuItems[], int menuItemsSize, MenuOptions menuOptions);
void watchMenuControls_Void(MenuItem menuItems[], int menuItemsSize, MenuOptions menuOptions, char confirmExit);

#endif