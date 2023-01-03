#include<stdio.h>
int fibo(int n)
{
    if(n==1 || n==2)
    return 1;
    else
    {
        return fibo(n-1)+fibo(n-2);
    }
 
}
int main()
{
    int n;
    printf("\nEnter the length of the series:");
    scanf("\n%d",&n);
    // for(int i=0;i<n;i++)
    printf("The number is \n%d",fibo(n));
    return 0;

}