#include <stdio.h>

void table(int n, int i) {
    if (i > 10) {
        return; // stop when i becomes greater than 10
    }
    printf("%d x %d = %d\n", n, i, n * i); // print one line of the table
    table(n, i + 1); // call function again with next number
}
int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    printf("Table of %d:\n", n);
    table(n, 1); // start from 1
    return 0;
}
