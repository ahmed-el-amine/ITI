#include <iostream>

using namespace std;


class Complex {
    int real = 0;
    int imaginary = 0;

    public:
    void setReal(int realData) {
        real = realData;
    }
    int getReal() {
        return real;
    }
    // 
    void setImg(int imgData) {
        imaginary = imgData;
    }
    int getImg() {
        return imaginary;
    }
    // 
    void fastSet(int realData, int imgData)
    {
        real = realData;
        imaginary = imgData;
    }
    //
    Complex add(Complex &complexWith)
    {
        Complex result;
        result.fastSet(real + complexWith.real, imaginary + complexWith.imaginary);
        return result;
    }
    Complex sub(Complex &complexWith)
    {
        Complex result;
        result.fastSet(real - complexWith.real, imaginary - complexWith.imaginary);
        return result;
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
};

int main()
{
    int real = 0;
    int imaginary = 0;

    cout << "Please Enter Real Value" << endl;
    
    cin >> real;
    
    cout << "Please Enter Imaginary Value" << endl;

    cin >> imaginary;

    Complex c1;

    // set one by one
    c1.setReal(10);
    c1.setImg(-5);

    // or set all at once
    c1.fastSet(-10, -5);

    // show result
    c1.display();

    Complex c2;
    c2.fastSet(2, -16);
    //imag only
    c2.display();

    // add complex one to another
    Complex c3 = c1.add(c2);
    c3.display();


    // sub complex one to another
    Complex c4 = c3.sub(c2);
    c4.display();


    return 0;
}