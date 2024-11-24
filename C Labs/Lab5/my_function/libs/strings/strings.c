/// @brief this function takes one array and return its length
/// @param arr 
/// @return int
int stringLength_Int(char arr[])
{
    int length = 0;
    while (arr[length] != '\0')
    {
        length++;
    }
    return length;
}


/// @brief this function takes two arrays and compare them return char [0] if equal, [1] if arr1 > arr2, [-1] if arr1 < arr2
/// @param arr1 
/// @param arr2 
/// @return char [0] if equal, [1] if arr1 > arr2, [-1] if arr1 < arr2
char stringStrcump_Char(char arr1[], char arr2[])
{
    int arr1Size = stringLength_Int(arr1);
    int arr2Size = stringLength_Int(arr2);

    if (arr1Size != arr2Size)
    {
        if (arr1Size > arr2Size) return 1;
        else return -1;
    }
    else 
    {
        for (int i = 0; i < arr1Size; i++)
        {
            if (arr1[i] > arr2[i]) return 1;
            else if (arr1[i] < arr2[i]) return -1;
        }
        return 0;
    }
}

/// @brief this function takes two char arrays and append source to dest
/// @param dest 
/// @param source
void stringStrcat_Void(char dest[], char source[])
{
    int destLength = 0;
    while (dest[destLength] != '\0')
    {
        destLength++;
    }

    int i = 0;
    while (source[i] != '\0')
    {
        dest[destLength] = source[i];
        i++;
        destLength++;
    }

    source[destLength+i]= '\0';
}


/// @brief this function copy source to dist
/// @param dist 
/// @param source 
void stringStrcp(char dist[], char source[])
{
    int i = 0;

    while (source[i] != '\0') {
        dist[i] = source[i];
        i++;
    }
    dist[i] = '\0';
}

/// @brief this function convert char to LowerCase
/// @param ch 
/// @return char
char stringCharToLowerCase(char ch)
{
    if (ch >= 'A' && ch<= 'Z') return (ch + 32);
    return ch;
}

/// @brief this function convert char to UpperCase
/// @param ch 
/// @return char
char stringCharToUpperCase(char ch)
{
    if (ch >= 'a' && ch<= 'z') return (ch - 32);
    return ch;
}

/// @brief this function convert string to LowerCase
/// @param chars 
void stringToLowerCase(char chars[])
{

    int i = 0;
    while (chars[i] != '\0')
    {
        if (chars[i] >= 'A' && chars[i] <= 'Z') chars[i] = (chars[i] + 32);
        i++;
    }
}

/// @brief this function convert string to UpperCase
/// @param chars 
void stringToUpperCase(char chars[])
{
    int i = 0;
    while (chars[i] != '\0')
    {
        if (chars[i] >= 'a' && chars[i] <= 'z') chars[i] = (chars[i] - 32);
        i++;
    }
}