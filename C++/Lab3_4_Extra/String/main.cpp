#include <iostream>
#include "./MyString.cpp"

using namespace std;

int main()
{
    MyString s1 = "Ahmed";
    MyString s2 = "Mohamed";

    cout << s1 + s2 << endl;
    cout << s1 + " Text At End" << endl;
    cout << "Text At Start " + s1 + " Text At End " + s2 << endl;
    // -----------------------
    cout << s1 << endl;
    cout << s2 << endl;
    s1 = s2;
    cout << s1 << endl;
    cout << s2 << endl;
    cout << (s1 = s2);

    return 0;
}