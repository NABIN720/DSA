#include<stdio.h>
int fibo(int n)
{
    int a=1,b=1,c=1,i;
    for(i=3;i<=n;i++)
    {
        c=a+b;
        a=b;
        b=c;
    }
    return c;
}
int main()
{
    int n;
    printf("\nEnter the iteration of the series:");
    scanf("\n%d",&n);
    printf("The number is \n%d",fibo(n));
    return 0;

}