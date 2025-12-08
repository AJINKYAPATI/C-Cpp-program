



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
