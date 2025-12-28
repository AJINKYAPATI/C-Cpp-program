  #include<stdio.h>
int main()
{
    int num1,
  num2,
  num3;
    printf("enter the first number :");
    scanf("%d",&num1);

    printf("enter the second number :");
    scanf( "%d", &num2);

    
    printf("enter the third number :");
    scanf("%d",&num3);

    int max=num1>num2?num1:num2;
        max=max>num3?max:num3;

    printf("max num is %d",max);

}


