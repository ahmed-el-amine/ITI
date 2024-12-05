#ifndef HANDLEINPUTS_H
#define HANDLEINPUTS_H


#include <iostream>
#include <cstring>
#include <stdio.h>
#include "./conio.h"
#include "defines.h"

using namespace std;

class Input {
    public:
    static char getKey()
    {
        char c = getch();

        if (c == KEY_EXTEND)
        {
            if (kbhit())
            {
                getch();
                c = getch();
                return c;
            }
            else
                return c;
        }
        return c;
    }

    struct NUMBER_STATE {
        bool isNumber;
        int Number;
    };
    static NUMBER_STATE getNumber() {
        int number;
        char buffer[256];
        fgets(buffer, 256, stdin);
        int bufferLength = strlen(buffer);

        for (int i = 0; i < bufferLength; i++)
        {
            char mChar = buffer[i];
            if (isalpha(mChar))
            {
                return NUMBER_STATE{ .isNumber = false};
            }
        }
        
        number = atoi(buffer);

        return NUMBER_STATE{ .isNumber = true, .Number = number };
    }
};

class Validate {

};

int getInputNumber() {
    int num;

    char buffer[256];
    fgets(buffer, 256, stdin);

    num = atoi(buffer);
    if (strlen(buffer) == num)
    {
        return num;
    }
}

#endif