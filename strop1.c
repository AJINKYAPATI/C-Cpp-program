#include <stdio.h>
#include <string.h>
#include <ctype.h>
// Function to reverse a string
void reverse(char str[], int len) {
    int start = 0, end = len - 1;
    while (start < end) {
        char temp = str[start];
        str[start++] = str[end];
        str[end--] = temp;
    }
}
// Function to convert string to uppercase
void uppercase(char str[], int len) {
    for (int i = 0; i < len; i++) {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = str[i] - 32;
    }
}
// Function to convert string to lowercase
void lowercase(char str[], int len) {
    for (int i = 0; i < len; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] + 32;
    }
}
int main() {
    char str[100];
    int flag = 1, ch;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0'; // Remove newline if present

    int len = strlen(str);

    while (flag) {
        printf("\n-------- String Operations --------\n");
        printf("1. Reverse the string\n");
        printf("2. Display the string\n");
        printf("3. Convert to uppercase\n");
        printf("4. Convert to lowercase\n");
        printf("5. Reserve (reverse) the words\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        getchar(); // To consume the newline left by scanf

        switch (ch) {
            case 1:
                reverse(str, len);
                printf("Reversed string: %s\n", str);
                break;

            case 2:
                printf("String is: %s\n", str);
                break;

            case 3:
                uppercase(str, len);
                printf("Uppercase string: %s\n", str);
                break;

            case 4:
                lowercase(str, len);
                printf("Lowercase string: %s\n", str);
                break;

            case 5: {
                char temp[100], word[20];
                int i = 0, j = 0, k = 0;
                for (i = strlen(str) - 1; i >= 0; i--) {
                    if (str[i] == ' ' || i == 0) {
                        if (i == 0)
                            word[j++] = str[i];
                        word[j] = '\0';
                        strrev(word); // Using built-in reverse for a word
                        strcat(temp, word);
                        strcat(temp, " ");
                        j = 0;
                    } else {
                        word[j++] = str[i];
                    }
                }
                strcpy(str, temp);
                printf("Words reversed: %s\n", str);
                break;
            }

            case 6:
                flag = 0;
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
