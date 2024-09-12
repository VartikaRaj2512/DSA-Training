#include<stdio.h>
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
void displayascending(int arr[],int n){
    int i;
    for (i=0;i<n;i++){
        printf(" %d ",arr[i]);
    }

}
void displaydescending(int arr[],int n){
    int i;
    for (i=n-1;i>=0;i--){
        printf(" %d ",arr[i]);
    }

}
void bubbleSortdec(int arr[],int n){  //for descending  
 int i,j,temp;
for (i=0;i<n;i++){
    for (j=i+1;j<n;j++){
                 if(arr[j]>arr[i]){
             temp=arr[i];
             arr[i]=arr[j];
             arr[j]=temp;
            }       }
    }
}

int main(){
    int a[5]={21,10,50,40,30};

    printf("ascending order: ");
    bubbleSort(a,5);
    displayascending(a,5);
    printf("\ndescending order: ");
    displaydescending(a,5);

}