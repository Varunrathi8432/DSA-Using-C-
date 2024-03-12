#include<iostream>
using namespace std;
struct node{
    node* left;
    int item;
    node* right;
    int height;
};
class AVL{
    node* root;
    protected:
    node* insert(node*,int);
    public:
    AVL();
    void insert(int);
    int getroot();
};
AVL::AVL(){
    root=NULL;
}
node* AVL::insert(node* root,int data){
    node* n=new node;
    n->item=data;
    if(root==NULL){
        n->left=NULL;
        n->right=NULL;
        n->height=0;
        root=n;
    }
    else if(data<root->item){
        root->height=(root->left->height)-(root->right->height);
        root->left=insert(root->left,data);
    }
    else{
        root->height=(root->left->height)-(root->right->height);
        root->right=insert(root->right,data);
    }
    return root;
}
void AVL::insert(int data){
    root=insert(root,data);
}
int AVL::getroot(){
    return root->height;
}
int main(){
    AVL tr;
    tr.insert(4);
    tr.insert(2);
    tr.insert(6);
    tr.insert(1);
    tr.insert(3);
    tr.insert(5);
    tr.insert(7);
    cout<<tr.getroot();
    return 0;
}