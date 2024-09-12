
#include <stdio.h>

int main() {
    int i, j;
    for(i = 1; i <= 7; i++) {
        for(j = 1; j <= 7; j++) {
            if ((i == 1 || i == 4 || i == 7) || (j == 2 && i == 5) || (j == 6 && i == 2) || (j == 6 && i == 3) || (j == 2 && i == 6)) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
