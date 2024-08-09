#include <stdio.h>

// Function to calculate the nth Fibonacci number
int fib(int n)
{
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}

// Function to calculate the number of ways to reach the 'destination' stair
int countWays(int destination) 
{ 
    return fib(destination + 1); 
}

int main()
{
    int destination;

    // Asking the user to input the stair number
    printf("Enter the number of the stair you want to reach: ");
    scanf("%d", &destination);

    // Displaying the number of ways to reach the entered stair
    printf("Number of ways to reach stair %d = %d\n", destination, countWays(destination));

    return 0;
}