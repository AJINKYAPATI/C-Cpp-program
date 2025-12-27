#include <stdio.h>
// WAP to find length of given string
int main() 
{
    char str[100];
    int i,
    length = 0;

    printf("Enter a string: ");
    gets(str);

    for (i = 0;str[i] !='\0'; i++) {
        length++;
    }
   
    printf("length of the string is: %d\n", length);

    return 0;
}
