#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
int i, j, k, size = 0;
char username[] = "shubham43";
char password[] = "shubham@43";
struct patient
{
    char firstName[19];
    char lastName[19];
    char gender[19];
    char age[5];
    char add[19];
    char phoneNo[10];
    char bedNo[9];
    char disease[19];
    char doctorName[19];
};
struct patient data[99];
void line()
{
    printf("\t\t");
    for (i = 0; i <= 45; i++)
    {
        printf("#");
    }
}
void load()
{
    printf("\t\tLoading");
    for (i = 0; i < 6; i++)
    {
        printf(",");
        Sleep(100);
    }
}
void screen()
{
    system("cls");
    printf("\n\n\n");
    line();
    printf("\n\t\t\t  HOSPITAL MANAGEMENT SYSTEM\n");
    line();
    printf("\n\t\tPress Any Key to continue!");
    getch();
}
void signup()
{
    system("cls");
    printf("\n\n\n");
    line();
    printf("\n\t\t\t\t   Sign Up\n");
    line();
    printf("\n\n\n\t\tEnter Your Username : ");
    scanf("%s", &username);
    printf("\n\t\tEnter Your Password : ");
    scanf("%s", &password);
}
void login()
{
    char tempid[13], tempPass[13];
    int idchk, passchk;
start:
    system("cls");
    printf("\n\n\n");
    line();
    printf("\n\t\t\t\t   LOGIN\n");
    line();
    printf("\n\n\n\t\tEnter Your Username : ");
    scanf("%s", &tempid);
    printf("\t\tEnter Your Password : ");
    scanf("%s", &tempPass);
    if (!(strcmp(username, tempid) || strcmp(password, tempPass)))
    {
        system("cls");
        printf("\n\n\n");
        line();
        printf("\n\t\t\t\tLOGIN SUCCESSFULLY\n");
        line();
        getch();
    }
    else
    {
        printf("\n\t\tIncorrect Username or Password\n\t\tTry Again");
        getch();
        goto start;
    }
}
int operation()
{
    int op;
    system("cls");
    printf("\n\n");
    printf("\n\t\tEnter 0 : For Save New Data");
    printf("\n\t\tEnter 1 : For See Data");
    printf("\n\t\tEnter 2 : For Edit Data");
    printf("\n\t\tEnter 3 : For Search Data");
    printf("\n\t\tEnter 4 : For Delete Data");
    printf("\n\t\tEnter 5 : For Log Out");
    printf("\n\t\tEnter 6 : For Exit\n\t\t");
    scanf("%d", &op);
    load();
    return op;
}
void saveData()
{
    int n;
    printf("\n\t\tEnter How Many Patient data is you want to entered : ");
    scanf("%d", &n);
    for (i = size; i < (n + size); i++)
    {
        printf("\n\t\t\tEnter Patient No.%d Information", i + 1);
        printf("\n\t\tFirst Name : ");
        scanf("%s", &data[i].firstName);
        printf("\n\t\tLast Name : ");
        scanf("%s", &data[i].lastName);
        printf("\n\t\tGender(Male/Female/Transgender) : ");
        scanf("%s", &data[i].gender);
        printf("\n\t\tAge : ");
        scanf("%s", &data[i].age);
        printf("\n\t\tAddress(Only Area Name) : ");
        scanf("%s", &data[i].add);
        printf("\n\t\tContact No. : ");
        scanf("%s", &data[i].phoneNo);
        printf("\n\t\tBed No. : ");
        scanf("%s", &data[i].bedNo);
        printf("\n\t\tDisease : ");
        scanf("%s", &data[i].disease);
        printf("\n\t\tDoctor Prescribed : ");
        scanf("%s", &data[i].doctorName);
    }
    size += n;
    getch();
}
void seeData()
{
    if (size == 0)
    {
        printf("\n\t\tNo Data is Present");
    }
    else
    {
        for (i = 0; i < size; i++)
        {
            printf("\n\n\t\tPatient No.%d : ", i + 1);
            printf("\n\t\tName : %s %s", data[i].firstName, data[i].lastName);
            printf("\n\t\tGender : %s", data[i].gender);
            printf("\n\t\tAge : %s", data[i].age);
            printf("\n\t\tAddress : %s", data[i].add);
            printf("\n\t\tContact No. : %s", data[i].phoneNo);
            printf("\n\t\tBed No. : %s", data[i].bedNo);
            printf("\n\t\tDisease : %s", data[i].disease);
            printf("\n\t\tDoctor Prescribed : %s", data[i].doctorName);
            getch();
        }
    }
    getch();
}
void show(int n)
{
    printf("\n\n\t\tPatient No%d : ", n + 1);
    printf("\n\t\tName : %s %s", data[n].firstName, data[n].lastName);
    printf("\n\t\tGender : %s ", data[n].gender);
    printf("\n\t\tAge : %s", data[n].age);
    printf("\n\t\tAddress : %s", data[n].add);
    printf("\n\t\tContact No. : %s", data[n].phoneNo);
    printf("\n\t\tBed No. : %s", data[n].bedNo);
    printf("\n\t\tDisease : %s", data[n].disease);
    printf("\n\t\tDoctor Prescribed : %s", data[n].doctorName);
    getch();
}
void editData()
{
    char tbedNo[9];
    int chk = 0;
    if (size == 0)
    {
        printf("\n\t\tNo data is present");
    }
    else
    {
        printf("\n\t\tEnter the Bed No. of the patient whose data is to be edit : ");
        scanf("%s", &tbedNo);
        for (i = 0; i < size; i++)
        {
            if (!(strcmp(tbedNo, data[i].bedNo)))
            {
                printf("\n\t\tPrevious Data : ");
                show(i);
                printf("\n\n\t\tEnter New Data : ");
                printf("\n\t\tFirst Name : ");
                scanf("%s", data[i].firstName);
                printf("\n\t\tLast Name : ");
                scanf("%s", data[i].lastName);
                printf("\n\t\tGender(Male/Female/Other) : ");
                scanf("%s", data[i].gender);
                printf("\n\t\tAge : ");
                scanf("%s", data[i].age);
                printf("\n\t\tAddress : ");
                scanf("%s", data[i].add);
                printf("\n\t\tContact No. : ");
                scanf("%s", data[i].phoneNo);
                printf("\n\t\tBed No. : ");
                scanf("%s", data[i].bedNo);
                printf("\n\t\tDisease : ");
                scanf("%s", data[i].disease);
                printf("\n\t\tDoctor Prescribed : ");
                scanf("%s", data[i].doctorName);
                break;
            }
            chk++;
            if (chk == size)
            {
                printf("\n\t\tNo such Bed No. is Found\n\t\tTry Again Later");
            }
        }
    }
    getch();
}
void searchData()
{
    char tbedNo[19];
    int chk = 0;
    if (size == 0)
    {
        printf("\n\t\tNo data is present");
    }
    else
    {
        printf("\n\t\tEnter the Bed No. of the patient : ");
        scanf("%s", &tbedNo);
        for (i = 0; i < size; i++)
        {
            if (!(strcmp(tbedNo, data[i].bedNo)))
            {
                show(i);
                chk++;
            }
        }
        if (!chk)
        {
            printf("\n\t\tNo such Bed No. is Found\n\t\tTry Again Later");
        }
    }
    getch();
}
void deleteData()
{
    char tbedNo[19];
    int confirm = -1;
    if (size == 0)
    {
        printf("\n\t\tNo data is present");
    }
    else
    {
        printf("\n\t\tEnter the Bed No. of the patient : ");
        scanf("%s", &tbedNo);
        for (i = 0; i < size; i++)
        {
            if (!(strcmp(tbedNo, data[i].bedNo)))
            {
                printf("\n\t\tPrevious Data : ");
                show(i);
                printf("\n\n\t\tEnter 0 for confirm delete and 1 for not confirm : ");
                scanf("%s", &confirm);
                break;
            }
        }
        if (confirm == -1)
        {
            printf("\n\t\tNo Such Bed No. is Found\n\t\tTry Again Later...");
        }
        else if (!confirm)
        {
            confirm = i;
            for (i = confirm; i < size; i++)
            {
                strcpy(data[i].firstName, data[i + 1].firstName);
                strcpy(data[i].lastName, data[i + 1].lastName);
                strcpy(data[i].gender, data[i + 1].gender);
                strcpy(data[i].age, data[i + 1].age);
                strcpy(data[i].add, data[i + 1].add);
                strcpy(data[i].phoneNo, data[i + 1].phoneNo);
                strcpy(data[i].bedNo, data[i + 1].bedNo);
                strcpy(data[i].disease, data[i + 1].disease);
                strcpy(data[i].doctorName, data[i + 1].doctorName);
                printf("\n\t\tData deleted successfully");
            }
            size--;
        }
    }
    getch();
}
int main()
{
    int op;
    system("cls");
    screen();
    signup();
Login:
    screen();
    login();
Operation:
    op = operation();
    switch (op)
    {
    case 0:
        saveData();
        goto Operation;
    case 1:
        seeData();
        goto Operation;
    case 2:
        editData();
        goto Operation;
    case 3:
        searchData();
        goto Operation;
    case 4:
        deleteData();
        goto Operation;
    case 5:
        system("cls");
        goto Login;
    case 6:
        printf("\n\t\tExiting");
        for (i = 0; i < 6; i++)
        {
            printf(".");
            Sleep(150);
        }
        // exit();
        break;
    default:
        printf("\n\t\tInvalid Entry\n\t\tTry Again");
        goto Operation;
    }
    getch();
    return 0;
}