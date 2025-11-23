#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int freq[256] = {0};  // ASCII table size
    int i;

    printf("Enter a string: ");
    gets(str);   // simple for exams

    // Count frequency
    for (i = 0; str[i] != '\0'; i++) {
        freq[(unsigned char)str[i]]++;
    }

    printf("\nCharacter Frequency:\n");

    // Print characters that appear
    for (i = 0; i < 256; i++) {
        if (freq[i] != 0) {
            printf("%c = %d\n", i, freq[i]);
        }
    }

    return 0;
}
