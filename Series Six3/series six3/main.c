
#include <stdio.h>

int main()
{
    int n,heigh,rule,rule2;
    float area;
    printf("which one?\n(1)Area of a parallelogram \n(2)Area of a triangle\n(3)Area of a trapezoid\n(4)Area of a circle\n(5)QUIT\n");
    scanf("%d",&n);
    switch(n)
    {
        case 1:
            printf("heigh: ");
            scanf("%d",&heigh);
            printf("rule: ");
            scanf("%d",&rule);
            printf("area: %d",heigh*rule);
            break;
        case 2:
            printf("heigh: ");
            scanf("%d",&heigh);
            printf("rule: ");
            scanf("%d",&rule);
            printf("area: %d",(heigh*rule)/2);
            break;
        case 3:
            printf("heigh: ");
            scanf("%d",&heigh);
            printf("the big rule: ");
            scanf("%d",&rule);
            printf("small rule: ");
            scanf("%d",&rule2);
            area=((rule2+rule)*heigh)/2;
            printf("area: %f",area);
            break;
        case 4:
            printf("radius: ");
            scanf("%d",&heigh);
            area=(heigh*heigh)*3.14;
            printf("area: %f",area);
            break;
        case 5:
            break;
    }
}