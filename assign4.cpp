#include <iostream>
using namespace std;
class node
{
public:
    int item;
    node *next;
};
class SLL
{
    node *start;

public:
    SLL();
    void beginsert(int);
    void endinsert(int);
    node *search(int);
    void insert(node *, int);
    void begdelete();
    void enddelete();
    void Delete1(node *);
    void Delete2(int);
    ~SLL();
};
SLL::SLL()
{
    start = NULL;
}
SLL::~SLL()
{
    while (start != NULL)
    {
        begdelete();
    }
}
void SLL::beginsert(int data)
{
    node *newnode;
    newnode = new node;
    newnode->item = data;
    newnode->next = start;
    start = newnode;
}
void SLL::endinsert(int data)
{
    node *newnode;
    node *temp;
    newnode = new node;
    newnode->item = data;
    newnode->next = NULL;
    if (start == NULL)
        start = newnode;
    else
    {
        temp = start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}
node *SLL::search(int data)
{
    node *temp;
    temp = start;
    while (temp->item != data)
    {
        temp = temp->next;
        if (temp == NULL)
            return NULL;
    }
    return temp;
}
void SLL::insert(node *n, int data)
{
    node *newnode;
    newnode = new node;
    newnode->item = data;
    newnode->next = n->next;
    n->next = newnode;
}
void SLL::begdelete()
{
    node *temp;
    if (start)
    {
        temp = start;
        start = start->next;
        delete temp;
    }
}
void SLL::enddelete()
{
    node *temp;
    temp = start;
    if (start)
    {
        if (temp->next == NULL)
        {
            delete temp;
            start = NULL;
        }
        else
        {
            while (temp->next->next != NULL)
                temp = temp->next;
            delete temp->next;
            temp->next = NULL;
        }
    }
}
void SLL::Delete1(node *a)
{
    if (a == NULL)
    {
        return;
    }
    if (start == a)
    {
        start = start->next;
        delete a;
        return;
    }
    node *temp = start;
    while (temp != NULL && temp->next != a)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        return;
    }
    temp->next = a->next;
    delete a;
}

void SLL::Delete2(int data)
{
    if (start == NULL)
    {
        return;
    }
    node *temp = start;
    if (temp->item == data)
    {
        start = temp->next;
        delete temp;
        return;
    }
    while (temp->next->item != data && temp->next != NULL)
    {
        temp = temp->next;
    }
    if (temp->next == NULL)
    {
        return;
    }
    node *t = temp->next;
    temp->next = t->next;
    delete t;
}
int main()
{
    SLL ll;
    ll.beginsert(21);
    ll.endinsert(31);
    ll.beginsert(41);
    // cout<<ll.search(31);
    // ll.Delete1(ll.search(21));
    ll.Delete2(21);
    // ll.Delete1(ll.search(31));
    ll.Delete2(41);
    cout << ll.search(31)->item;
    return 0;
}