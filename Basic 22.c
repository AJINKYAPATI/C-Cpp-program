#include <stdio.h>

int main() {
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n < 2) {
        printf("Array must have at least two elements.\n");
        return 0;
    }

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int largest = arr[0];
    int second = -999999; // or use a very small value

    // Find largest and second largest
    for (i = 1; i < n; i+
      
