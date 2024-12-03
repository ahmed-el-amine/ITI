#include <iostream>

using namespace std;


class Complex {
    int real = 0;
    int imaginary = 0;

    public:
    Complex(int realData, int imgData) {
        this->real = realData;
        this->imaginary = imgData;
    }
    void setReal(int realData) {
        this->real = realData;
    }
    int getReal() {
        return real;
    }
    // 
    void setImg(int imgData) {
        this->imaginary = imgData;
    }
    int getImg() {
        return this->imaginary;
    }
    // 
    void fastSet(int realData, int imgData)
    {
        this->real = realData;
        this->imaginary = imgData;
    }

    void display() {
        if (real == 0 && imaginary == 0)
        {
            cout << "0";
            return;
        }

        if (real != 0) cout << real;
        if (imaginary > 0) cout << real << "+" << imaginary << "j" << endl;
        else if (imaginary < 0) cout << imaginary << "j" << endl;


        // if (real == 0 && imaginary != 0) cout << imaginary << "j" << endl;
        // else if (real == 0 && imaginary == 0) cout << "No Data" << endl;
        // else if (imaginary > 0) cout << real << "+" << imaginary << "j" << endl;
        // else if (imaginary == 0) cout << real << endl;

        // if (real != 0) cout << real;

        // if (imaginary > 0) cout << real << "+" << imaginary << "j" << endl;
        // else if (imaginary < 0) cout << real << imaginary << "j" << endl;
        // else cout << real << endl;

        // if (real == 0) cout << "No Data" << endl;
        // else if (imaginary == 0) cout << real << endl;


        // if (real == 0) {
        //     if (imaginary != 0) {
        //         cout << imaginary << "j" << endl;
        //     }
        //     else {
        //         cout << "No Data"<< endl;
        //     }
        // }
        // else {
        //     if (imaginary > 0) {
        //         cout << real << "+" << imaginary << "j" << endl;
        //     }
        //     else if (imaginary == 0) {
        //         cout << real << endl;
        //     }
        //     else cout << real << imaginary << "j" << endl;
        // }
    }
    
    ~ Complex() {
        cout << "Dist " << endl;
    }
};

Complex add(Complex complex1, Complex complex2)
{
    Complex result(complex1.getReal() + complex2.getReal(), complex1.getImg() + complex2.getImg());
    return result;
}

Complex sub(Complex complex1, Complex complex2)
{
    Complex result(complex1.getReal() - complex2.getReal(), complex1.getImg() - complex2.getImg());
    return result;
}

int main()
{
    int real = 0;
    int imaginary = 0;

    cout << "Please Enter Real Value" << endl;
    
    cin >> real;
    
    cout << "Please Enter Imaginary Value" << endl;

    cin >> imaginary;

    Complex c1(10, -5);

    // show result
    c1.display();

    Complex c2(2, -16);

    c2.display();

    // add complex one to another
    Complex c3 = add(c1, c2);
    c3.display();


    // sub complex one to another
    Complex c4 = sub(c3, c2);
    c4.display();


    return 0;
}