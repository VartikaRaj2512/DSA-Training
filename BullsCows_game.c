#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to check if a number has all unique digits
int hasUniqueDigits(int num) {
    int digits[10] = {0}; // Array to track the occurrence of each digit
    while (num > 0) {
        int digit = num % 10;
        if (digits[digit] != 0) {
            return 0; // Not unique
        }
        digits[digit] = 1;
        num /= 10;
    }
    return 1; // All digits are unique
}

// Function to generate a 4-digit number with unique digits
int generateUniqueNumber() {
    int num;
    do {
        num = rand() % 9000 + 1000; // Generate a number between 1000 and 9999
    } while (!hasUniqueDigits(num));
    return num;
}

// Function to count bulls and cows
void getBullsAndCows(int secret, int guess, int *bulls, int *cows) {
    int secretDigits[4], guessDigits[4];
    *bulls = 0;
    *cows = 0;

    // Extract digits from secret and guess
    for (int i = 0; i < 4; i++) {
        secretDigits[i] = secret % 10;
        guessDigits[i] = guess % 10;
        secret /= 10;
        guess /= 10;
    }

    // Count bulls
    for (int i = 0; i < 4; i++) {
        if (secretDigits[i] == guessDigits[i]) {
            (*bulls)++;
            secretDigits[i] = -1; // Mark digit as used
            guessDigits[i] = -2; // Mark digit as used
        }
    }

    // Count cows
    for (int i = 0; i < 4; i++) {
        if (guessDigits[i] >= 0) {
            for (int j = 0; j < 4; j++) {
                if (guessDigits[i] == secretDigits[j]) {
                    (*cows)++;
                    secretDigits[j] = -1; // Mark digit as used
                    break;
                }
            }
        }
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    int secret = generateUniqueNumber();
    int guess, bulls, cows;
    int attempts = 7;

    printf("Welcome to Bulls and Cows!\n");
    printf("Guess the 4-digit number with unique digits.\n");

    for (int i = 0; i < attempts; i++) {
        printf("Attempt %d of %d: ", i + 1, attempts);
        scanf("%d", &guess);

        // Check for valid input
        if (guess < 1000 || guess > 9999 || !hasUniqueDigits(guess)) {
            printf("Error: Please enter a 4-digit number with unique digits.\n");
            i--; // Do not count this as an attempt
            continue;
        }

        // Get bulls and cows
        getBullsAndCows(secret, guess, &bulls, &cows);

        // Check if the player has won
        if (bulls == 4) {
            printf("Player wins!\n");
            break;
        } else {
            printf("Bulls = %d, Cows = %d\n", bulls, cows);
        }
    }

    // If the player didn't win within the attempts
    if (bulls != 4) {
        printf("Player lost! The secret number was %d.\n", secret);
    }

    return 0;
}
