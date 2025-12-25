#include<stdio.h>
int main()

{
    
    int n;
    printf("enter a size for array:");
    scanf("%d",&n);
    int arr[n];

    printf("enter value for array:");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    
    int min=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]<min){
            min=arr[i];
        }
    }
    printf("min :%d",min);

    return 0;
}
