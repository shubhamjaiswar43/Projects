#ifndef iostream
#include <iostream>
#endif
#ifndef cmath
#include <cmath>
#endif
#ifndef PI
#define PI 3.1415
#endif
class Complex
{
    float Re, Im, r, theta;

public:
    friend Complex modulusOf(Complex);
    Complex() : Re(0), Im(0) {
        r = sqrt(Re * Re + Im * Im);
        theta = (atan2(Im,Re))*180/PI;
    }
    Complex(int x) : Re(x), Im(0) {}
    Complex(int x, int y) : Re(x), Im(y)
    {
        r = sqrt(Re * Re + Im * Im);
        theta = (atan2(Im,Re))*180/PI;
    }
    void setRe(int x)
    {
        Re = x;
        r = sqrt(Re * Re + Im * Im);
        theta = (atan2(Im,Re))*180/PI;
    }
    void setIm(int y)
    {
        Im = y;
        r = sqrt(Re * Re + Im * Im);
        theta = (atan2(Im,Re))*180/PI;
    }
    void setBoth(int x, int y)
    {
        Re = x;
        Im = y;
        r = sqrt(Re * Re + Im * Im);
        theta = (atan2(Im,Re))*180/PI;
    }
    void EsetBoth(int r,int theta){//E->Euler Form
        this->r = r;
        this->theta = theta;
        if(theta==90){
            Re = 0;
            Im = r;
        }
        else{
        Re = r*(cos(theta*PI/180));
        Im = r*(sin(theta*PI/180));
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
    void Eshow()//E->Euler Form
    {
        std::cout << "(" << r << "),(" << theta << ")" ;
    }
    Complex operator+(Complex ob)
    {
        Complex temp;
        temp.Re = Re + ob.Re;
        temp.Im = Im + ob.Im;
        temp.r = sqrt(pow(temp.Re,2)+pow(temp.Im,2));
        temp.theta = (atan2(temp.Im,temp.Re))*180/PI;
        return temp;
    }
    Complex operator-(Complex ob)
    {
        Complex temp;
        temp.Re = Re - ob.Re;
        temp.Im = Im - ob.Im;
        temp.r = sqrt(pow(temp.Re,2)+pow(temp.Im,2));
        temp.theta = (atan2(temp.Im,temp.Re))*180/PI;
        return temp;
    }
    Complex operator*(Complex ob)
    {
        Complex temp;
        temp.Re = (Re * ob.Re) - (Im * ob.Im);
        temp.Im = (Im * ob.Re) + (Re * ob.Im);
        temp.r = sqrt(pow(temp.Re,2)+pow(temp.Im,2));
        temp.theta = (atan2(temp.Im,temp.Re))*180/PI;
        return temp;
    }
    Complex operator/(Complex ob)
    {
        Complex temp;
        temp.Re = ((Re * ob.Re) + (Im * ob.Im)) / ((ob.Re * ob.Re) + (ob.Im * ob.Im));
        temp.Im = ((ob.Re * Im) - (ob.Im * Re)) / ((ob.Re * ob.Re) + (ob.Im * ob.Im));
        temp.r = sqrt(pow(temp.Re,2)+pow(temp.Im,2));
        temp.theta = (atan2(temp.Im,temp.Re))*180/PI;
        return temp;
    }
    Complex modulus(){
        Complex temp;
        temp.Re=Re;
        temp.Im=(-Im);
        temp.r = sqrt(pow(temp.Re,2)+pow(temp.Im,2));
        temp.theta = (atan2(temp.Im,temp.Re))*180/PI;
    }
};
Complex modulusOf(Complex x){
    Complex temp;
    temp.Re=x.Re;
    temp.Im=(-x.Im);
    temp.r = sqrt(pow(temp.Re,2)+pow(temp.Im,2));
    temp.theta = (atan2(temp.Im,temp.Re))*180/PI;
    return temp;
}