// #include <stdio.h>

// Function to perform selection sort
void selectionSort(int arr[], int n) {
    int temp, i, j, minimum;
    for (i = 0; i < n - 1; i++) {
        minimum = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minimum]) {
                minimum = j;
            }
        }
        // Swap the found minimum element with the first element
        temp = arr[i];
        arr[i] = arr[minimum];
        arr[minimum] = temp;
    }
}

int main() {
    int arr[] = {59, 34, 21, 25, 12};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Call the selection sort function
    selectionSort(arr, n);

    // Print the sorted array
    for (int i = 0; i < n; i++) {
        printf("%d \n", arr[i]);
    }

    return 0;
}
