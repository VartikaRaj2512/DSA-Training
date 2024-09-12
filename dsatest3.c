// #include <stdio.h>

// void searchAndReplace(int arr[], int size, int searchElement, int replaceElement) {
//     for (int i = 0; i < size; i++) {
//         if (arr[i] == searchElement) {
//             arr[i] = replaceElement;
//         }
//     }
// }

// void printArray(int arr[], int size) {
//     for (int i = 0; i < size; i++) {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");
// }

// int main() {
//     int size;
    
//     // Input the size of the array
//     printf("Enter the number of elements: ");
//     scanf("%d", &size);
    
//     int arr[size];
    
//     // Input the array elements
//     printf("Enter the elements of the array:\n");
//     for (int i = 0; i < size; i++) {
//         scanf("%d", &arr[i]);
//     }
    
//     int searchElement, replaceElement;
    
//     // Input the element to search and the element to replace it with
//     printf("Enter the element to search: ");
//     scanf("%d", &searchElement);
//     printf("Enter the element to replace it with: ");
//     scanf("%d", &replaceElement);
    
//     // Perform search and replace
//     searchAndReplace(arr, size, searchElement, replaceElement);
    
//     // Print the modified array
//     printf("Modified array:\n");
//     printArray(arr, size);
    
//     return 0;
// }
#include<stdio.h>
int main(){
    int i=10,j=20,m,n;
    m=i--;
    n=--i + m++ ;
    printf("%d\n",i);
    printf("%d\n",j);
    printf("%d\n",m);
    printf("%d\n",n);
    return 0;

}