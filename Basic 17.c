#include <stdio.h>

int main() {
    char str[200];
    int i;

    printf("Enter a sentence: ");
    gets(str);   // fine for simple programs

    // Capitalize first character if it's a letter
    if (str[0] >= 'a' && str[0] <= 'z')
        str[0] = str[0] - 32;

    // Capitalize after spaces
    for (i = 1; str[i] != '\0'; i++) {
        if (str[i - 1] == ' ' && (str[i] >= 'a' && str[i] <= 'z')) {
            str[i] = str[i] - 32;
        }
    }

    printf("Result: %s\n", str);

    return 0;
}
