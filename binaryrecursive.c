#include<stdio.h>
int binarysearch_recursive(int arr[],int low,int high,int ele){
    int mid;
    while (low<=high){
        mid=(low+high)/2;
        if (ele==arr[mid]){
            return mid;
        }else if (ele<arr[mid]){
            return binarysearch_recursive(arr,low,mid-1,ele);
        }else{
            return binarysearch_recursive(arr,mid+1,high,ele);
        }
    } 
    return -1;
}
int main(){
    int n,i,r,ele;
    printf("Enter the number of elements in the array=");
    scanf("%d",&n);
    int arr[n];
    for (i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter element to be searched=");
    scanf("%d",&ele);
    int low=0;
    int high=n-1;
    r=binarysearch_recursive(arr,low,high,ele);
    if (r==-1){
        printf("Element not present in the array");
    }else{
        printf("Element %d is at position %d in array",ele,r+1);
    }
}