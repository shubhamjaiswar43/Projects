#include<iostream>
#include<maths.hpp>
using namespace std;
int main(){
    double x,y;
    cout<<"Enter Two Numbers : "<<endl;
    cin>>x>>y;
    cout<<endl;
    cout<<"absolute(x) : "<<absolute(x)<<endl;
    cout<<"power(x,2) : "<<power(x,2)<<endl;
    cout<<"factorial((int)x) : "<<factorial((int)x)<<endl;
    cout<<"permutation(5,3) : "<<permutation(5,3)<<endl;
    cout<<"combination(5,3) : "<<combination(5,3)<<endl;
    cout<<"sine(x) : "<<sine(x)<<endl;
    cout<<"cosine(x) : "<<cosine(x)<<endl;
    cout<<"tangent(x) : "<<tangent(x)<<endl;
    cout<<"cosecant(x) : "<<cosecant(x)<<endl;
    cout<<"secant(x) : "<<secant(x)<<endl;
    cout<<"cotangent(x) : "<<cotangent(x)<<endl;
    cout<<"logBaseE(x) : "<<logBaseE(x)<<endl;
    cout<<"exponent(x) : "<<exponent(x)<<endl;
    cout<<"squareRoot(x) : "<<squareRoot(x)<<endl;
    cout<<"logXbaseY(x,y) : "<<logXbaseY(x,y)<<endl;
    cout<<"xRaiseToy(x,y) : "<<xRaiseToy(x,y)<<endl;
    
    return 0;
}