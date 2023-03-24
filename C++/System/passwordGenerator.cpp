#include<iostream>
#include<time.h>
#include<vector>
using namespace std;
int main()
{
    srand(time(NULL)); //this will change the random value everytime it called;
    vector<char> password;
    int size;
    cout<<"Enter the size of the password : ";
    cin>>size;
    for (int i = 1; i < size; i++)
    {
        int temp=rand()%3;
        switch (temp)
        {
        case 0:
            password.push_back((rand()%26)+65);
            break;
        
        case 1:
            password.push_back((rand()%10)+48);
            break;

        case 2:
            password.push_back((rand()%26)+97);
            break;

        }
    }
    // adding a special character to make password more secure;
    password.insert(password.begin()+(rand()%password.size()),'@');
    for (int i = 0; i < password.size(); i++)
    {
        cout<<password[i];
    }
    cout<<endl;
    
    return 0;
}