#include <stdio.h>
#include <math.h>

int main() {
    int choice;
    float a, b, result;

    do {
        printf("\n===== Advanced Calculator =====\n");
        printf("1. Addition (+)\n");
        printf("2. Subtraction (-)\n");
        printf("3. Multiplication (*)\n");
        printf("4. Division (/)\n");
        printf("5. Modulus (%%)\n");
        printf("6. Power (a^b)\n");
        printf("7. Square Root (√a)\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter two numbers: ");
                scanf("%f %f", &a, &b);
                result = a + b;
                printf("Result = %.2f\n", result);
                break;

            case 2:
                printf("Enter two numbers: ");
                scanf("%f %f", &a, &b);
                result = a - b;
                printf("Result = %.2f\n", result);
                break;

            case 3:
                printf("Enter two numbers: ");
                scanf("%f %f", &a, &b);
                result = a * b;
                printf("Result = %.2f\n", result);
                break;

            case 4:
                printf("Enter two numbers: ");
                scanf("%f %f", &a, &b);
                if (b == 0)
                    printf("Error! Cannot divide by zero.\n");
                else {
                    result = a / b;
                    printf("Result = %.2f\n", result);
                }
                break;

            case 5:
                printf("Enter two integers: ");
                scanf("%f %f", &a, &b);
                if ((int)b == 0)
                    printf("Error! Modulus by zero.\n");
                else
                    printf("Result = %d\n", (int)a % (int)b);
                break;

            case 6:
                printf("Enter base and exponent: ");
                scanf("%f %f", &a, &b);
                result = pow(a, b);
                printf("Result = %.2f\n", result);
                break;

            case 7:
                printf("Enter a number: ");
                scanf("%f", &a);
                if (a < 0)
                    printf("Error! Square root of negative number.\n");
                else {
                    result = sqrt(a);
                    printf("Result = %.2f\n", result);
                }
                break;

            case 8:
                printf("Exiting calculator...\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }

    } while (choice != 8);

    return 0;
}
