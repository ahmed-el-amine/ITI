#include <iostream>

using namespace std;

class Complex
{
    int real = 0;
    int imaginary = 0;

public:
    Complex(int realData, int imgData)
    {
        this->real = realData;
        this->imaginary = imgData;
    }
    void setReal(int realData)
    {
        this->real = realData;
    }
    int getReal()
    {
        return real;
    }
    //
    void setImg(int imgData)
    {
        this->imaginary = imgData;
    }
    int getImg()
    {
        return this->imaginary;
    }
    //
    void fastSet(int realData, int imgData)
    {
        this->real = realData;
        this->imaginary = imgData;
    }

    void display()
    {
        if (real == 0 && imaginary == 0)
        {
            cout << "0" << endl;
            return;
        }

        if (real != 0)
            cout << real;
        if (imaginary > 0)
            cout << "+" << imaginary << "j" << endl;
        else if (imaginary < 0)
            cout << imaginary << "j" << endl;
    }

    static Complex add(Complex complex1, Complex complex2)
    {
        Complex result(complex1.getReal() + complex2.getReal(), complex1.getImg() + complex2.getImg());
        return result;
    }

    static Complex sub(Complex complex1, Complex complex2)
    {
        Complex result(complex1.getReal() - complex2.getReal(), complex1.getImg() - complex2.getImg());
        return result;
    }

    Complex operator+(Complex c)
    {
        Complex newComplex(this->real + c.real, this->imaginary + c.imaginary);
        return newComplex;
    }

    Complex operator-(Complex c)
    {
        Complex newComplex(this->real - c.real, this->imaginary - c.imaginary);
        return newComplex;
    }

    Complex operator++()
    {
        this->real++;
        this->imaginary++;
        return *this;
    }

    Complex operator--()
    {
        this->real--;
        this->imaginary--;
        return *this;
    }

    Complex operator++(int x)
    {
        Complex temp = *this;

        ++(*this);

        return temp;
    }

    Complex operator--(int x)
    {
        Complex temp = *this;

        --(*this);

        return temp;
    }

    Complex operator+(int x)
    {
        return Complex(this->real + x, this->imaginary + x);
    }

    Complex operator-(int x)
    {
        return Complex(this->real - x, this->imaginary - x);
    }

    bool operator==(Complex c2)
    {
        if (this->real == c2.getReal() && this->imaginary == c2.getImg())
            return true;
        return false;
    }

    void operator+=(Complex c2)
    {
        this->setReal(this->getReal() + c2.getReal());
        this->setImg(this->getImg() + c2.getImg());
    }

    ~Complex()
    {
        // cout << "Dist " << endl;
    }
};

Complex operator+(int x, Complex c)
{
    return Complex(c.getImg() + x, c.getReal() + x);
}

Complex operator-(int x, Complex c)
{
    return Complex(c.getImg() - x, c.getReal() - x);
}

int main()
{

    Complex c1(15, 5);
    Complex c2(10, 2);
    // ----------------------
    c1.display();
    c1 += c2;
    c1.display();
    cout << ((c1 == c2) ? "true" : "false");

    // ----------------------
    // cout << ((c1 == c2) ? "true" : "false");

    // ----------------------
    // c1.display();
    // Complex c2 = c1 - 1;
    // c1.display();
    // c2.display();

    // ----------------------

    // c1.display();
    // Complex c2 = c1 + 1;
    // c1.display();
    // c2.display();

    // ----------------------

    // c1.display();
    // Complex c2 = 5 + c1;
    // c1.display();
    // c2.display();

    // ----------------------
    // c1.display();
    // ++c1;
    // c1++;
    // c1--;
    // --c1;
    // c1.display();
    // ----------------------
    // c1.display();
    // c2.display();

    // Complex c3 = c1 + c2;

    // c1.display();
    // c2.display();
    // c3.display();

    // c3 = c1 - c2;

    // c1.display();
    // c2.display();
    // c3.display();

    // int real = 0;
    // int imaginary = 0;

    // cout << "Please Enter Real Value" << endl;

    // cin >> real;

    // cout << "Please Enter Imaginary Value" << endl;

    // cin >> imaginary;

    // Complex c1(10, -5);

    // // show result
    // c1.display();

    // Complex c2(2, -16);

    // c2.display();

    // // add complex one to another
    // Complex c3 = Complex::add(c1, c2);
    // c3.display();

    // // sub complex one to another
    // Complex c4 = Complex::sub(c3, c2);
    // c4.display();

    return 0;
}