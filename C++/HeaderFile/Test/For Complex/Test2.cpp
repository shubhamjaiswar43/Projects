#include<iostream>
#include"Complex.hpp"
using namespace std;
int main(){
    Complex z1(1,1),z2(2,2),z3(3,3),z4(4,4),z;

    cout<<"z1 : ";
    z1.show();
    cout<<endl;

    cout<<"z2 : ";
    z2.show();
    cout<<endl;

    cout<<"z3 : ";
    z3.show();
    cout<<endl;

    cout<<"z4 : ";
    z4.show();
    cout<<endl;

    z = z1*z2*z3;
    cout<<"z1*z2*z3 : ";
    z.show();
    cout<<endl;
    
    z = z1/z2/z3; //this will execute as (z1/z2)/z3,bcoz preference is left to right for same operator
    cout<<"z1/z2/z3 : ";
    z.show();
    cout<<endl;
    
    z = z1/z2/z3/z4; //((z1/z2)/z3)/z4  ===> Order of Execution
    cout<<"z1/z2/z3/z4 : ";
    z.show();
    cout<<endl;

    z = z1*z2/z3*z4; //((z1*z2)/z3)*z4  ===> Order of Execution(left to right )
    cout<<"z1*z2/z3*z4 : ";
    z.show();
    cout<<endl;

    //TEST PASSED
    return 0;
}