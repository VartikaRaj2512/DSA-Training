#include<stdio.h>
// #include<stdlib.h>
int binarySearch(int arr[],int s,int e,int element){
    int mid ;
    mid=(s+e)/2;
    if (arr[mid]== element){
        return mid+1;
    }
    else if(arr[mid]<element){
        s=mid+1;
        return binarySearch(arr,s,e,element);
    }
    else{
        e=mid-1;
        return binarySearch(arr,s,e,element);
    }
    return -1;

}

int main(){
    int arr[5]={10,20,30,40,50};

    int n=40;
    int a=binarySearch(arr,0,4,n);
    printf("%d is present at %dth position \n",n,a);
    
    return 0;
}