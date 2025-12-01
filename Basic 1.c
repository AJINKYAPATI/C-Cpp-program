#include <stdio.h>

int main() {
    int n, i;
    long long fact = 1;

    
    printf("Enter a number: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Factorial of a negative number is not possible.");
    } 
    else {
        for (i = 1; i <= n; i++) {
            fact *= i;
        }
        printf("Factorial of %d = %lld", n, fact);
    }

    return 0;
}
