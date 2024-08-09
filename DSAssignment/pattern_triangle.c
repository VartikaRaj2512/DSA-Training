#include <stdio.h>

int main() {
    int rows = 5;

    for (int i = 1; i <= rows; ++i) {
        // Print leading spaces
        for (int space = 1; space <= rows - i; ++space) {
            printf(" ");
        }
        // Print the pyramid
        for (int j = 1; j <= 2 * i - 1; ++j) {
            if (j == 1 || j == 2 * i - 1 ||i==rows)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }

    return 0;
}
