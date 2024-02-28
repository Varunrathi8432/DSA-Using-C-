#include<iostream>
using namespace std;
struct node{
    int vertex;
    node* next;
};
class adjlist{
    node* start;
    public:
    adjlist();
};
adjlist::adjlist(){
    start=NULL;
}
class Graph{
    int v;
    adjlist *arr;
    public:
    Graph(int);
};
Graph::Graph(int a){
    v=a;
    arr=new adjlist[v];
}
int main(){
    return 0;
}