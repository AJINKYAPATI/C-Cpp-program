#include<stdio.h>
int main()
{

    int a=1,n,b=1;
    printf("enter a number:");
    scanf("%d",&n);

    while(a<=10)
    {
        b=1;
        while(b<=n){
            printf("%d\t",a*b);
            b++;
        }
        printf("\n");
        a++;
    }

    return 0;
}
