#ifndef iostream
#include <iostream>
#endif
#ifndef cmath
#include <cmath>
#endif
#ifndef PI
#define PI 3.1415 // defining pi(because it is use for conversion of cartesian form to polar form)
#endif
class Complex
{
    float Re, Im, r, theta; // variable for complex number

public:
    friend Complex modulusOf(Complex); // making modulusOf function a friend function of complex(by which the function can access private variable of complex)
    Complex() : Re(0), Im(0)
    {
        r = sqrt(Re * Re + Im * Im);
        theta = (atan2(Im, Re)) * 180 / PI;
    }
    Complex(int x) : Re(x), Im(0) {}
    Complex(int x, int y) : Re(x), Im(y)
    {
        r = sqrt(Re * Re + Im * Im);
        theta = (atan2(Im, Re)) * 180 / PI;
    }
    void setRe(int x)
    {
        Re = x;
        r = sqrt(Re * Re + Im * Im);
        theta = (atan2(Im, Re)) * 180 / PI;
    }
    void setIm(int y)
    {
        Im = y;
        r = sqrt(Re * Re + Im * Im);
        theta = (atan2(Im, Re)) * 180 / PI;
    }
    void setBoth(int x, int y)
    {
        Re = x;
        Im = y;
        r = sqrt(Re * Re + Im * Im);
        theta = (atan2(Im, Re)) * 180 / PI;
    }
    void EsetBoth(int r, int theta)
    { // E->Euler Form(i.e polar form)
        this->r = r;
        this->theta = theta;
        if (theta == 90)
        {
            Re = 0;
            Im = r;
        }
        else
        {
            Re = r * (cos(theta * PI / 180));
            Im = r * (sin(theta * PI / 180));
        }
    }

    float Real() { return Re; }
    float Imaginary() { return Im; }
    float dist() { return r; }
    float angle() { return theta; }
    void show()
    {
        if (Im < 0 && Im != (-1))
        {
            std::cout << Re << Im << "i";
        }
        else if (Im == 1)
        {
            std::cout << Re << "+i";
        }
        else if (Im == -1)
        {
            std::cout << Re << "-i";
        }
        else
        {
            std::cout << Re << "+" << Im << "i";
        }
    }
    void Eshow() // E->Euler Form
    {
        std::cout << "(" << r << "),(" << theta << ")";
    }
    Complex operator+(Complex ob) // For addition of complex number
    {
        Complex temp;
        temp.Re = Re + ob.Re;
        temp.Im = Im + ob.Im;
        temp.r = sqrt(pow(temp.Re, 2) + pow(temp.Im, 2));
        temp.theta = (atan2(temp.Im, temp.Re)) * 180 / PI;
        return temp;
    }
    Complex operator-(Complex ob) // for subtraction
    {
        Complex temp;
        temp.Re = Re - ob.Re;
        temp.Im = Im - ob.Im;
        temp.r = sqrt(pow(temp.Re, 2) + pow(temp.Im, 2));
        temp.theta = (atan2(temp.Im, temp.Re)) * 180 / PI;
        return temp;
    }
    Complex operator*(Complex ob) // for multiplication
    {
        Complex temp;
        temp.Re = (Re * ob.Re) - (Im * ob.Im);
        temp.Im = (Im * ob.Re) + (Re * ob.Im);
        temp.r = sqrt(pow(temp.Re, 2) + pow(temp.Im, 2));
        temp.theta = (atan2(temp.Im, temp.Re)) * 180 / PI;
        return temp;
    }
    Complex operator/(Complex ob) // for division
    {
        Complex temp;
        temp.Re = ((Re * ob.Re) + (Im * ob.Im)) / ((ob.Re * ob.Re) + (ob.Im * ob.Im));
        temp.Im = ((ob.Re * Im) - (ob.Im * Re)) / ((ob.Re * ob.Re) + (ob.Im * ob.Im));
        temp.r = sqrt(pow(temp.Re, 2) + pow(temp.Im, 2));
        temp.theta = (atan2(temp.Im, temp.Re)) * 180 / PI;
        return temp;
    }
    Complex modulus() // for modulus
    {
        Complex temp;
        temp.Re = Re;
        temp.Im = (-Im);
        temp.r = sqrt(pow(temp.Re, 2) + pow(temp.Im, 2));
        temp.theta = (atan2(temp.Im, temp.Re)) * 180 / PI;
    }
};
Complex modulusOf(Complex x)
{
    Complex temp;
    temp.Re = x.Re;
    temp.Im = (-x.Im);
    temp.r = sqrt(pow(temp.Re, 2) + pow(temp.Im, 2));
    temp.theta = (atan2(temp.Im, temp.Re)) * 180 / PI;
    return temp;
}