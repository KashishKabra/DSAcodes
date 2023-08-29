#include<stdio.h>
void selectionsort_iterative(int arr[],int n){
    int temp;
    for (int i=0;i<n-1;i++){
        int imin=i;
        for (int j=i+1;j<n;j++){
            if (arr[imin]>arr[j]){
                imin=j;
            }
        }//first element swapped with imin
        if (imin != i){
            temp=arr[imin];
            arr[imin]=arr[i];
            arr[i]=temp;
        }}
}
void printarray(int arr[],int n){
    for (int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }   
}
int main(){
    int n,ch;
    printf("Enter the number of elements in the array=");
    scanf("%d",&n);
    int arr[n];
    for (int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }    
    selectionsort_iterative(arr,n );
    printarray(arr,n);
}
