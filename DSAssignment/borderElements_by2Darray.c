#include <stdio.h>

int main() {
    int matrix[4][4] = {
        {1, 2, 3, 4},
        {12, 2, 4, 5},
        {11, 7, 8, 6},
        {10, 9, 8, 7}
    };

    int rows = 4;
    int cols = 4;

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            // Print border elements only
            if (r == 0 || r == rows - 1 || c == 0 || c == cols - 1) {
                printf("%2d ", matrix[r][c]);
            } else {
                printf("   "); // Print spaces for non-border elements
            }
        }
        printf("\n");
    }

    return 0;
}
