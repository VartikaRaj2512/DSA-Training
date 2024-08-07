#include <stdio.h>
#include <string.h>

// Function to count the frequency of each character in the string
void countFrequency(const char* str, int freq[]) {
    int i;
    int len = strlen(str);

    // Initialize frequency array
    for (i = 0; i < 256; i++) {
        freq[i] = 0;
    }

    // Count frequency of each character
    for (i = 0; i < len; i++) {
        freq[(unsigned char)str[i]]++;
    }
}

int main() {
    char str[100];
    int freq[256];
    int i;
    int maxFreq = 0;
    int minFreq = 100;  // Initialize to a large value
    char maxChar = '\0';
    char minChar = '\0';

    // Input string from user
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';  // Remove newline character from input

    // Count the frequency of each character
    countFrequency(str, freq);

    // Find maximum and minimum frequency characters
    for (i = 0; i < 256; i++) {
        if (freq[i] > maxFreq) {
            maxFreq = freq[i];
            maxChar = (char)i;
        }
        if (freq[i] > 0 && freq[i] < minFreq) {
            minFreq = freq[i];
            minChar = (char)i;
        }
    }

    // Print results
    printf("Character with maximum frequency: %c (Frequency: %d)\n", maxChar, maxFreq);
    printf("Character with minimum frequency: %c (Frequency: %d)\n", minChar, minFreq);

    return 0;
}
