#include <stdio.h>
#define max_value 100
int main(){
    int arr[max_value];
    int flag=1,choice,n;
    printf("enter size of array:");
    scanf("%d",&n);
    printf("enter value of array:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    while(flag){
        printf("\narray aperation\n");
        printf("1.display\n");
        printf("2.insertion\n");
        printf("3.deletion\n");
        printf("4.update array\n");
        printf("5.Exit\n");
        printf("enter your choice:");
        scanf("%d",&choice);
        
        switch(choice){
            
            case 1:{
                printf("Array elements:\n");
                for(int i=0;i<n;i++){
                    printf("%d",arr[i]);
                }
                printf("\n");
                break;
            }
            
            case 2:{
                int pos,element;
                printf("enter a position:");
                scanf("%d",&pos);
                printf("enter a new element:");
                scanf("%d",&element);
                for(int i=n;i>=pos;i--){
                    arr[i]=arr[i-1];
                }
                arr[pos-1]=element;
                n++;
                printf("element inserted succesfully.\n");
                break;
            }
            
            case 3:{
                int pos;
                printf("enter a position:");
                scanf("%d",&pos);

                for(int i=pos-1;i<=n;i++){
                arr[i]=arr[i+1];
            }
                n--;
                printf("element deleted succesfully\n");
                break;
            }
            
            case 4:{
                int existing,element;
                printf("enter existing element:");
                scanf("%d",&existing);
                printf("enter new elements");
                scanf("%d",&element);
            
                arr[existing-1]=element;
                printf("elemeents updates succesfully!");
                break;
            }
            
            case 5:
                flag=0;
                printf("Exiting program.\n");
                break;
            
            default:
                 printf("invalide choice....please re-enter choice...");
        }
    }

    return 0;
}
