/*program to print  
1  2  3  4 
12        5 
11        6 
10  9  8  7 
*/
#include <stdio.h>

int main() {
    int rows = 4, cols = 4;

    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= cols; j++) {
            if (i == 1) {
                // First row: print 1 2 3 4
                printf("%2d ", j);
            } else if (i == rows) {
                // Last row: print 10 9 8 7
                printf("%2d ", 10 - j + 1);
            } else if (j == 1) {
                // First column of 2nd and 3rd row
                printf("%2d ", 12 - i + 1);
            } else if (j == cols) {
                // Last column of 2nd and 3rd row
                printf("%2d ", i + 3);
            } else {
                // Spaces in between
                printf("   ");
            }
        }
        printf("\n");
    }

    return 0;
}
