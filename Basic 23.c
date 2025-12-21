#include <stdio.h>

int main() 
{
    int n, 
    i, 
    flag = 1;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Check sorted
    for (i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            flag = 0;   // Not sorted
            break;
        }
    }

    if (flag == 1)
        printf("Array is sorted in ascending order.\n");
    else
        printf("Array is NOT sorted in ascending order.\n");

    return 0;
}
