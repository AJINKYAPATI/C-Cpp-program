#include<stdio.h>
int main()
{
    int arr[]={10,21,30,40,50,67,89,67};
    int len=sizeof(arr)/sizeof(arr[0]);
    
    for(int i=0;i<len;i++){
        printf("%d\n",arr[i]);
    }

    return 0;
}
