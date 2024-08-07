#include <stdio.h>

// Function to print Pascal's Triangle
void printPascal(int n) {
    // Validate input
    if (n <= 0) {
        printf("Number of rows must be positive.\n");
        return;
    }

    // Iterate through each line
    for (int line = 1; line <= n; line++) {
        // Print leading spaces for pyramid shape
        for (int space = 1; space <= n - line; space++) {
            printf("   ");  // Adjust spacing for alignment
        }
        // Calculate and print each value in the line
        int coef = 1;
        for (int i = 1; i <= line; i++) {
            printf("%4d", coef);
            // Update coef to the next value in the line
            coef = coef * (line - i) / i;
        }
        printf("\n");
    }
}

// Driver code
int main() {
    int n;

    // Input the number of rows for Pascal's Triangle
    printf("Enter the number of rows for Pascal's Triangle: ");
    if (scanf("%d", &n) != 1) {
        printf("Invalid input. Please enter a valid integer.\n");
        return 1;
    }

    // Print Pascal's Triangle
    printPascal(n);

    return 0;
}
