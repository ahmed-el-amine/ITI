#ifndef EMPLOYEE_C
#define EMPLOYEE_C

#include <iostream>
#include <cstring>
#include "../stack/stack.cpp"
#include "../../lib/consoleColor.cpp"

using namespace std;

class Employee
{
private:
    char *name;
    int id;

public:
    Employee() {}
    Employee(int id, const char *name)
    {
        this->id = id;
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    int getID()
    {
        return this->id;
    }

    char *getName()
    {
        return this->name;
    }
};

Employee createNewEmployee()
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
            // int idInUse = 0;
            // for (int i = 0; i < st.getStackSize(); i++)
            // {
            //     Employee emp = st.getData()[i];
            //     if (empID == emp.getID())
            //     {
            //         idInUse = 1;
            //         i + st.getStackSize();
            //     }
            // }

            // if (idInUse > 0)
            // {
            //     setTextColor(TC_RED);
            //     cout << "This Id " << empID << " Is Alrady Used" << endl;
            //     setTextColor(TC_WHITE);
            //     empID = 0;
            // }
            // else
            cout << "EmployeeID is: " << empID << endl;
        }
    }

    setTextColor(TC_CYAN);
    printf("Enter Employee Name : ");
    setTextColor(TC_WHITE);
    char empName[50];
    scanf("%50[^\n]", empName);
    getchar(); // read skip line
    printf("Employee Name is: %s \n", empName);

    return Employee(empID, empName);
}

#endif