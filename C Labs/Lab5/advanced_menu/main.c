#include <stdio.h>
#include "lib/conio.h"
#include "hooks/menu/menu.h"
#include "hooks/menu/menu.c"
#include "entities/employee/employee.h"

int main()
{
    setTextColor(TC_WHITE);

    // Create Default employee
    Employee em1 = { .id = 1, .name = "Ahmed Mohamed", .salary = 100000 };

    // Create Employee List
    Employee employeesList[MAX_EMPLOYEE_CAN_SAVE] = { em1 };

    // Create Menu Items
    MenuItem m1 = { 
        .menuText = "New Employes",
        .focusNote = "To Add New Employes",
        .isEnterdMenu = 0,
        .operation = OP_ADD_NEW_EMPLOYESS,
         .dataHolder = { 
            .employeeList = employeesList
        }
    };

    MenuItem m2 = { 
        .menuText = "Display/Edit Employess",
        .focusNote = "To Show All Employes",
        .isEnterdMenu = 0,
        .operation = OP_DISPLAY_EMPLOYESS,
        .dataHolder = { 
            .employeeList = employeesList
        }
    };

    MenuItem m3 = { 
        .menuText = "Exit",
        .focusNote = "To Exit Form App",
        .isEnterdMenu = 0,
        .operation = OP_SHOW_EXIT_CONFIRM
    };

    // Create Menu List
    MenuItem menuList[] = { 
        m1, 
        m2,
        m3
    };

    // Create Menu Options
    MenuOptions op1 = {
        .focusedOption = 1, 
        .selectedItemElement = 0
    };

    int menuItemsSize = sizeof(menuList) / sizeof(menuList[0]);

    // Show Menu
    initMenu_Void(menuList, menuItemsSize, op1, 0);

    return 0;
}