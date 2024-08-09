#include <stdio.h>
#include <stdlib.h>

// Structure to represent a meeting
typedef struct {
    int start;
    int end;
} Meeting;

// Function to compare two meetings based on their end time (for sorting)
int compareMeetings(const void *a, const void *b) {
    Meeting *m1 = (Meeting *)a;
    Meeting *m2 = (Meeting *)b;
    return m1->end - m2->end;
}

// Function to find the maximum number of meetings that can be accommodated
int maxMeetings(Meeting meetings[], int n) {
    qsort(meetings, n, sizeof(Meeting), compareMeetings);
    
    int count = 1; // At least one meeting can be scheduled
    int lastEnd = meetings[0].end;

    for (int i = 1; i < n; i++) {
        if (meetings[i].start >= lastEnd) {
            count++;
            lastEnd = meetings[i].end;
        }
    }
    return count;
}

// Function to find the minimum number of meetings that can be accommodated
int minMeetings() {
    return 1; // The minimum number of meetings that can be accommodated is always 1
}

// Function to validate input
int validateInput(Meeting meetings[], int n) {
    for (int i = 0; i < n; i++) {
        if (meetings[i].start < 0 || meetings[i].end < 0 || meetings[i].start >= meetings[i].end) {
            printf("Invalid input for meeting %d: start time = %d, end time = %d\n", i + 1, meetings[i].start, meetings[i].end);
            return 0;
        }
    }
    return 1;
}

int main() {
    // Example set of meetings (start, end) in minutes from 12am
    Meeting meetings[] = { {3, 29}, {50, 93}, {88, 92}, {54, 67}, {50, 87} };
    int n = sizeof(meetings) / sizeof(meetings[0]);

    // Validate input
    if (!validateInput(meetings, n)) {
        return 1; // Exit if input is invalid
    }

    // Calculate and print the maximum number of meetings
    int max = maxMeetings(meetings, n);
    printf("Maximum number of meetings that can be accommodated: %d\n", max);

    // Calculate and print the minimum number of meetings
    int min = minMeetings();
    printf("Minimum number of meetings that can be accommodated: %d\n", min);

    return 0;
}

