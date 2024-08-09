#include <stdio.h>
#include <ctype.h>
#include <string.h> // Include this header for strchr and strlen

#define VOWELS "AEIOUaeiou"

// Function to count vowels and consonants in a string
void countVowelsAndConsonants(const char* str, int* vowelCount, int* consonantCount) {
    *vowelCount = 0;
    *consonantCount = 0;
    
    while (*str) {
        char ch = *str;
        if (isalpha(ch)) { // Check if the character is alphabetic
            if (strchr(VOWELS, ch)) { // Check if the character is a vowel
                (*vowelCount)++;
            } else { // Otherwise, it is a consonant
                (*consonantCount)++;
            }
        }
        str++;
    }
}

int main() {
    char str[100];
    int vowelCount, consonantCount;

    // Input the string
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove newline character if present
    size_t length = strlen(str);
    if (length > 0 && str[length - 1] == '\n') {
        str[length - 1] = '\0';
    }

    // Count vowels and consonants
    countVowelsAndConsonants(str, &vowelCount, &consonantCount);

    // Print the results
    printf("Number of vowels: %d\n", vowelCount);
    printf("Number of consonants: %d\n", consonantCount);

    return 0;
}
