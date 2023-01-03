#include<stdio.h>
int gcd(int a, int b)
{
    int rem;
    if(b==0)
    return a;
    else{
        while (b!=0)
        {
            rem = a%b;
            a=b;
            b=rem;
        }
        return a;
    }
}
int main()
{
    int a,b;
    printf("<-------------------------GCD CALCULATION DSA---------------->");
    printf("\nEnter two numbers:");
    scanf("%d\n%d",&a,&b);
    printf("\nThe GCD is:%d",gcd(a,b));
   
    return 0;
}

