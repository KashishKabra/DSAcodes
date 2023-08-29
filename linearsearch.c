#include<stdio.h>
int linearsearch(int arr[],int n,int key){
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            return i;
        }
    }
    return -1;
}
int main(){
    int n,i,r,key;
    printf("Enter the number of elements in the array=");
    scanf("%d",&n);
    int arr[n];
    for (i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter element to be searched=");
    scanf("%d",&key);
    r=linearsearch(arr,n,key);
    if (r==-1){
        printf("Element not present in the array");
    }else{
        printf("Element %d is at position %d in array",key,r+1);
    }
}