#include<iostream>
using namespace std;

int main()
{
    //int I=1,V=5,X=10,L=50,C=100,D=500,M=1000;
    int num=0;
    string st;
    input:
    cout<<"Enter a Roman Number : ";
    cin>>st;//Taking input for the roman no.
    int n=st.size();
    int arr[n];//array for value of the roman no. at every index
    for(int i=0;i<n;i++){
        switch(st[i]){
            case 'I':
                arr[i]=1;
                break;
            case 'V':
                arr[i]=5;
                break;
            case 'X':
                arr[i]=10;
                break;
            case 'L':
                arr[i]=50;
                break;
            case 'C':
                arr[i]=100;
                break;
            case 'D':
                arr[i]=500;
                break;
            case 'M':
                arr[i]=1000;
                break;
            default:
                cout<<"Invalid Input!!!\nTry Again...\n"<<endl;
            goto input;
        }
    }
    for(int i=0;i<n;i++){//converting to decimal number
        if(i<n-1){
            if(arr[i]<arr[i+1])
                num-=arr[i];
            else
                num+=arr[i];
        }
        else
            num+=arr[i];
    }
    cout<<"Number("<<st<<") : "<<num<<endl;//printing the decimal number
    return 0;
}