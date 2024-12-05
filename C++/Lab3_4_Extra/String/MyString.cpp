#include <iostream>
#include <cstring>
using namespace std;

class MyString
{
private:
    char *str = new char[0];
    int _length = 0;

public:
    MyString(const char *text)
    {
        this->_length = strlen(text);
        str = new char[this->_length + 1];
        strcpy(str, text);
    }

    char *getText() const
    {
        return str;
    }

    int length() const
    {
        return this->_length;
    }

    MyString operator+(MyString &x)
    {
        char *newStringArray = new char[this->length() + x.length() + 1];
        strcpy(newStringArray, this->getText());
        strcat(newStringArray, x.getText());
        MyString newString = newStringArray;
        delete[] newStringArray;
        return newString;
    }

    MyString operator+(const char *x)
    {
        char *newStringArray = new char[this->length() + strlen(x) + 1];
        strcpy(newStringArray, this->getText());
        strcat(newStringArray, x);
        MyString newString = newStringArray;
        delete[] newStringArray;
        return newString;
    }

    MyString &operator=(MyString &c)
    {
        delete[] this->str;
        this->_length = c.length();
        this->str = new char[this->_length + 1];
        strcpy(this->str, c.getText());

        return *this;
    }

    ~MyString()
    {
        delete[] str;
    }
};

MyString operator+(const char *x, MyString &c)
{
    char *newStringArray = new char[c.length() + strlen(x) + 1];
    strcpy(newStringArray, x);
    strcat(newStringArray, c.getText());
    MyString newString = newStringArray;
    delete[] newStringArray;
    return newString;
}

ostream &operator<<(ostream &os, const MyString &myStr)
{
    os << myStr.getText();
    return os;
}