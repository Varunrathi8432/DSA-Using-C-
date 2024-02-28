#include<iostream>
using namespace std;
int g(int n){
    if(n%2==0){
        return g(g(n-1));
    }
    else{
        return n++;
    }
}
int main(){
    // cout<<g(12);
}