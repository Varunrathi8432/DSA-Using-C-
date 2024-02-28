#include<iostream>
using namespace std;
int inversionCount(int a[], int n)
    {
        // Your Code Here
    
        int count=0;
        int i=0;
        int j=n-1;
        while(i<j){
            if(i==j-1){
                if(a[i]>a[j]){
                    count ++;
                }
                i=0;
                j--;
            }
            else if(a[i]<a[j]){
                i++;
            }
            if(a[i]>a[j]){
                count ++;
            }
            cout<<count;
        }
        return count;
    }
int main(){
    int a[5]={2 ,4 ,1 ,3 ,5};
    int a1=5;
    inversionCount(a,a1);
}