#include <stdio.h>
#include <string.h>

int main() 
{
    char str[100], rev[100];
    int i, len;

    printf("Enter a string: ");
    gets(str);  
    
    // For simple programs; avoid in real projects

    len = strlen(str);

    for(i = 0; i < len; i++) {
        rev[i] = str[len - i - 1];
    }
    rev[i] = '\0'; 
    
    // Null terminate the reversed string

    printf("Reversed string: %s\n", rev);

    return 0;
}
