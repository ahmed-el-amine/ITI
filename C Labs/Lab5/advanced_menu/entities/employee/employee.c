#ifndef EMPLOYEE_C
#define EMPLOYEE_C

#include <stdio.h>
#include "../../lib/defines.h"
#include "../../hooks/menu/menu.h"
#include "../../lib/strings/strings.c"
#include "../../lib/consoleColor.c"
#include "../../lib/handleInputs.h"

int calcUsedSpace_Int(Employee employeesList[MAX_EMPLOYEE_CAN_SAVE]);
int calcFreeSpace_Int(Employee employeesList[MAX_EMPLOYEE_CAN_SAVE]);
void addNewEmploye_Void(MenuItem menuItems);
void addNewEmployeHandler_Void(MenuItem menuItems);
void editEmployes_Void(MenuItem menuItems);

void addNewEmployeHandler_Void(MenuItem menuItems)
{
    // calc do we have space in array or no
    int freeSpace = calcFreeSpace_Int(menuItems.dataHolder.employeeList);
    char canAddNew = 1;

    if (freeSpace > 0)
    {
        while (canAddNew && freeSpace > 0)
        {
            clear();

            setTextColor(TC_GREEN);
            printf("You Currently Have [%d OF %d] Employees Free Space \n", freeSpace, MAX_EMPLOYEE_CAN_SAVE);
            setTextColor(TC_WHITE);

            addNewEmploye_Void(menuItems);

            setTextColor(TC_GREEN);
            printf("\nYou have successfully added a new employee. \n");
            setTextColor(TC_WHITE);

            freeSpace = calcFreeSpace_Int(menuItems.dataHolder.employeeList);

            if (freeSpace <= 0)
            {
                setTextColor(TC_LIGHTRED);
                printf("\n\nYou have reached the maximum limit and cannot add more \n");
                setTextColor(TC_CYAN);
                printf("Press [ESC] OR [Q] To Go Back To Main Menu \n");
                setTextColor(TC_WHITE);
            }
            else
            {
                setTextColor(TC_LIGHTGREEN);
                printf("\nDo You Whant To Countinu Adding Items Press [Enter]/Yes Or [ESC]/No \n");
                setTextColor(TC_WHITE);

                char runing = 1;
                while (runing)
                {
                    char keyChar = getKey_Char();
                    switch (keyChar)
                    {
                        case KEY_ENTER:
                            runing = 0;
                        break;
                        case KEY_ESC:
                        case KEY_Q:
                            canAddNew = 0;
                            runing = 0;
                            confirmExitMessageMenu_Void();
                        break;
                    }
                }
            }
        }
    }
    else
    {
        int usedSpace = calcUsedSpace_Int(menuItems.dataHolder.employeeList);
        setTextColor(TC_RED);
        printf("You Currently Have [%d] Employees And You Cann't Add More \n", usedSpace);
        setTextColor(TC_CYAN);
        printf("Press [ESC] OR [Q] To Go Back To Main Menu \n");
        setTextColor(TC_WHITE);
    }
}

void addNewEmploye_Void(MenuItem menuItems)
{
    int empID = 0;
    while (empID <= 0)
    {
        setTextColor(TC_CYAN);
        printf("Enter Employee Uniqu ID [Numbers Only] : ");
        setTextColor(TC_WHITE);

        char buffer[256];
        fgets(buffer, 256, stdin);
        empID = atoi(buffer);

        if (empID <= 0) 
        {
            setTextColor(TC_RED);
            printf("Please Enter Valid Number \n");
            setTextColor(TC_WHITE);
        }
        else 
        {
            int idInUse = 0;
            for (int i = 0; i < MAX_EMPLOYEE_CAN_SAVE; i++)
            {
                Employee emp = menuItems.dataHolder.employeeList[i];
                if (empID == emp.id)
                {
                    idInUse = 1;
                    i + MAX_EMPLOYEE_CAN_SAVE;
                }
            }
            
            if (idInUse > 0)
            {  
                setTextColor(TC_RED);
                printf("This ID [%d] Is Alrady Used \n", empID);
                setTextColor(TC_WHITE);
                empID = 0;
            }
            else printf("EmployeeID is: %d \n", empID);
        }
    }

    //////////////

    setTextColor(TC_CYAN);
    printf("Enter Employee Name : ");
    setTextColor(TC_WHITE);

    char empName[50];
    scanf("%50[^\n]", empName);
    getchar(); // read skip line
    printf("Employee Name is: %s \n", empName);

    //////////////

    int empSalary = 0;
    while (empSalary <= 0)
    {
        setTextColor(TC_CYAN);
        printf("Enter Employee Salary [Numbers Only] : ");
        setTextColor(TC_WHITE);

        char buffer[256];
        fgets(buffer, 256, stdin);
        empSalary = atoi(buffer);

        if (empSalary <= 0) 
        {
            setTextColor(TC_RED);
            printf("Please Enter Valid Number \n");
            setTextColor(TC_WHITE);
        }
        else  printf("Employee Salary is: %d \n", empSalary);
    }

    Employee newEmp = { .id = empID, .salary = empSalary };

    stringStrcp(newEmp.name, empName);

    menuItems.dataHolder.employeeList[calcUsedSpace_Int(menuItems.dataHolder.employeeList)] = newEmp;

    setTextColor(TC_WHITE);
}

