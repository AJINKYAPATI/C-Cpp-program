#include <stdio.h>
int main(){
    int arr[]={3,5,4,2,1};
    int len=sizeof(arr)/sizeof(arr[0]);

    for(int i=0;i<len-1;i++){
        for(int j=0;j<len;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j=1]=temp;
            }
        }
    }

    for(int i=0;i<len;i+=2){
        int temp1=arr[i];
        arr[i]=arr[i+1];
        arr[i+1]=temp1;
    }
    printf("sorting: ");
    for(int i=0;i<len;i++){
        printf("%d",arr[i]);
    }

    return 0;
}
