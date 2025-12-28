#include<stdio.h>
int main()
{
    int num1,
    num2,
    num3,
    num4,
    num5;
    printf("enter the first number :");
    scanf("%d",&num1);

    printf("enter the second number :");
    scanf( "%d", &num2);

    
    printf("enter the third number :");
    scanf("%d",&num3);

    printf("enter the fourth number :");
    scanf( "%d", &num4);

    
    printf("enter the fifth number :");
    scanf("%d",&num5);

    int max;
    max = num1>num2?num1:num2;
    max = max>num3?max:num3;
    max = max>num4?max:num5;

    printf("maximum number is : %d",max);
}
