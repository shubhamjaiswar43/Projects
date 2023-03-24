#include"Complex.hpp"
#include<iostream>
using namespace std;
int main(){
    Complex z1(1,-1),z2;
    // cout<<"(";
    // z1.show();
    // cout<<" = ";
    // z1.Eshow();
    // cout<<endl;
    // z1.setRe(0);
    // z1.show();
    // cout<<" = ";
    // z1.Eshow();
    // cout<<endl;
    // z1.setIm(0);
    // z1.show();
    // cout<<" = ";
    // z1.Eshow();
    //
    cout<<"z1 = ";
    z1.show();
    cout<<" = ";
    z1.Eshow();
    cout<<endl;
    z2.setBoth(1,1);
    cout<<"z2 = ";
    z2.show();
    cout<<" = ";
    z2.Eshow();
    cout<<endl;
    Complex z;

    z=z1+z2;
    cout<<"z1 + z2 = ";
    z.show();
    cout<<" = ";
    z.Eshow();
    cout<<endl;

    z=z1-z2;
    cout<<"z1 - z2 = ";
    z.show();
    cout<<" = ";
    z.Eshow();
    cout<<endl;

    z=z1*z2;
    cout<<"z1 * z2 = ";
    z.show();
    cout<<" = ";
    z.Eshow();
    cout<<endl;

    z=z1/z2;
    cout<<"z1 / z2 = ";
    z.show();
    cout<<" = ";
    z.Eshow();
    cout<<endl;

    //TEST PASSED
    return 0;
}