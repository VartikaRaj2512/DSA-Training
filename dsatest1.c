#include <stdio.h>

// Function to reverse the number
int reverseNumber(int num) {
    // Base case: if the number is 0, return 0
    if (num == 0) {
        return 0;
    }
    // Recursive case
    // Reverse the rest of the number and append the last digit
    int reversed = reverseNumber(num / 10);
    int digits = 1;
    while (digits <= num / 10) {
        digits *= 10;
    }
    return (num % 10) * digits + reversed;
}

int main() {
    int num;
    
    // Input the number
    printf("Enter a number: ");
    scanf("%d", &num);
    
    // Handle negative numbers
    int sign = 1;
    if (num < 0) {
        sign = -1;
        num = -num;
    }
    
    // Find and print the reversed number
    int reversed = reverseNumber(num) * sign;
    printf("The reversed number is: %d\n", reversed);
    
    return 0;
}
