#include<iostream>
#include<vector.hpp>
#include<conio.h>
using namespace std;
int main(){
    vector<int> arr;
    cout<<"(size,capacity) = ("<<arr.size()<<","<<arr.capacity()<<")"<<endl;
    int size,temp;
    cout<<"Enter the size of the array : ";
    cin>>size;
    for (int i = 0; i < size; i++)
    {
        cout<<"Enter "<<i<<" : ";
        cin>>temp;
        arr.add(temp);
    }
    arr.show();
    cout<<"\nEnter the index to add a number to that : ";
    cin>>size;
    cout<<"Enter the element at that index : ";
    cin>>temp;
    arr.addAt(temp,size);
    arr.show();
    cout<<"\nEnter to delete last element : ";
    getche();
    arr.pop();
    cout<<endl;
    arr.show();
    cout<<"\nEnter a index to delete that element : ";
    cin>>size;
    arr.popAt(size);
    arr.show();
    return 0;
}