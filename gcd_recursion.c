#include<stdio.h>
int gcd(int a, int b)
{
    if(b==0)
    {
        return a;
    }
    else{
        return gcd(b,a%b);
    }
}
int main()
{
    int a,b;
    printf("Enter two numbers:");
    scanf("\n%d\n%d",&a,&b);
    printf("The gcd is : %d",gcd(a,b));
    return 0;
}