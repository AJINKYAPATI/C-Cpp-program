#include<stdio.h>

int main()
{
    int num1,
    num2;

    printf("enter the first number :");
    scanf("%d",&num1);

    printf("enter the second number ;");
    scanf( "%d", &num2);

    int max=num1>num2?num1:num2;
    printf("max num is %d", max);

}
