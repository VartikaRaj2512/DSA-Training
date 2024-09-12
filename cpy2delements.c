#include <stdio.h>

#define ROWS 3
#define COLS 4

void copy2DArray(int source[ROWS][COLS], int destination[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            destination[i][j] = source[i][j];
        }
    }
}

int main() {
    // Initialize a 2D array
    int source[ROWS][COLS] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    
    // Declare an empty 2D array
    int destination[ROWS][COLS];

    // Copy elements from source to destination
    copy2DArray(source, destination);

    // Print the destination array to verify the copy
    printf("Destination Array:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", destination[i][j]);
        }
        printf("\n");
    }

    return 0;
}
