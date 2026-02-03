#include<stdio.h>
#include<ctype.h>
int main(){

    char ch;
    printf("enter the character: ");
    scanf("%c",&ch);

    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || 
          ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
            printf("character is vowel, %c", ch);
          } else if (isalpha(ch)) {
            printf("character is cnsonant, %c", ch);
          } else if (isdigit(ch)) {
            printf("character is digit, %c", ch);
          } else {
            printf("character is special symbol, %c", ch);
          }
     b return 0;
}
