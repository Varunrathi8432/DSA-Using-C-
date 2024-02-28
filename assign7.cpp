#include <iostream>
using namespace std;
class node
{
public:
    int item;
    node *next;
    node *prev;
};
class CDLL
{
    node *start;

public:
    CDLL();
    void insertatbeg(int);
    void insertatend(int);
    node *search(int);
    void display();
    void insertatnode(node *, int);
    void deleteatbeg();
    void deleteatend();
    void deleteatnode(int);
    ~CDLL();
};
CDLL::CDLL()
{
    start = NULL;
}
CDLL::~CDLL()
{
    while (start)
        deleteatend();
}
void CDLL::insertatbeg(int data)
{
    node *n = new node;
    n->item = data;
    if (start)
    {
        n->prev = start->prev;
        n->next = start;
        start->prev->next = n;
        start->prev = n;
        start = n;
    }
    else
    {
        n->prev = n;
        n->next = n;
        start = n;
    }
}
void CDLL::insertatend(int data)
{
    node *n = new node;
    n->item = data;
    if (start)
    {
        n->prev = start->prev;
        n->next = start;
        start->prev->next = n;
        start->prev = n;
    }
    else
    {
        n->prev = n;
        n->next = n;
        start = n;
    }
}
node *CDLL::search(int data)
{
    if (start)
    {
        node *t = start;
        do
        {
            if (t->item == data)
            {
                return t;
            }
            t = t->next;
        } while (t != start);
    }
    return NULL;
}
void CDLL::display()
{
    if (start)
    {
        node *t = start;
        do
        {
            cout << t->item << " ";
            t = t->next;
        } while (t != start);
    }
    else
    {
        cout << "list is empty" << endl;
    }
}
void CDLL::insertatnode(node *a, int data)
{
    if (start && a)
    {
        node *n = new node; 
        n->item = data;
        n->prev = a;
        n->next = a->next;
        a->next->prev = n;
        a->next = n;
    }
}
void CDLL::deleteatbeg()
{
    if (start)
    {
        if (start->next == start)
        {
            delete start;
            start = NULL;
        }
        else
        {
            start->next->prev = start->prev;
            start->prev->next = start->next;
            node *temp = start;
            start = temp->next;
            delete temp;
        }
    }
}
void CDLL::deleteatend()
{
    if (start)
    {
        if (start->next == start)
        {
            delete start;
            start = NULL;
        }
        else
        {
            node *last = start->prev;
            last->prev->next = start;
            start->prev = last->prev;
            delete last;
        }
    }
}
void CDLL::deleteatnode(int data)
{
    if (start)
    {
        node *temp;
        temp = start;
        if (temp->next == start && temp->item == data)
        {
            delete temp;
            start = NULL;
        }
        else
        {
            do
            {
                if (temp->item == data)
                {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                    if (temp == start)
                        start = start->next;
                    delete temp;
                    break;
                }
                temp = temp->next;
            } while (temp != start);
        }
    }
}
int main()
{
    CDLL cdl;
    cdl.insertatbeg(1);
    cdl.insertatend(2);
    cdl.insertatend(4);
    cdl.insertatnode(cdl.search(2), 3);
    // cdl.deleteatend();
    cdl.deleteatnode(1);
    // cout<<cdl.search(2)->item<<endl;
    cdl.display();
    return 0;
}