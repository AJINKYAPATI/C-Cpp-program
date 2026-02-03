#include<stdio.h>
int main()
{
    int num;
    printf("enter one num");
    scanf("%d",&num);

    if(num>=0)
    {
        if(num%2==0){
        printf("num is even");
        }else{
            printf("num is odd");
        }
    }else{
        printf("num is negative");
    }
}
