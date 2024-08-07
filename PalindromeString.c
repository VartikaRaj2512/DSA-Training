#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LENGTH 100 // Define the maximum length for the input string

bool isPalindrome(const char *str) {
    int l = strlen(str);
    char rev[l + 1];
    int i;

    // Reverse the string
    for (i = 0; i < l; i++) {
        rev[i] = str[l - 1 - i];
    }
    rev[l] = '\0'; // Null-terminate the reversed string

    // Check if the original string is equal to the reversed string
    return strcmp(str, rev) == 0;
}

int main() {
    char s[MAX_LENGTH];
    
    printf("Enter a string: ");
    fgets(s, sizeof(s), stdin);

    // Remove the newline character if it is present
    size_t len = strlen(s);
    if (len > 0 && s[len - 1] == '\n') {
        s[len - 1] = '\0';
    }

    if (isPalindrome(s)) {
        printf("Palindrome\n");
    } else {
        printf("Not Palindrome\n");
    }

    return 0;
}
