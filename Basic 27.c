#include <stdio.h>

int main() 
{
    int n, 
    count = 0;

    printf("Enter a number: ");
    scanf("%d", &n);

    // Handle 0 separately
    if (n == 0) {
        count = 1;
    } else {
        // Convert negative number to positive
        if (n < 0) {
            n = -n;
        }

        // Count digits
        while (n > 0) {
            n = n / 10;
            count++;
        }
    }

    printf("Number of digits = %d\n", count);

    return 0;
}
