#include <stdio.h>

int main(){

    int row,col;
    printf("enter no of row and cols: ");
    scanf("%d",&row,&col);

    int arr2[row][col];

    printf("enter value for 2d array: ");
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            scanf("%d",&arr2[i][j]);
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%d ",arr2[i][j]);
        }
        
        printf("\n");
    }
}
