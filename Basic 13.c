#include <stdio.h>

int main() 

{
    char str[110];
    int i, vowels = 0, consonants = 0;

    printf("Enter a string: ");
    gets(str);  
    
    // simple for exams

    for(i = 0; str[i] != '\0'; i++) {
        char ch = str[i];

        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
            
            // Check if vowel
            if (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' ||
                ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U') {
                vowels++;
            } 
            
            else {
                consonants++;
            }
        }
    }

    printf("Vowels: %d\n", vowels);
    printf("Consonants: %d\n", consonants);

    return 0;
}
