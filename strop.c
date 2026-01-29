#include <stdio.h>
#include <string.h>
void reverse(char str[],int len) 
{
int start=0,end=len-1;
    while(start<=end){
        char temp=str[start];
        str[start++]=str[end];
        str[end--]=temp;
    }
}
void uppercase(char str[],int len) {
    for(int i=0;i<len;i++) {
        str[i]=str[i]-32;
    }
}

int main() 
{

        char str[20];
        printf("Enter name:");

        fgets(str,20,stdin);
        printf("hellow %s",str);
        int len=strlen(str)-1 ,flag=1,ch;
        while(flag) {
            printf("-----------string operation---------\n");
            printf("1.reverse a string\n");
            printf("2.Display\n");
            printf("3.convert to uppercase \n");
            printf("4.covert to lowercase \n");
            printf("5.reserve a words\n");
            printf("6.exit\n");
            printf("enter your choice: ");
            scanf("%d",&ch);
            switch(ch){
                case 1:reverse(str,len);
                case 2:printf("String :%s\n",str);break;
                case 3:uppercase(str,len);break;
                case 4: for(int i=0;i<len;i++) {
                            
            }
        }

}
