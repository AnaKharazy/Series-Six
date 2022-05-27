
#include <stdio.h>

void add(int n,int m)
{
    printf("%d",n+m);
}
void sub(int n,int m)
{
    printf("%d",n-m);
}
void mult(int n,int m)
{
    printf("%d",n*m);
}
void div(int n,int m)
{
    printf("%d",n/m);
}
void fact(int n)
{
    int f=1;
    for(int i=1;i<=n;i++)
        f*=i;
    printf("%d",f);
}
int main()
{
    int n,m;
    printf("which one?\n1:Addition \n2:Subtraction\n3:Multiplication\n4:Division\n5:Factorial\n6:QUIT\n");
    scanf("%d",&n);
    switch(n) {
        case 1:
            printf("enter two numbers:");
            scanf("%d", &n);
            scanf("%d", &m);
            add(n, m);
            break;
        case 2:
            printf("enter two numbers:");
            scanf("%d", &n);
            scanf("%d", &m);
            sub(n, m);
            break;
        case 3:
            printf("enter two numbers:");
            scanf("%d", &n);
            scanf("%d", &m);
            mult(n, m);
            break;
        case 4:
            printf("enter two numbers:");
            scanf("%d", &n);
            scanf("%d", &m);
            div(n, m);
            break;
        case 5:
            printf("enter a number:");
            scanf("%d", &n);
            fact(n);
            break;
    }
    }
