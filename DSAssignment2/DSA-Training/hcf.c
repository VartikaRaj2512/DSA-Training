#include <stdio.h>

// Function to find HCF using recursion
int findHCF(int a, int b) {
    // Base case: if b becomes 0, the HCF is a
    if (b == 0) {
        return a;
    }
    // Recursive case: call the function with b and the remainder of a divided by b
    return findHCF(b, a % b);
}

int main() {
    int num1, num2;

    // Input two numbers
    printf("Enter two integers: ");
    if (scanf("%d %d", &num1, &num2) != 2) {
        fprintf(stderr, "Invalid input. Please enter integers only.\n");
        return 1;
    }

    // Handle negative inputs
    if (num1 < 0) num1 = -num1;
    if (num2 < 0) num2 = -num2;

    // Find and print HCF
    int hcf = findHCF(num1, num2);
    printf("The HCF of %d and %d is %d.\n", num1, num2, hcf);

    return 0;
}
