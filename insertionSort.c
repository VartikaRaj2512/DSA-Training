// #include<stdio.h>
// int main(){
//     int i,n=6;
//     int arr[]={59,34,12,65,21,45};
//     for(i=0;i<n;i++){
//         int key=arr[i];
//         int j=i-1;
//         while(j>=0 && arr[j]>key){
//             arr[j+1]=arr[j];
//             j=j-1;
//         }
//         arr[j+1]=key;
//     }
//     for(i=0;i<n;i++){
//         printf("%d \n",arr[i]);
//     }
//     return 0;
// }
#include <stdio.h>

// Function to perform insertion sort
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 0; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
void bubbleSort(int arr[],int n){
    int i,j,temp;
    for (i=0;i<n;i++){
        for (j=i+1;j<n;j++){
            if(arr[j]<arr[i]){
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}

int main() {
    int i, n;

    // Take input for the size of the array
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Take input for the elements of the array
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}