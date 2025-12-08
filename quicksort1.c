include <stdio.h>
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int pivot(int arr[],int start,int end){

    int pivot=arr[end];
    int i=start-1;
    for(int j=start;j<end;j++){
        if(arr[j]<pivot){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
}



int main (){
    int arr[]={2,1,5,4,3};
    int len=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<len;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");

    partition(arr,0,len-1);

    for(int i=0;i<len;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
