#include <iostream>
using namespace std;
struct node
{
    int item;
    int pno;
    node *next;
};
class priorityqueue
{
    node *start;

public:
    priorityqueue();
    void insert(int, int);
    void Delete();
    int proelement();
    int pronumber();
    bool isempty();
    void display();
    ~priorityqueue();
};
priorityqueue::priorityqueue()
{
    start = NULL;
}
priorityqueue::~priorityqueue()
{
    while (start)
        Delete();
}
void priorityqueue::insert(int data, int priority)
{
    node *n = new node;
    n->item = data;
    n->pno = priority;
    if (start == NULL || start->pno < n->pno)
    {
        n->next = start;
        start = n;
    }
    else
    {
        node *t = start;
        while (t->next != NULL)
        {
            if (t->next->pno < n->pno)
            {
                n->next = t->next;
                t->next = n;
                break;
            }
            t = t->next;
        }
        if (t->next == NULL)
        {
            t->next = n;
            n->next = NULL;
        }
    }
}
void priorityqueue::Delete()
{
    if (start)
    {
        node *t = start;
        start = start->next;
        delete t;
    }
}
int priorityqueue::proelement()
{
    if (start)
    {
        return start->item;
    }
    return -1;
}
int priorityqueue::pronumber()
{
    if (start)
    {
        return start->pno;
    }
    return -1;
}
bool priorityqueue::isempty()
{
    return start == NULL;
}
void priorityqueue::display()
{
    node *t = start;
    while (t != NULL)
    {
        cout << t->item << " ";
        t = t->next;
    }
}
int main()
{
    priorityqueue pq;
    pq.insert(1, 10);
    pq.insert(0, 11);
    pq.insert(2, 9);
    pq.insert(4, 7);
    pq.insert(3, 8);
    pq.insert(5, 6);
    pq.Delete();
    cout << pq.pronumber() << " ";
    cout << pq.proelement() << " ";
    pq.display();
    return 0;
}