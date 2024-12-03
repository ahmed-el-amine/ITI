#ifndef STACK_C
#define STACK_C

#include <iostream>
#include "../employee/employee.cpp"
#include "../../lib/consoleColor.cpp"

using namespace std;

class Stack
{
    int SIZE;
    int INDEX;
    Employee *DATA;

public:
    // Constructor
    Stack(int SIZE)
    {
        this->SIZE = SIZE;
        this->INDEX = -1;
        this->DATA = new Employee[SIZE];
    }

    // push
    struct PUSH_STATUS
    {
        char STATE;
        Employee PUSH_DATA;
    };
    PUSH_STATUS push(Employee Data)
    {
        if (this->INDEX >= this->SIZE - 1)
            return PUSH_STATUS{.STATE = 0};

        this->INDEX++;
        this->DATA[this->INDEX] = Data;

        return PUSH_STATUS{.STATE = 1, .PUSH_DATA = Data};
    }

    // pop
    struct POP_STATUS
    {
        char STATE;
        Employee POP_DATA;
    };
    POP_STATUS pop()
    {
        if (this->INDEX <= -1)
            return POP_STATUS{
                .STATE = 0,
            };

        Employee POP_DATA = this->DATA[this->INDEX];

        // this->DATA[this->INDEX] = NULL;
        this->INDEX--;

        return POP_STATUS{.STATE = 1, .POP_DATA = POP_DATA};
    }

    int getStackSize()
    {
        return this->INDEX + 1;
    }

    int getStackLimit() {
        return this->SIZE;
    }

    void display()
    {
        if (this->INDEX > -1)
        {
            for (int i = 0; i <= this->INDEX; i++)
            {
                cout << this->DATA[i].getName() << endl;
            }
        }
        else
        {
            setTextColor(TC_LIGHTRED);
            cout << "Stack Is Empty No Data To Display" << endl;
            setTextColor(TC_WHITE);
        }
    }

    Employee *getData()
    {
        return this->DATA;
    }

    // Destructor
    ~Stack()
    {
        delete[] DATA;
    }
};

#endif