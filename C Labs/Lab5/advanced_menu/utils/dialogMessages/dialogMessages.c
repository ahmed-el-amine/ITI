#ifndef DIALOG_MESSAGES_C
#define DIALOG_MESSAGES_C

#include <stdio.h>
#include "../../hooks/menu/menu.h"
#include "../../hooks/menu/menu.c"

void dialogMessageExitApp_Void()
{

     MenuItem m1 = { 
        .topNote = "This is top note text for option TEST 1",
        .menuText = "TEST 1",
        .isEnterdMenu = 0,
        .operation = OP_DO_NOTING
    };

    MenuItem m2 = { 
        .focusNote = "This focusNote for the TEST 2",
        .menuText = "TEST 2",
        .isEnterdMenu = 0,
        .operation = OP_DO_NOTING
    };


    MenuItem m3 = { 
        .topNote = "Ar You Soure You Whant To Exit? If No Click [ESC] OR [Q] 2 Times In Row",
        .menuText = "Exit",
        .isEnterdMenu = 0,
        .operation = OP_EXIT
    };

   

    MenuItem menuList[] = { 
        m1,
        m2,
        m3
    };

    MenuOptions op1 = { 
        .focusedOption = 1, 
        .selectedItemElement = 0
    };

    int menuItemsSize = sizeof(menuList) / sizeof(menuList[0]);

    initMenu_Void(menuList, menuItemsSize, op1, 1);
}

#endif