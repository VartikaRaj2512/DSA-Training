#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to input a matrix
void inputMatrix(int rows, int cols, int matrix[rows][cols]) {
    printf("Enter elements of the matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (scanf("%d", &matrix[i][j]) != 1) {
                fprintf(stderr, "Invalid input. Please enter integers only.\n");
                exit(EXIT_FAILURE);
            }
        }
    }
}

// Function to print a matrix
void printMatrix(int rows, int cols, int matrix[rows][cols]) {
    printf("Matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to check if two matrices are equal
bool areMatricesEqual(int rows, int cols, int matrix1[rows][cols], int matrix2[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix1[i][j] != matrix2[i][j]) {
                return false; // Matrices are not equal
            }
        }
    }
    return true; // Matrices are equal
}

int main() {
    int rows, cols;

    // Input matrix dimensions
    printf("Enter the number of rows and columns: ");
    if (scanf("%d %d", &rows, &cols) != 2 || rows <= 0 || cols <= 0) {
        fprintf(stderr, "Invalid dimensions. Please enter positive integers for rows and columns.\n");
        return EXIT_FAILURE;
    }

    // Allocate memory for matrices
    int (*matrix1)[cols] = malloc(rows * sizeof(*matrix1));
    int (*matrix2)[cols] = malloc(rows * sizeof(*matrix2));

    if (!matrix1 || !matrix2) {
        fprintf(stderr, "Memory allocation failed.\n");
        return EXIT_FAILURE;
    }

    // Input matrices
    printf("Input for Matrix 1:\n");
    inputMatrix(rows, cols, matrix1);
    
    printf("Input for Matrix 2:\n");
    inputMatrix(rows, cols, matrix2);

    // Check if matrices are equal
    if (areMatricesEqual(rows, cols, matrix1, matrix2)) {
        printf("Matrix 1 and Matrix 2 are equal.\n");
    } else {
        printf("Matrix 1 and Matrix 2 are not equal.\n");
    }

    // Print matrices
    printf("Matrix 1:\n");
    printMatrix(rows, cols, matrix1);

    printf("Matrix 2:\n");
    printMatrix(rows, cols, matrix2);

    // Free allocated memory
    free(matrix1);
    free(matrix2);

    return EXIT_SUCCESS;
}
