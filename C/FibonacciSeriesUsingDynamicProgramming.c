#include<stdio.h>
int count=0,term[20],value[20];
int fib(int n){
    // printf("%d ",n);
    if(n==1 || n==2)
        return (n-1);
    int b1,b2,c1=0,c2=0;
    chk:
    for(int i=0;i<count;i++){
        if(term[i]==(n-1)){
            b1=value[i];
            c1++;
        }
        else if(term[i]==(n-2)){
            b2=value[i];
            c2++;
        }
    }
    if(!c1){
        b1 = fib(n-1);
        term[count] = n-1;
        value[count] = b1;
        count++;
        c1=1;
        goto chk;
    }
    if(!c2){
        b2 = fib(n-2);
        term[count] = n-2;
        value[count] = b2;
    }
    return (b1+b2);
    // return fib(n-1)+fib(n-2);
}
int main(){
    int n;
    printf("Enter Which Term of fibonacci series is to be printed : ");
    scanf("%d",&n);
    printf("\nThe %d Term of the fibonacci series : %d",n,fib(n));
    return 0;
}