#include <iostream>

using namespace std;

class Stack
{
    int SIZE;
    int INDEX;
    int *DATA;
    static int CALL_COUNT;

public:
    // Constructor
    Stack(int SIZE)
    {
        this->SIZE = SIZE;
        this->INDEX = -1;
        this->DATA = new int[SIZE];

        CALL_COUNT++;
    }

    // push
    struct PUSH_STATUS
    {
        char STATE;
        int PUSH_DATA;
    };
    PUSH_STATUS push(int Data)
    {
        if (this->INDEX >= this->SIZE - 1)
            return PUSH_STATUS{.STATE = 0, .PUSH_DATA = 0};

        this->INDEX++;
        this->DATA[this->INDEX] = Data;

        return PUSH_STATUS{.STATE = 1, .PUSH_DATA = Data};
    }

    // pop
    struct POP_STATUS
    {
        char STATE;
        int POP_DATA;
    };
    POP_STATUS pop()
    {
        if (this->INDEX <= -1)
            return POP_STATUS{.STATE = 0, .POP_DATA = 0};

        int POP_DATA = this->DATA[this->INDEX];

        this->DATA[this->INDEX] = 0;
        this->INDEX--;

        return POP_STATUS{.STATE = 1, .POP_DATA = POP_DATA};
    }

    void display()
    {
        if (this->INDEX > -1)
        {
            for (int i = 0; i < this->INDEX; i++)
            {
                cout << this->DATA[i] << endl;
            }
        }
    }

    // getCallCount
    static int getCallCount()
    {
        return CALL_COUNT;
    }

    // Destructor
    ~Stack()
    {
        delete[] DATA;
        CALL_COUNT--;
    }
};

int Stack::CALL_COUNT = 0;

int main()
{
    Stack st1(5);

    Stack::PUSH_STATUS p_state = st1.push(1);
    cout << (p_state.STATE ? "Push Done" : "Push Failed") << endl;
    if (p_state.STATE)
    {
        cout << "Push Data is = " << p_state.PUSH_DATA << endl;
    }

    cout << (st1.push(2).STATE ? "Push Done" : "Push Failed") << endl;
    cout << (st1.push(3).STATE ? "Push Done" : "Push Failed") << endl;
    cout << (st1.push(4).STATE ? "Push Done" : "Push Failed") << endl;
    cout << (st1.push(5).STATE ? "Push Done" : "Push Failed") << endl;
    Stack::POP_STATUS status = st1.pop();
    if (status.STATE)
    {
        cout << "POP Data is = " << status.POP_DATA << endl;
    }
    cout << (st1.push(6).STATE ? "Push Done" : "Push Failed") << endl;
    cout << (st1.push(6).STATE ? "Push Done" : "Push Failed") << endl;
    cout << (st1.push(6).STATE ? "Push Done" : "Push Failed") << endl;
    cout << "Call Count = " << Stack::getCallCount() << endl;

    st1.display();

    cout << "------------------------------------" << endl;

    Stack st2(4);
    cout << (st2.push(1).STATE ? "Push Done" : "Push Failed") << endl;
    cout << (st2.push(2).STATE ? "Push Done" : "Push Failed") << endl;
    cout << (st2.push(3).STATE ? "Push Done" : "Push Failed") << endl;
    cout << (st2.push(4).STATE ? "Push Done" : "Push Failed") << endl;
    cout << (st2.push(5).STATE ? "Push Done" : "Push Failed") << endl;
    cout << (st2.push(6).STATE ? "Push Done" : "Push Failed") << endl;

    cout << "Call Count = " << Stack::getCallCount() << endl;

    st1.display();

    return 0;
}
