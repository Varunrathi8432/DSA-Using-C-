#include<iostream>
using namespace std;
int SUM(int n){
    if(n>0){
        return n+SUM(n-1);
    }
    return n;
}
int SUMODD(int n){
    static int sum=0;
    if(n>0){
        sum=sum+(2*n-1);
        n=SUMODD(n-1);
    }
    return sum;
}
int SUMEVEN(int n){
    static int sum=0;
    if(n>0){
        sum=sum+(2*n);
        n=SUMEVEN(n-1);
    }
    return sum;
}
int SUMSQR(int n){
    // static int sum=0;
    if(n>0){
        // sum=sum+(n*n);
        n=n*n+SUMSQR(n-1);
    }
    // return sum;
    return n;
}
int Fact(int n){
    if(n>1){
        return n*Fact(n-1);
    }
    return n;
}
int sumdigit(int n){
    if(n>0){
        return (n%10)+sumdigit(n/10);
    }
    return n;
}
void binary(int n){
    if(n>0){
        binary(n/2);
        cout<<n%2;
    }    
}
int Fab(int n){
    if(n==0||n==1)
        return n;
    if(n>1){
        return Fab(n-1)+Fab(n-2);
    }
    return n;
}
int hcF(int n1,int n2){
    
}
int power(int x,int y){
    if(y>1){
        return x*power(x,y-1);
    }
    return x;
}
int main(){
    binary(8);
    return 0;
}