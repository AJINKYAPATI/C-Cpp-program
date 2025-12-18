#include <stdio.h>
#include <string.h>

int main() 

{
    char str[110];
    int i, len, flag = 0;

    printf("Enter a string: ");
    gets(str);   
    
    // easy for exams, unsafe in real use

    len = strlen(str);

    for (i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            flag = 1;
            break;
        }
    }

    if (flag == 0)
        printf("%s is a palindrome.\n", str);
    else
        printf("%s is not a palindrome.\n", str);

    return 0;
}
