#include <stdio.h>
#include "./src/utils/userControls/userControls.h"
#include "./src/utils/userControls/userControls.c"
#include "./src/lib/strings/strings.c"
#include "./src/lib/strings/strings.h"
#include "./src/lib/defines.h"

void enableInserMode()
{
    printf("\e[4 q");
}

void disableInsertMode()
{
    printf("\e[2 q");
}

int main()
{
    char lineData[MAX_CHARS + 1] = { 0 };

    unsigned char lineDataSize = 0;
    unsigned char startPosation = 0;
    unsigned char curentPosation = 0;
    unsigned char endPosation = MAX_CHARS - 1;
    char isInsertMode = 0;
    
    printf("%s\n", lineData, curentPosation + 1);
    printf("CurentPosation: %d InsertMode: %d lineDataSize: %d", curentPosation + 1, isInsertMode, lineDataSize + 1);
    gotoxy(curentPosation + 1, 0);

    while (1)
    {
        char input = userControlsGetInputChar();
        switch (input)
        {
            case KEY_INSERT_MODE:
                isInsertMode = !isInsertMode;
                if (isInsertMode) enableInserMode();
                else disableInsertMode();
                break;
            case KEY_RIGHT:
                if (curentPosation < lineDataSize)
                {
                    curentPosation++;
                    gotox(curentPosation);
                }
                break;
            case KEY_LEFT:
                if (curentPosation > startPosation)
                {
                    curentPosation--;
                    
                }
                break;
            case KEY_BACKSPACE:
                if (curentPosation > 0)
                {
                    curentPosation--;
                    lineDataSize--;
                    lineData[curentPosation] = input;
                }
                break;
            default:
                if (lineDataSize < endPosation)
                {
                    // type at the end
                    if (!isInsertMode && curentPosation == lineDataSize)
                    {
                        lineData[curentPosation] = input;
                        if (curentPosation == lineDataSize)
                        {
                            lineDataSize++;
                        }
                        curentPosation++;
                    }
                    if (!isInsertMode && curentPosation < lineDataSize)
                    {
                        char newData[MAX_CHARS + 1] = { 0 };
                        char insertChat = 0;
                        for (int i = 0; i < lineDataSize + 1; i++)
                        {
                            if (curentPosation == i)
                            {
                                insertChat = 1;
                                newData[i] = input;
                            }
                            else
                            {
                                newData[i] = lineData[insertChat ? i - 1 :i];
                            }
                        }
                        lineDataSize++;
                        stringStrcp(lineData, newData);
                    }
                    
                    else if (isInsertMode)
                    {
                        lineData[curentPosation] = input;
                    }
                }
            break;
        }

        clear();
        
        printf("%s\n", lineData, curentPosation + 1);
        printf("CurentPosation: %d InsertMode: %d lineDataSize: %d", curentPosation + 1, isInsertMode, lineDataSize + 1);

        gotoxy(curentPosation + 1, 0);
    }
    

    return 0;
}