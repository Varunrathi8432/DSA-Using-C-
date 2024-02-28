#include <iostream>
using namespace std;
struct node
{
    int item;
    node *next;
};
class Queue
{
    node *Front;
    node *rear;

public:
    Queue();
    void insert(int);
    int getrear();
    int getFront();
    int Delete();
    int count();
    ~Queue();
};
Queue::Queue()
{
    Front = rear = NULL;
}
Queue::~Queue()
{
    while (Front)
        Delete();
}
void Queue::insert(int data)
{
    node *n = new node;
    n->item = data;
    if (rear == NULL)
        Front = rear = n;
    else
    {
        rear->next = n;
        rear = n;
    }
    n->next = NULL;
}
int Queue::getrear()
{
    if (rear == NULL)
        return -1;
    return rear->item;
}
int Queue::getFront()
{
    if (rear == NULL)
        return -1;
    return Front->item;
}
int Queue::Delete()
{
    node *t = Front;
    if (t == NULL)
        return -1;
    else if (Front == rear)
    {
        delete Front;
        Front = rear = NULL;
    }
    else
    {
        Front = Front->next;
        int x = t->item;
        delete t;
        return x;
    }
}
int Queue::count()
{
    node *t = Front;
    int i = 0;
    while (t != NULL)
    {
        t = t->next;
        i++;
    }
    return i;
}
int main()
{
    return 0;
}