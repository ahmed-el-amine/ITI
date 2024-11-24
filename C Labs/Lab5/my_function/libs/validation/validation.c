int validationInputInt_Int()
{
    int num = 0;
    char ch = 0;
    int exit = 1;
    while (exit)
    {
        ch = getchar();

        if ((int)ch >= 48 && (int)ch <= 57) 
        {
            // printf("%c %d \n", ch, ch);
            num += ch;
        }
        else if ((int)ch == 10) exit = 0;
    }
    return num;


    // char ch = 0;
    // while (ch = getchar())
    // {
    //     printf("%c %d", ch, ch);
    // }

    // int i = 0;
    // char ch;

    // // Read characters until newline or max length is reached
    // while ((ch = getchar()) != '\n' && ch != EOF) {
    //     printf("%c", ch);
    // }


    return 1;
}