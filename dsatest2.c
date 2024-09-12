#include <stdio.h>

// Function to find the nth Fibonacci number
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    int a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    int n;
    
    // Input the value of n
    printf("Enter the position (n) in the Fibonacci sequence: ");
    scanf("%d", &n);
    
    // Find and print the nth Fibonacci number
    printf("The %dth Fibonacci number is: %d\n", n, fibonacci(n));
    
    return 0;
}
