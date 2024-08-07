/* program to print:
    1
   222
  33333
 4444444
555555555

*/
#include <stdio.h>

int main() {
    int n, z = 1;
    
    // Prompt the user to enter the size of the pattern
    printf("Enter the size: ");
    
    // Read the input for the size
    if (scanf("%d", &n) != 1 || n <= 0) {
        // Input validation: Check if the input is a valid positive integer
        printf("Invalid input. Please enter a positive integer.\n");
        return 1; // Exit the program with an error code
    }

    // Loop through each row
    for (int i = 0; i < n; i++) {
        // Print leading spaces for the current row
        for (int j = n - 1; j > i; j--) {
            printf(" ");
        }
        // Print the required numbers for the current row
        for (int k = 0; k < z; k++) {
            printf("%d", z - i);
        }
        // Increment z by 2 for the next row
        z += 2;
        // Move to the next line
        printf("\n");
    }

    return 0; // Indicate that the program ended successfully
}
