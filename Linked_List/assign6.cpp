#include <iostream>
using namespace std;
struct node
{
    int item;
    node *next;
};
class CLL
{
    node *last;

public:
    CLL();
    void insertatbeg(int);
    void insertatend(int);
    node *search(int);
    void insert(node *, int);
    void deleteatbeg();
    void deleteatend();
    void deleteatnode(int);
    void display();
    ~CLL();
};
CLL::CLL()
{
    last = NULL;
}
CLL::~CLL()
{
    while (last)
        deleteatbeg();
}
void CLL::insertatbeg(int data)
{
    node *n;
    n = new node;
    n->item = data;
    if (last == NULL)
    {
        last = n;
        n->next = n;
    }
    else
    {
        n->next = last->next;
        last->next = n;
    }
}
void CLL::insertatend(int data)
{
    node *n;
    n = new node;
    n->item = data;
    if (last == NULL)
    {
        last = n;
        n->next = n;
    }
    else
    {
        n->next = last->next;
        last->next = n;
        last = n;
    }
}
node *CLL::search(int data)
{
    if (last)
    {
        node *t;
        t = last;
        while (t->next != last)
        {
            if (t->item == data)
            {
                // cout<<"search";
                return t;
            }
            t = t->next;
        }
        if (t->next == last && t->item == data)
        {
            // cout<<"search";
            return t;
        }
    }
    return NULL;
}
void CLL::insert(node *a, int data)
{
    node *n;
    n = new node;
    n->item = data;
    if (last && a)
    {
        n->next = a->next;
        a->next = n;
        if (a == last)
            last = n;
    }
}
void CLL::deleteatbeg()
{
    if (last)
    {
        node *t;
        t = last->next;
        if (t == last)
            last = NULL;
        else
        {
            last->next = t->next;
        }
        delete t;
    }
}
void CLL::deleteatend()
{
    if (last)
    {
        node *t;
        t = last;
        if (t->next == last)
        {
            delete t;
            last = NULL;
        }
        else
        {
            while (t->next != last)
            {
                t = t->next;
            }
            t->next = last->next;
            delete last;
            last = t;
        }
    }
}
void CLL::deleteatnode(int data)
{
    if (last)
    {
        node *t, *prev;
        t = last;
        if (t->next == last && t->item == data)
        {
            delete t;
            last = NULL;
        }
        else
        {
            t = t->next;
            prev = last;
            while (t != last)
            {
                if (t->item == data)
                {
                    prev->next = t->next;
                    delete t;
                    break;
                }
                t = t->next;
                prev = prev->next;
            }
            if (t->item == data)
            {
                prev->next = t->next;
                delete t;
                last = prev;
            }
        }
    }
}
void CLL::display()
{
    node *temp = last->next;
    do
    {
        cout << temp->item << " ";
        temp = temp->next;
    } while (temp != last->next);
    cout << endl;
}
int main()
{
    CLL cl;
    cl.insertatend(1);
    cl.insertatend(3);
    cl.insertatend(4);
    cl.insert(cl.search(1), 2);
    cl.deleteatnode(4);
    cl.display();
    return 0;
}