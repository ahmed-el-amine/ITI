#include <iostream>

using namespace std;

enum MESSAGE_BY {
    BEFORE_MESSAGE_BY_VALUE,
    BEFORE_MESSAGE_BY_ADDRESS,
    BEFORE_MESSAGE_BY_REFERENCE,
    AFTER_MESSAGE_BY_VALUE,
    AFTER_MESSAGE_BY_ADDRESS,
    AFTER_MESSAGE_BY_REFERENCE,
};

class Swap
{
    public:
    void byValue(int x, int y) {
        int temp = x;
        x = y;
        y = temp;
    }
    void byAddress(int *x, int *y) {
        int temp = *x;
        *x = *y;
        *y = temp;
    }
    void byReference(int &x, int &y) {
        int temp = x;
        x = y;
        y = temp;
    }

    void showBeforeMessage(int x, int y, MESSAGE_BY messageType) {
        switch (messageType)
        {
            case BEFORE_MESSAGE_BY_VALUE:
                cout << "Before Swap By Value x = " << x << " Y = " << y << endl;
                break;        
            case BEFORE_MESSAGE_BY_ADDRESS:
                cout << "Before Swap By Address x = " << x << " Y = " << y << endl;
                break;        
            case BEFORE_MESSAGE_BY_REFERENCE:
                cout << "Before Swap By Reference x = " << x << " Y = " << y << endl;
                break;        
        }
    }

    void showAfterMessage(int x, int y, MESSAGE_BY messageType) {
        switch (messageType)
        {
            case AFTER_MESSAGE_BY_VALUE:
                cout << "After Swap By Value x = " << x << " Y = " << y << endl;
                break;        
            case AFTER_MESSAGE_BY_ADDRESS:
                cout << "After Swap By Address x = " << x << " Y = " << y << endl;
                break;        
            case AFTER_MESSAGE_BY_REFERENCE:
                cout << "After Swap By Reference x = " << x << " Y = " << y << endl;
                break;        
        }
    }
};

int main()
{
    Swap sw;
    int x = 10;
    int y = 50;

    sw.showBeforeMessage(x, y, MESSAGE_BY::BEFORE_MESSAGE_BY_VALUE);
    sw.byValue(x, y);
    sw.showAfterMessage(x, y, MESSAGE_BY::AFTER_MESSAGE_BY_VALUE);
    cout << "----------------------------------------------------------" << endl;

    sw.showBeforeMessage(x, y, MESSAGE_BY::BEFORE_MESSAGE_BY_ADDRESS);
    sw.byAddress(&x, &y);
    sw.showAfterMessage(x, y, MESSAGE_BY::AFTER_MESSAGE_BY_ADDRESS);
    cout << "----------------------------------------------------------" << endl;
    
    sw.showBeforeMessage(x, y, MESSAGE_BY::BEFORE_MESSAGE_BY_REFERENCE);
    sw.byReference(x, y);
    sw.showAfterMessage(x, y, MESSAGE_BY::AFTER_MESSAGE_BY_REFERENCE);

    return 0;
}