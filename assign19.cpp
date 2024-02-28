#include<iostream>
using namespace std;
void Swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}
void bubblesort(int arr[],int n){
    for(int i=0;i<n;i++){
        for(int j=1;j<n-i;j++){
            if(arr[j-1]>arr[j]){
                Swap(arr[j-1],arr[j]);
            }
        }
    }
}
void modified_bubblesort(int arr[],int n){
    bool Flag;
    for(int i=0;i<n;i++){
        Flag=true;
        for(int j=1;j<n-i;j++){
            if(arr[j-1]>arr[j]){
                Swap(arr[j-1],arr[j]);
                Flag=false;
            }
        }
        if(Flag)
            break;
    }
}
void insertionsort(int arr[],int n){
    for(int i=1;i<n;i++){
        int temp=arr[i];
        int j=i-1;
        while(j>=0){
            if(temp<arr[j]){
                arr[j+1]=arr[j];
                j--;
            }
            else{
                break;
            }
        }
        arr[j+1]=temp;
    }   
}
void selectionsort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int k=i;
        for(int j=i+1;j<n;j++){
            if(arr[k]>arr[j])
                k=j;
        }
        Swap(arr[i],arr[k]);
    }
}

int quick(int arr[],int l,int r){
    int loc=l;
    while(l<r){
        if(loc==l){
            if(arr[loc]>arr[r]){
                Swap(arr[loc],arr[r]);
                loc=r;
            }
            else{
                r--;   
            }
        }
        else{
            if(arr[l]>arr[loc]){
                Swap(arr[loc],arr[l]);
                loc=l;
            }
            else{
                l++;
            }
        }
    }
    return loc;
}
void quicksort(int arr[],int l,int r){
    if(l<r){
        int loc;
        loc=quick(arr,l,r);
        quicksort(arr,l,loc-1);
        quicksort(arr,loc+1,r);
    }
}
void quicksort(int arr[],int n){
    quicksort(arr,0,n-1);
}
void merge(int arr[],int l,int mid,int r){
    int i=l;
    int j=mid+1;
    int k=0;
    int *ptr=new int[r-l+1];
    while(i<=mid && j<=r){
        if(arr[i]<arr[j]){
            ptr[k]=arr[i];
            i++;
        }
        else{
            ptr[k]=arr[j];
            j++;
        }
        k++;
    }
    while(i<=mid){
        ptr[k]=arr[i];
        k++;
        i++;
    }
    while(j<=r){
        ptr[k]=arr[j];
        k++;
        j++;
    }
    for(int z=l;z<=r;z++){
        arr[z]=ptr[z-l];
    }
    delete []ptr;
}
void mergesort(int arr[],int l,int r){
    if(l<r){
        int mid=l+(r-l)/2;
        mergesort(arr,l,mid);
        mergesort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
}
void mergesort(int arr[],int n){
    mergesort(arr,0,n-1);
}
int main(){
    int a[]={58,62,91,43,29,37,88,72,16};
    int n=9;
    mergesort(a,n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}