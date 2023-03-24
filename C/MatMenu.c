#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int i, j, k, count = 0, p[10], q[10], ind, op1, op2, sv;
float **M[10];
// For saving a matrix into another.....
void MatCpy(float **x, float **y, int m, int n)
{
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
            *(*(x + i) + j) = *(*(y + i) + j);
    }
}
// For Declaration of a matrix
void MatDec(float ***x, int m, int n)
{
    *x = (float **)malloc(m * sizeof(float *));
    for (i = 0; i < m; i++)
        *(*x + i) = (float *)malloc(n * sizeof(float));
    count++;
}
// For Input of the matrix
void MatInp(float **x, int m, int n)
{
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
            scanf("%f", (*(x + i) + j));
    }
}
// For Printing of the matrix
void MatPrt(float **x, int m, int n, int ind)
{
    printf("\nMatrix(M%d(%dx%d)) : \n", ind, m, n);
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
            printf("%.2f\t", *(*(x + i) + j));
        printf("\n");
    }
    getch();
    printf("\n");
}
// Matrix Adddition
int MatAdd(float **x, float **y, int m1, int n1, int m2, int n2)
{
    float **temp;
    if ((m1 != m2) || (n1 != n2))
    {
        printf("Matrix Can't Be Add.\nTry Again Later...\n\n");
        getch();
        return -1;
    }
    MatDec(&temp, m1, n1);
    count--;
    for (i = 0; i < m1; i++)
    {
        for (j = 0; j < n1; j++)
        {
            *(*(temp + i) + j) = *(*(x + i) + j) + *(*(y + i) + j);
            printf("%.2f\t", *(*(temp + i) + j));
        }
        printf("\n");
    }
    printf("To Save this matrix press 1 else 0 : ");
    scanf("%d", &sv);
    if (sv == 1)
    {
        printf("Enter Matrix No. To Save in it : ");
        scanf("%d", &sv);
        if (sv > count)
            MatDec(&M[sv - 1], m1, n1);
        p[sv - 1] = m1;
        q[sv - 1] = n1;
        MatCpy(M[sv - 1], temp, m1, n1);
    }
    free(temp);
    return 1;
}
// Matrix Subtraction
int MatSub(float **x, float **y, int m1, int n1, int m2, int n2)
{
    float **temp;
    if ((m1 != m2) || (n1 != n2))
    {
        printf("Matrix Can't Be Subtract.\nTry Again Later...\n\n");
        getch();
        return -1;
    }
    MatDec(&temp, m1, n1);
    count--;
    for (i = 0; i < m1; i++)
    {
        for (j = 0; j < n1; j++)
        {
            *(*(temp + i) + j) = *(*(x + i) + j) - *(*(y + i) + j);
            printf("%.2f\t", *(*(temp + i) + j));
        }
        printf("\n");
    }
    printf("To Save this matrix press 1 else 0 : ");
    scanf("%d", &sv);
    if (sv == 1)
    {
        printf("Enter Matrix No. To Save in it : ");
        scanf("%d", &sv);
        if (sv > count)
            MatDec(&M[sv - 1], m1, n1);
        p[sv - 1] = m1;
        q[sv - 1] = n1;
        MatCpy(M[sv - 1], temp, m1, n1);
    }
    free(temp);
    return 1;
}
// Matrix Multiplication
int MatMul(float **x, float **y, int m1, int n1, int m2, int n2)
{
    float **temp;
    if (m2 != n1)
    {
        printf("Matrix Can't Be Multiply.\nTry Again Later...\n\n");
        getch();
        return -1;
    }
    MatDec(&temp, m1, n1);
    count--;
    for (i = 0; i < m1; i++)
    {
        for (j = 0; j < n2; j++)
        {
            *(*(temp + i) + j) = 0;
            for (k = 0; k < n1; k++)
            {
                *(*(temp + i) + j) += *(*(x + i) + k) * *(*(y + k) + j);
            }
            printf("%.2f\t", *(*(temp + i) + j));
        }
        printf("\n");
    }
    printf("To Save this matrix press 1 else 0 : ");
    scanf("%d", &sv);
    if (sv == 1)
    {
        printf("Enter Matrix No. To Save in it : ");
        scanf("%d", &sv);
        if (sv > count)
            MatDec(&M[sv - 1], m1, n1);
        p[sv - 1] = m1;
        q[sv - 1] = n1;
        MatCpy(M[sv - 1], temp, m1, n1);
    }
    free(temp);
    return 1;
}
// swap of integer
void swap(int *x, int *y)
{
    *x = *x + *y;
    *y = *x - *y;
    *x = *x - *y;
}
// for shift array 1st element into last for index of determinant
void arrShift(int arr[], int n)
{
    for (j = 0; j < (n - 1); j++)
    {
        swap(&arr[j], &arr[j + 1]);
    }
}
// return Determinant of a matrix
float RecDet(float **x, int n)
{
    float ans = 0, ps = 0, ng = 0;
    /*
    (00 11)+(01 10)-[(10 01)+(11 00)]
    (00 11 22)+(01 12 20)+(02 10 21)-[(20 11 02)+(21 12 00)+(22 10 01)]
    (00 11 22 33)+(01 12 23 30)+(02 13 20 31)+(03 10 21 32)-[(30 21 12 03)+(31 22 13 00)+(32 23 10 01)+(33 20 11 02)]
    */
    if (n == 2)
    {
        ps = *(*(x + 0) + 0) * *(*(x + 1) + 1);
        ng = *(*(x + 0) + 1) * *(*(x + 1) + 0);
        ans = ps - ng;
    }
    else
    {
        int temp[n];
        for (i = 0; i < n; i++)
            temp[i] = i;
        for (i = 0; i < n; i++)
        {
            float ps1 = 1, ng1 = 1;
            for (j = 0; j < n; j++)
            {
                ps1 *= *(*(x + j) + temp[j]);
                ng1 *= *(*(x + n - j - 1) + temp[j]);
            }
            arrShift(temp, n);
            ps += ps1;
            ng += ng1;
        }
        ans = ps - ng;
    }
    return ans;
}
// print determinant of matrix
int MatDet(float **x, int p, int q)
{
    float temp;
    if (p != q)
    {
        printf("Determinant Can't Be Calculated\nTry Again Later......\n");
        getch();
        return -1;
    }
    temp = RecDet(x, p);
    printf("%.2f\n", temp);
    getch();
    return 1;
}
// save inverse of matrix x in y
int RecInv(float **x, float **y, int n, float detX)
{

    if (n == 2)
    {
        // swapping 00 and 11(shortcut for adjacent)
        *(*(x + 0) + 0) = *(*(x + 0) + 0) + *(*(x + 1) + 1);
        *(*(x + 1) + 1) = *(*(x + 0) + 0) - *(*(x + 1) + 1);
        *(*(x + 0) + 0) = *(*(x + 0) + 0) - *(*(x + 1) + 1);

        // changing sign of 01 and 10 (shortcut for adjacent)
        *(*(x + 0) + 1) *= (-1);
        *(*(x + 1) + 0) *= (-1);

        // dividing by det for inverse
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                *(*(x + i) + j) /= detX;
                *(*(y + i) + j) = *(*(x + i) + j);
            }
        }
    }
    // Performing General Operation In Identity Matrix For Inverse of Given Matrix
    else
    {
        for (i = 0; i < n; i++)
        {
            for (j = i; j < n; j++)
            {
                int temp = *(*(x + i) + i);
                *(*(x + i) + j) /= temp;
                *(*(y + i) + j) /= temp;
                for (k = i + 1; k < n; k++)
                {
                    int temp = *(*(x + k) + i);
                    *(*(x + k) + j) -= temp * *(*(x + i) + j);
                    *(*(y + k) + j) -= temp * *(*(y + i) + j);
                }
            }
            // printf("\nTemp : \n");
            // MatPrt(y,n,n,0);
            // printf("\n");
            for (j = i; j < n; j++)
            {
                for (k = i + 1; k < n; k++)
                {
                    int temp = *(*(x + i) + k);
                    *(*(x + j) + k) -= temp * *(*(x + k) + i);
                    *(*(y + j) + k) -= temp * *(*(y + k) + i);
                }
            }
        }
    }
    return 1;
}
int MatInv(float **x, int m1, int n1)
{
    // printf("\np : %d,q : %d\n",p,q);
    if (m1 != n1)
    {
        printf("Inverse is not possible!!!\nTry Again Later....\n");
        return -1;
    }
    float detX = RecDet(x, m1);
    int detXx = RecDet(x, m1);
    // printf("\ndetX : %.2f,detXx : %d\n",detX,detXx);
    if (detXx == 0)
    {

        printf("Inverse is not possible!!!\nTry Again Later....\n");
        return -1;
    }
    float **temp;
    MatDec(&temp, m1, n1);
    count--;
    for (i = 0; i < m1; i++)
    {
        for (j = 0; j < n1; j++)
        {
            if (i == j)
                *(*(temp + i) + j) = 1;
            else
                *(*(temp + i) + j) = 0;
        }
    }
    RecInv(x, temp, m1, detX);
    for (i = 0; i < m1; i++)
    {
        for (j = 0; j < n1; j++)
        {
            printf("%.2f\t", *(*(temp + i) + j));
        }
        printf("\n");
    }
    printf("To Save this matrix press 1 else 0 : ");
    scanf("%d", &sv);
    if (sv == 1)
    {
        printf("Enter Matrix No. To Save in it : ");
        scanf("%d", &sv);
        if (sv > count)
            MatDec(&M[sv - 1], m1, n1);
        p[sv - 1] = m1;
        q[sv - 1] = n1;
        MatCpy(M[sv - 1], temp, m1, n1);
    }
    free(temp);
    return 1;
}
// Transpose of a matrix
int MatTrans(float **x, int m1, int n1)
{
    float **temp;
    MatDec(&temp, m1, n1);
    count--;
    for (i = 0; i < m1; i++)
    {
        for (j = 0; j < n1; j++)
        {
            *(*(temp + i) + j) = *(*(x + j) + i);
            printf("%.2f\t", *(*(temp + i) + j));
        }
        printf("\n");
    }
    printf("To Save this matrix press 1 else 0 : ");
    scanf("%d", &sv);
    if (sv == 1)
    {
        printf("Enter Matrix No. To Save in it : ");
        scanf("%d", &sv);
        if (sv > count)
            MatDec(&M[sv - 1], m1, n1);
        p[sv - 1] = m1;
        q[sv - 1] = n1;
        MatCpy(M[sv - 1], temp, m1, n1);
    }
    free(temp);
    return 1;
}
// to clear memory allocated in heap
void MatClr()
{
    for (i = 0; i < 10; i++)
        free(M[i]);
}
int main()
{
    int op = 0;
    while (1)
    {
        printf("\n0 : Instruction\n");
        printf("1 : Define A New Matrix\n");
        printf("2 : Edit A Matrix\n");
        printf("3 : Add Two Matrix\n");
        printf("4 : Subtract Two Matrix\n");
        printf("5 : Multiply Two Matrix\n");
        printf("6 : Determinant Two Matrix\n");
        printf("7 : Inverse of A Matrix(Not Available)\n");
        printf("8 : Transpose of A Matrix\n");
        printf("9 : Print A Matrix\n");
        printf("58 : Exit Program\n");
        printf("Enter to Number to perform any task : ");
        scanf("%d", &op);
        switch (op)
        {
        case 0:
            printf("INSTRUCTION : \n");
            break;
        case 1:
            printf("Enter Rows And Column of Matrix : ");
            scanf("%d%d", &p[count], &q[count]);
            MatDec(&M[count], p[count], q[count]);
            printf("Enter The Element of Matrix(M%d) : \n", count);
            MatInp(M[count - 1], p[count - 1], q[count - 1]);
            break;
        case 2:
            printf("Enter Matrix No. To Edit : ");
            scanf("%d", &ind);
            MatInp(M[ind], p[ind], q[ind]);
            break;

        case 3:
            if (count == 0)
            {
                printf("Please, Define Matrix First\n");
                getch();
                break;
            }
            printf("Enter Which Two Matrix is to be added : ");
            scanf("%d%d", &op1, &op2);
            MatAdd(M[op1 - 1], M[op2 - 1], p[op1 - 1], q[op1 - 1], p[op2 - 1], q[op2 - 1]);
            break;

        case 4:
            if (count == 0)
            {
                printf("Please, Define Matrix First\n");
                getch();
                break;
            }
            printf("Enter Which Two Matrix is to be subtract : ");
            scanf("%d%d", &op1, &op2);
            MatSub(M[op1 - 1], M[op2 - 1], p[op1 - 1], q[op1 - 1], p[op2 - 1], q[op2 - 1]);
            break;

        case 5:
            if (count == 0)
            {
                printf("Please, Define Matrix First\n");
                getch();
                break;
            }
            printf("Enter Which Two Matrix is to be multiply : ");
            scanf("%d%d", &op1, &op2);
            MatMul(M[op1 - 1], M[op2 - 1], p[op1 - 1], q[op1 - 1], p[op2 - 1], q[op2 - 1]);
            break;

        case 6:
            if (count == 0)
            {
                printf("Please, Define Matrix First\n");
                getch();
                break;
            }
            printf("Enter Matrix No. To find determinant of it : ");
            scanf("%d", &op1);
            printf("Determinant of M%d(%dx%d) : ", op1, p[op1 - 1], q[op1 - 1]);
            MatDet(M[op1 - 1], p[op1 - 1], q[op1 - 1]);
            break;

        case 7:
            if (count == 0)
            {
                printf("Please, Define Matrix First\n");
                getch();
                break;
            }
            printf("Enter Matrix No. to find Inverse : ");
            scanf("%d", &op1);
            // printf("p[0] : %d,q[0] : %d",p[op1-1],q[op1-1]);
            MatInv(M[op1 - 1], p[op1 - 1], q[op1 - 1]);
            break;

        case 8:
            if (count == 0)
            {
                printf("Please, Define Matrix First\n");
                getch();
                break;
            }
            printf("Enter Matrix No. to find transpose : ");
            scanf("%d", &op1);
            MatTrans(M[op1 - 1], p[op1 - 1], q[op1 - 1]);
            break;

        case 9:
            if (count == 0)
            {
                printf("Please, Define Matrix First\n");
                getch();
                break;
            }
            printf("Enter Which Matrix is to be printed : ");
            scanf("%d", &ind);
            MatPrt(M[ind - 1], p[ind - 1], q[ind - 1], ind);
            break;
        case 58:
            MatClr();
            return 0;

        default:
            printf("Invalid Entry!!!\nTry Again......\n");
            break;
        }
    }
    MatClr();
    return 0;
}