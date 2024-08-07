/*program to print  
     *
    * *
   * * *
  * * * *
 * * * * *
* * * * * *
 * * * * *
  * * * *
   * * *
    * *
     *
     * */
    
#include <stdio.h>
#include <stdlib.h>

int main() {
    int size;

    // Prompt the user for the size of the diamond
    printf("Enter the size of the diamond: ");
    scanf("%d", &size);

    // Loop to handle the rows
    for (int i = size; i >= -size; i--) {
        // Print leading spaces
        for (int j = 1; j <= abs(i); j++) {
            printf(" ");
        }

        // Print asterisks
        for (int k = size; k >= abs(i); k--) {
            printf("* ");
        }

        // Move to the next line after printing each row
        printf("\n");
    }

    return 0;
}
