#include <stdio.h>

int main() {
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int smallest = arr[0];
    int largest = arr[0];

    // Loop to find smallest and largest
    for (i = 1; i < n; i++) {
        if (arr[i] < smallest)
            smallest = arr[i];

        if (arr[i] > largest)
            largest = arr[i];
    }

    printf("Smallest element is: %d\n", smallest);
    printf("Largest element is: %d\n", largest);

    return 0;
}
