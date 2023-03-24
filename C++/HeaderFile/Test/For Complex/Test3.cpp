#include <iostream>
#include "Complex.hpp"
using namespace std;
int main()
{
    Complex x(1, 7), y(2, -1), z;

    cout << "x : ";
    x.show();
    cout << endl;

    cout << "y : ";
    y.show();
    cout << endl;

    z = x / (y * y);
    cout << "x/(y*y) : ";
    z.show();
    cout << endl;

    z = modulusOf(y);
    cout << "modulusOf(y) : ";
    z.show();
    cout << endl;

    z = modulusOf(y*y);
    cout << "modulusOf(y*y) : ";
    z.show();
    cout << endl;
    
    //TEST PASSED
    return 0;
}