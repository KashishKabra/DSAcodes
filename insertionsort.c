#include<stdio.h>
void insertionsort(int arr[],int n){
    for(int i=1;i<n;i++){
        int temp=arr[i];
        int j=i-1;
        while (j>=0 && temp<=arr[j]){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=temp;
    }
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
    insertionsort(arr,n );
    printarray(arr,n);
}
