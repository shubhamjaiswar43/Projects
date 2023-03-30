#include <stdio.h>
/*  Fibonacci Series(sum of previous two number(starting with 0 and 1))
    0 1 1 2 3 5 8 13.......
*/
int count = 0, term[20], value[20];
int fib(int n)
{
    if (n == 1 || n == 2) // Base Condition Of Recursion
        return (n - 1);
    int b1, b2, c1 = 0, c2 = 0;
chk:
    for (int i = 0; i < count; i++)
    { // searching that,the required term is found or not
        if (term[i] == (n - 1))
        {
            b1 = value[i]; // if found that save it
            c1++;          // for checking further
        }
        else if (term[i] == (n - 2))
        {
            b2 = value[i]; // if found that save it
            c2++;          // for checking further
        }
    }
    if (!c1)
    { // If first required one not found then find it recursively
        b1 = fib(n - 1);
        term[count] = n - 1;
        value[count] = b1;
        count++;
        c1 = 1;
        goto chk; // going to chk again
    }
    if (!c2)
    { // If second required one not found then find it recursively
        b2 = fib(n - 2);
        term[count] = n - 2;
        value[count] = b2;
    }
    return (b1 + b2);
}
int main()
{
    int n;
    printf("Enter Which Term of fibonacci series is to be printed : ");
    scanf("%d", &n);
    printf("\nThe %d Term of the fibonacci series : %d", n, fib(n));
    return 0;
}