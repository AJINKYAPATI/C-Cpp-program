#include<stdio.h>
int main(){
    
    
    int a=2,num,flag=0;
    printf("enter the number");
    scanf("%d",&num);
    while(a<=num/2){
        if(num%a==0){
            flag=1;
            break;
        }
        a++;
    }
    
    
    printf(flag?"not prime number" : "prime number");
    
    return 0;
}
