#include<stdio.h>
void move(int n,char source,char destination,char temporary)
{
    if(n==1)
    {
        printf("\nMove disc %d from %c to %c",n,source,destination);
    }
    else
    {
        move(n-1,source,temporary,destination);
        printf("\nMove disc %d from %c to %c",n,source,destination);
        move(n-1,temporary,destination,source);
    }
}
int main()
{
    int n;
    printf("\nn=?");
    scanf("%d",&n);
    move(n,'A','C','B');

    return 0;
}