void displayEmployes_Void(MenuItem menuItems)
{
    MenuItem menuList[MAX_EMPLOYEE_CAN_SAVE] = {};

    int menuItemsSize = 0;

    for (int i = 0; i < MAX_EMPLOYEE_CAN_SAVE; i++)
    {
        Employee emp = menuItems.dataHolder.employeeList[i];
        if (emp.id > 0)
        {
            MenuItem x = {
                .isEnterdMenu = 0,
                .operation = OP_EDIT_EMPLOYESS,
                .focusNote = "Press Enter To Edit",
                .dataHolder = {
                    .employeeToEdit = menuItems.dataHolder.employeeList[i]
                }
            };

            menuList[i] = x;
            
            stringStrcp(menuList[i].menuText, emp.name);

            menuItemsSize++;
        }
    }

    MenuOptions op1 = { 
        .focusedOption = 1, 
        .selectedItemElement = 0
    };

    initMenu_Void(menuList, menuItemsSize, op1, 1);
}

void editEmployes_Void(MenuItem menuItems)
{
    setTextColor(TC_CYAN);
    printf("Name Is [%s] Enter New Name : ", menuItems.dataHolder.employeeToEdit.name);
    setTextColor(TC_WHITE);

    char empName[50];
    scanf("%50[^\n]", empName);
    getchar(); // read skip line
    printf("Employee Name is: %s \n", empName);

    //////////////

    int empSalary = 0;
    while (empSalary <= 0)
    {
        setTextColor(TC_CYAN);
        printf("Salary Is [%d] Enter New Salary [Numbers Only] : ", menuItems.dataHolder.employeeToEdit.salary);
        setTextColor(TC_WHITE);

        char buffer[256];
        fgets(buffer, 256, stdin);
        empSalary = atoi(buffer);

        if (empSalary <= 0) 
        {
            setTextColor(TC_RED);
            printf("Please Enter Valid Number \n");
            setTextColor(TC_WHITE);
        }
        else  printf("Employee Salary is: %d \n", empSalary);
    }

    Employee newEmp = { .id = menuItems.dataHolder.employeeToEdit.id, .salary = empSalary };

    stringStrcp(newEmp.name, empName);

    // printf("Sorry This Edit Method Not Completly Finished There is A Bug And I'm Tray To Solveit \n");
    for (int i = 0; i < MAX_EMPLOYEE_CAN_SAVE; i++)
    {
        if (menuItems.dataHolder.employeeList[i].id == menuItems.dataHolder.employeeToEdit.id)
        {
            // An Error
            // menuItems.dataHolder.employeeList[i] = newEmp;
            // menuItems.dataHolder.employeeList[i] = newEmp;
            // menuItems.dataHolder.employeeList[i].

            // stringStrcp(menuItems.dataHolder.employeeList[i].name, empName);
            //  stringStrcp(menuItems.dataHolder.employeeList[i].salary, empSalary);
            // i + MAX_EMPLOYEE_CAN_SAVE;
        }
        
    }
    

    setTextColor(TC_WHITE);
}

int calcUsedSpace_Int(Employee employeesList[MAX_EMPLOYEE_CAN_SAVE])
{
    int freeSpace = 0;
    for (int i = 0; i < MAX_EMPLOYEE_CAN_SAVE; i++)
    {
        freeSpace = employeesList[i].id > 0 ? (freeSpace + 1) : freeSpace;
    }
    return freeSpace;
}

int calcFreeSpace_Int(Employee employeesList[MAX_EMPLOYEE_CAN_SAVE])
{
    return MAX_EMPLOYEE_CAN_SAVE - calcUsedSpace_Int(employeesList);
}

#endif