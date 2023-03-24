#include <stdio.h>
int chkLeap(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        return 1;
    else
        return 0;
}
int rtNoOfLY(int y1, int y2)
{
    int y = 0;
    if (y1 > y2)
    {
        y1 = y1 + y2;
        y2 = y1 - y2;
        y1 = y1 - y2;
    }
    for (int i = y1; i < y2; i++)
    {
        if (chkLeap(i))
        {
            y += 1;
        }
    }
    return y;
}
int rtFirstDay(int year)
{
    if (year == 1900)
        return 1;
    int fd = 1, n; // 1900
    n = rtNoOfLY(1900, year);
    if (year > 1900)
    {
        fd += (n + (year - 1900));
        fd = fd % 7;
        return fd;
    }
    else
    {
        fd -= (n + (1900 - year));
        fd *= -1;
        fd = (fd % 7) - 1;
        return fd;
    }
}
void mnPrint(int year, char month[], int day, int Fday)
{
    printf("-------------  %s %d -------------\n\n", month, year);
    printf("Sun   Mon   Tue   Wed   Thu   Fri   Sat\n");
    for (int i = 0; i < Fday; i++)
    {
        printf("      ");
    }

    for (int i = 1; i <= day; i++)
    {
        if (i < 10)
            printf(" %d    ", i);
        else
            printf(" %d   ", i);
        if (Fday == 0)
        {
            if ((i % 7 == 0))
                printf("\n");
        }
        else
        {
            if (i % 7 == (7 - Fday))
                printf("\n");
        }
    }
    printf("\n\n");
}
void calender(int year)
{
    char month[12][10] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int day = 31, Fday = rtFirstDay(year);
    for (int i = 0; i < 12; i++)
    {
        mnPrint(year, month[i], day, Fday);
        Fday += day;
        Fday %= 7;
        if (i == 0)
        {
            if (chkLeap(year))
                day = 29;
            else
                day = 28;
        }
        else if (i == 1)
            day = 31;
        else if (i == 6)
            day = 31;
        else
            day = (day == 31) ? 30 : 31;
    }
}
int main()
{
    int year;
    printf("Enter the Year : ");
    scanf("%d", &year);
    calender(year);
    return 0;
}
/*
0=31
1=28/29
2=31
3=30
4=31
5=30
6=31
7=31
8=30
9=31
10=30
11=31
*/