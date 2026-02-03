#include<stdio.h>
int main()
{
    char ch;
    printf("enter the alphabet: ");
    scanf("%c",&ch);

    if(ch >= 'A' && ch <= 'z'){
        if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'U'){
            printf("uppercase vowel: %c",ch);
        }
        else {
        printf("uppercase consonant: %c",ch);
        }
     } 
    else {
        printf("the entered character is not an uppercase");
    }
}
