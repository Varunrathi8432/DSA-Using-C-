#include <iostream>
#include <stack>
using namespace std;
struct node
{
    node *left;
    int item;
    node *right;
};
class BST
{
    node *root;

protected:
    void preorder2(node *);
    void inorder2(node *);
    void postorder2(node *);
    node *insert2(node *, int);
    node *Delete2(node *, int);
    node *Min(node *);
    void destroyTree(node *root);

public:
    BST();
    bool isempty();
    void insert(int);
    void insert2(int);
    void preorder();
    void preorder2();
    void inorder();
    void inorder2();
    void postorder();
    void postorder2();
    void Delete(int);
    void Delete2(int);
    node *search(int);
    ~BST();
};
BST::BST()
{
    root = NULL;
}
BST::~BST()
{
    destroyTree(root);
}
void BST::destroyTree(node *root)
{
    if (root)
    {
        destroyTree(root->left);
        destroyTree(root->right);
        delete root;
        root = nullptr;
    }
}
bool BST::isempty()
{
    return root == NULL;
}
void BST::insert(int data)
{
    node *n = new node;
    n->item = data;
    n->left = NULL;
    n->right = NULL;
    node *ptr = root;
    if (root == NULL)
        root = n;
    else
    {
        while (ptr != NULL)
        {
            if (ptr->item == data)
            {
                if (ptr->right == NULL)
                    ptr->right = n;
                else
                {
                    ptr = ptr->right;
                    while (ptr->left != NULL)
                        ptr = ptr->left;
                    ptr->left = n;
                }
                break;
            }
            else if (data < ptr->item)
            {
                if (ptr->left == NULL)
                {
                    ptr->left = n;
                    break;
                }
                ptr = ptr->left;
            }
            else
            {
                if (ptr->right == NULL)
                {
                    ptr->right = n;
                    break;
                }
                ptr = ptr->right;
            }
        }
    }
}
node *BST::insert2(node *root, int data)
{
    if (root == NULL)
    {
        node *n = new node;
        n->item = data;
        n->left = NULL;
        n->right = NULL;
        root = n;
        return root;
    }
    if (root->item > data)
    {
        root->left = insert2(root->left, data);
        return root;
    }
    if (root->item < data)
    {
        root->right = insert2(root->right, data);
        return root;
    }
    return NULL;
}
void BST::insert2(int data)
{
    root = insert2(root, data);
}
void BST::preorder()
{
    node *ptr;
    stack<node *> s1;
    s1.push(root);
    while (!s1.empty())
    {
        ptr = s1.top();
        s1.pop();
        cout << ptr->item << " ";
        if (ptr->right)
            s1.push(ptr->right);
        if (ptr->left)
            s1.push(ptr->left);
    }
}
void BST::preorder2(node *root)
{
    if (root == NULL)
        return;
    cout << root->item << " ";
    preorder2(root->left);
    preorder2(root->right);
}
void BST::preorder2()
{
    preorder2(root);
}
void BST::inorder()
{
    node *ptr = root;
    stack<node *> s1;
    while (ptr || !s1.empty())
    {
        while (ptr)
        {
            s1.push(ptr);
            ptr = ptr->left;
        }
        ptr = s1.top();
        s1.pop();
        cout << ptr->item << " ";
        ptr = ptr->right;
    }
}
void BST::inorder2(node *root)
{
    if (root == NULL)
        return;
    inorder2(root->left);
    cout << root->item << " ";
    inorder2(root->right);
}
void BST::inorder2()
{
    inorder2(root);
}
void BST::postorder()
{
    node *ptr;
    stack<node *> s1, s2;
    s1.push(root);
    while (!s1.empty())
    {
        ptr = s1.top();
        s1.pop();
        s2.push(ptr);
        if (ptr->left)
            s1.push(ptr->left);
        if (ptr->right)
            s1.push(ptr->right);
    }
    while (!s2.empty())
    {
        cout << s2.top()->item << " ";
        s2.pop();
    }
}
void BST::postorder2(node *root)
{
    if (root == NULL)
        return;
    postorder2(root->left);
    postorder2(root->right);
    cout << root->item << " ";
}
void BST::postorder2()
{
    postorder2(root);
}
void BST::Delete(int data)
{
    if (root)
    {
        node *prev = root;
        node *ptr = root;
        while (ptr != NULL)
        {
            if (data == ptr->item)
            {
                if (ptr->left == NULL && ptr->right == NULL)
                {
                    if (prev->left == ptr)
                    {
                        delete ptr;
                        prev->left = NULL;
                    }
                    if (prev->right == ptr)
                    {
                        delete ptr;
                        prev->right = NULL;
                    }
                    if (ptr == root)
                    {
                        delete ptr;
                        root = NULL;
                    }
                    break;
                }
                else if (ptr->left == NULL)
                {
                    if (prev->left == ptr)
                    {
                        prev->left = ptr->right;
                        delete ptr;
                    }
                    if (prev->right == ptr)
                    {
                        prev->right = ptr->right;
                        delete ptr;
                    }
                    if (ptr == root)
                    {
                        ptr = ptr->right;
                        root = ptr;
                        delete prev;
                    }
                    break;
                }
                else if (ptr->right == NULL)
                {
                    if (prev->left == ptr)
                    {
                        prev->left = ptr->left;
                        delete ptr;
                    }
                    if (prev->right == ptr)
                    {
                        prev->right = ptr->left;
                        delete ptr;
                    }
                    if (ptr == root)
                    {
                        ptr = ptr->left;
                        root = ptr;
                        delete prev;
                    }
                    break;
                }
                else
                {
                    node *t = ptr->right;
                    if (t->left == NULL)
                    {
                        t->left = ptr->left;
                        if (prev->left == ptr)
                            prev->left = t;
                        if (prev->right == ptr)
                            prev->right = t;
                        if (ptr == root)
                            root = t;
                        delete ptr;
                    }
                    else
                    {
                        node *t1 = NULL;
                        while (t->left != NULL)
                        {
                            t1 = t;
                            t = t->left;
                        }
                        ptr->item = t->item;
                        t1->left = NULL;
                    }
                    break;
                }
            }
            else if (data < ptr->item)
            {
                prev = ptr;
                ptr = ptr->left;
            }
            else
            {
                prev = ptr;
                ptr = ptr->right;
            }
        }
    }
}
node *BST::Min(node *root)
{
    while (root->left)
        root = root->left;
    return root;
}
node *BST::Delete2(node *root, int data)
{
    if (root == NULL)
        return NULL;
    if (root->item == data)
    {
        node *t;
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        else if (root->left == NULL)
        {
            t = root->right;
            delete root;
            return t;
        }
        else if (root->right == NULL)
        {
            t = root->left;
            delete root;
            return t;
        }
        else
        {
            t = Min(root->right);
            if (t == root->right)
            {
                t->left = root->left;
                delete root;
                return t;
            }
            else
            {
                root->item = t->item;
                root->right = Delete2(root->right, t->item);
            }
        }
    }
    else if (data < root->item)
        root->left = Delete2(root->left, data);
    else
        root->right = Delete2(root->right, data);
    return root;
}
void BST::Delete2(int data)
{
    root = Delete2(root, data);
}
node *BST::search(int data)
{
    node *ptr = root;
    while (ptr)
    {
        if (ptr->item == data)
            break;
        else if (ptr->item > data)
            ptr = ptr->left;
        else
            ptr = ptr->right;
    }
    return ptr;
}
int main()
{
    BST bt;
    bt.insert(4);
    bt.insert(2);
    bt.insert(6);
    bt.insert(1);
    bt.insert(3);
    bt.insert(5);
    bt.insert(7);
    bt.insert(0);
    bt.insert(8);
    bt.Delete2(7);
    bt.preorder();
    return 0;
}