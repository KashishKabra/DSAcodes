#include<stdio.h>
void merge(int a[],int low ,int mid,int high){
    int i,j,k;
    int b[100];
    i=low;
    j=mid+1; 
    k=low;
    while (i<=mid && j<=high){
        if (a[i]<a[j]){
            b[k]=a[i];
            i++;
        }else{
            b[k]=a[j];
            j++;
        }
        k++;
    }
    while (i<=mid){
        b[k]=a[i];
        k++;
        i++;
    }
    while(j<=high){
        b[k]=a[j];
        k++;
        j++;
    }
    for (i=low;i<=high ;i++){
        a[i]=b[i];
    }
}
void mergesort(int a[],int low,int high){
    int mid;
    if (low<high){
        mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}
void printarray(int a[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}
int main(){
    int n;
    printf("enter the number of elements=");
    scanf("%d",&n);
    int a[n];
    printf("enter\n");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    mergesort(a,0,n-1);
    printarray(a,n); 
}