#include <stdio.h>

int main() {
    int i, j;
    for(i = 1; i <= 7; i++) {
        for(j = 1; j <= 7; j++) {
            if (i == 1 || i == 4 || i == 7 || (j == 7 && (i == 2 || i == 3 || i == 5 || i == 6))) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
