#include <stdio.h>

int n;
void counter(int n)
{
    int countz=0,countf=0;
    while(n>0)
    {
        int r=n%10;
        if(r%2==0)
            countz++;
        else if(r%2!=0)
            countf++;

        n/=10;
    }
    printf("number of even numbers : %d , number of odd numbers: %d",countz,countf);
}
int main()
{
    printf("number: ");
    scanf("%d",&n);
    counter(n);

    return 0;
}