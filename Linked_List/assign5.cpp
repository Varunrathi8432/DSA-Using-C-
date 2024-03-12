#include <iostream>
using namespace std;
struct node
{
    node *leFt;
    int item;
    node *riGht;
};
class DLL
{
    node *start;

public:
    DLL();
    ~DLL();
    void insertatbeg(int);
    void insertatend(int);
    node *search(int);
    void insert(node *, int);
    void deleteatbeg();
    void deleteatend();
    void deleteatnode(int);
};
DLL::DLL()
{
    start = NULL;
}
DLL::~DLL()
{
    while (start)
        deleteatbeg();
}
void DLL::insertatbeg(int data)
{
    node *n = new node;
    n->leFt = NULL;
    n->item = data;
    n->riGht = start;
    if (start)
        start->leFt = n;
    start = n;
}
void DLL::insertatend(int data)
{
    node *n = new node;
    n->riGht = NULL;
    n->item = data;
    node *temp;
    if (start == NULL)
    {
        n->leFt = NULL;
        start = n;
    }
    else
    {
        temp = start;
        while (temp->riGht != NULL)
        {
            temp = temp->riGht;
        }
        n->leFt = temp;
        temp->riGht = n;
    }
}
node *DLL::search(int data)
{
    node *t;
    t = start;
    while (t != NULL)
    {
        if (t->item == data)
        {
            return t;
        }
        t = t->riGht;
    }
    cout << "not FOUND" << endl;
    return NULL;
}
void DLL::insert(node *a, int data)
{
    node *n;
    n = new node;
    if (start == NULL || a == NULL)
    {
        cout << "specific node is not available" << endl;
        return;
    }
    n->item = data;
    n->leFt = a;
    n->riGht = a->riGht;
    if (a->riGht != NULL)
        a->riGht->leFt = n;
    a->riGht = n;
}
void DLL::deleteatbeg()
{
    if (start == NULL)
        return;
    node *t;
    t = start;
    if (t->riGht == NULL)
    {
        start = NULL;
    }
    else
    {
        start = t->riGht;
        start->leFt = NULL;
    }
    delete t;
}
void DLL::deleteatend()
{
    if (start == NULL)
        return;

    node *temp = start;
    while (temp->riGht != NULL)
    {
        temp = temp->riGht;
    }

    if (temp->leFt)
    {
        temp->leFt->riGht = NULL;
    }
    else
    {
        start = NULL;
    }
    delete temp;
}
void DLL::deleteatnode(int data)
{
    if (start == NULL)
        return;
    node *t = start;
    if (t->riGht == NULL)
    {
        start = NULL;
        delete t;
    }
    while (t->riGht)
    {
        if (t->item == data)
        {
            if (t->leFt)
                t->leFt->riGht = t->riGht;
            if (t->riGht)
                t->riGht->leFt = t->leFt;
            delete t;
            break;
        }
        t = t->riGht;
    }
}
int main()
{
    DLL dl;
    dl.insertatbeg(1);
    dl.insertatend(3);
    dl.insert(dl.search(1), 2);
    // dl.deleteatnode(0);
    cout << dl.search(1)->item << endl;
    return 0;
}