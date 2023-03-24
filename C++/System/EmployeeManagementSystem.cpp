#include <iostream>
#include <windows.h>
#include <vector>
using namespace std;
string username, password;
class Employee
{
private:
    string name, salary, id, address, contact;

public:
    Employee(string n, string tid, string a, string c, string s)
    {
        name = n;
        salary = s;
        id = tid;
        contact = c;
        address = a;
    }
    void showdata()
    {
        cout << "\n\t\t Name : " << name;
        cout << "\n\t\t Id : " << id;
        cout << "\n\t\t Address : " << address;
        cout << "\n\t\t Contact : " << contact;
        cout << "\n\t\t Salary : " << salary;
        cout << endl;
    }
    string rtid()
    {
        string tid = id;
        return id;
    }
    void changeData(string n, string tid, string a, string c, string s)
    {
        name = n;
        salary = s;
        id = tid;
        contact = c;
        address = a;
    }
};
vector<Employee> data;
void loading()
{
    cout << "\n\t\tLoading";
    for (int i = 0; i < 5; i++)
    {
        cout << ".";
        Sleep((100) - (20 * i));
    }
}
void heading()
{
    loading();
    system("cls");
    cout << "\n\n\t\tEMPLOYEE MANAGEMENT SYSTEM\n\n";
}
void signup()
{
    cout << "\n\t\t****Sign up****";
    cout << "\n\t\tEnter New Username : ";
    cin >> username;
    cout << "\t\tEnter New Password : ";
    cin >> password;
    cout << "\t\tCreating New Id";
    for (int i = 0; i < 5; i++)
    {
        cout << ".";
        Sleep((1000) - (200 * i));
    }
    cout << "\n\t\tsign up successfully";
}
void login()
{
    string tusername, tpassword;
login:
    cout << "\n\t\tLOGIN";
    cout << "\n\t\tEnter Username : ";
    cin >> tusername;
    cout << "\t\tEnter Password : ";
    cin >> tpassword;
    if (tusername != username && tpassword != password)
    {
        cout << "\t\tIncorrect Username and Password\n\t\tTry Again....";
        goto login;
    }
    else if (tusername != username)
    {
        cout << "\t\tIncorrect Username\n\t\tTry Again.....";
        goto login;
    }
    else if (tpassword != password)
    {
        cout << "\t\tIncorrect Password\n\t\tTry Again.....";
        goto login;
    }
    else
    {
        cout << "\t\tLogin Successfully\n";
    }
}
int mainScreen()
{
    int operation;
    cout << "\n\t\tEnter 1: For Enter Data ";
    cout << "\n\t\tEnter 2: For Show Data ";
    cout << "\n\t\tEnter 3: For Search Data";
    cout << "\n\t\tEnter 4: For Update Data";
    cout << "\n\t\tEnter 5: For Delete Data";
    cout << "\n\t\tEnter 6: For LogOut";
    cout << "\n\t\tEnter 7: For Exit\n\t\t";
    cin >> operation;
    return operation;
}
void dataInsertion()
{
    int size;
    cout << "\n\t\tEnter How Many Employee's Data is to be Entered : ";
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        string name, id, add, cont, sal;
        cout << "\n\t\tEnter Name of Employee No." << i + 1 << " : ";
        cin >> name;
        cout << "\n\t\tEnter Id of Employee No." << i + 1 << " : ";
        cin >> id;
        getchar();
        cout << "\n\t\tEnter Address of Employee No." << i + 1 << " : ";
        getline(cin, add);
        cout << "\n\t\tEnter Contact No. of Employee No." << i + 1 << " : ";
        cin >> cont;
        cout << "\n\t\tEnter Salary of Employee No." << i + 1 << " : ";
        cin >> sal;
        Employee temp(name, id, add, cont, sal);
        data.push_back(temp);
    }
}
void dataVisiblity()
{
    if (data.size() == 0)
    {
        cout << "\n\t\tNo data is present...";
        Sleep(1000);
    }
    else
    {
        for (int i = 0; i < data.size(); i++)
        {
            cout << "\n\t\tEmployee No." << i + 1;
            data[i].showdata();
            getchar();
            cout << endl;
        }
    }
}
void dataSearching()
{
    if (data.size() == 0)
    {
        cout << "\n\t\tNo data is present...";
        Sleep(1000);
    }
    else
    {
        string tid;
        int temp = 0;
        cout << "\n\t\tEnter the Id of the Employee whose data is to be search : ";
        cin >> tid;
        for (int i = 0; i < data.size(); i++)
        {
            if (tid == data[i].rtid())
            {
                data[i].showdata();
                temp++;
                getchar();
                break;
            }
        }
        if (temp == 0)
        {
            cout << "\n\t\tNo Employee with Entered Id is Found";
            Sleep(2000);
            getchar();
        }
    }
}
void dataUpdatation()
{
    if (data.size() == 0)
    {
        cout << "\n\t\tNo data is present...";
        Sleep(1000);
    }
    else
    {
        string tid;
        int temp = 0;
        cout << "\n\t\tEnter the Id of the Employee which data is to be update : ";
        cin >> tid;
        for (int i = 0; i < data.size(); i++)
        {
            if (tid == data[i].rtid())
            {
                string name, id, add, cont, sal;
                cout << "\n\t\tEnter Name of Employee No." << i + 1 << " : ";
                cin >> name;
                cout << "\n\t\tEnter Id of Employee No." << i + 1 << " : ";
                cin >> id;
                getchar();
                cout << "\n\t\tEnter Address of Employee No." << i + 1 << " : ";
                getline(cin, add);
                cout << "\n\t\tEnter Contact No. of Employee No." << i + 1 << " : ";
                cin >> cont;
                cout << "\n\t\tEnter Salary of Employee No." << i + 1 << " : ";
                cin >> sal;
                data[i].changeData(name, id, add, cont, sal);
                temp++;
                getchar();
                break;
            }
        }
        if (temp == 0)
        {
            cout << "\n\t\tNo Employee with Entered Id is Found";
            Sleep(2000);
            getchar();
        }
    }
}
void dataDeletion()
{
    if (data.size() == 0)
    {
        cout << "\n\t\tNo data is present...";
        Sleep(1000);
    }
    else
    {
        string tid;
        int temp = 0;
        cout << "\n\t\tEnter the Id of the Employee whose data is to be deleted : ";
        cin >> tid;
        for (int i = 0; i < data.size(); i++)
        {
            if (tid == data[i].rtid())
            {
                data.erase(data.begin() + i);
                temp++;
                cout << "\n\t\tData of the Employee is Deleted Successfully";
                getchar();
                break;
            }
        }
        if (temp == 0)
        {
            cout << "\n\t\tNo Employee with Entered Id is Found";
            Sleep(2000);
            getchar();
        }
    }
}
int main()
{
    heading();
    signup();
    heading();
Login:
    login();
    heading();
    int operater;
operation:
    operater = mainScreen();
    switch (operater)
    {
    case 0:
        cout << "\n\t\tInvalid";
        goto operation;
    case 1:
        dataInsertion();
        heading();
        goto operation;
        break;

    case 2:
        dataVisiblity();
        heading();
        goto operation;
        break;

    case 3:
        dataSearching();
        heading();
        goto operation;
        break;

    case 4:
        dataUpdatation();
        heading();
        goto operation;
        break;

    case 5:

        dataDeletion();
        heading();
        goto operation;
        break;

    case 6:

        heading();
        cout << "\n\t\tLoging Out";
        for (int i = 0; i < 5; i++)
        {
            cout << ".";
            Sleep((1000) - (200 * i));
        }
        heading();
        goto Login;
        break;

    case 7:
        cout << "\n\t\tExiting the System";
        for (int i = 0; i < 5; i++)
        {
            cout << ".";
            Sleep((1000) - (200 * i));
        }
        goto end;
        break;

    default:
        cout << "\n\t\tInvalid Entry\n\t\tTry Again....";
        goto operation;
        break;
    }
end:
    return 0;
}