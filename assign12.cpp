#include <iostream>
using namespace std;
struct node
{
    int item;
    node *prev;
    node *next;
};
class Deque
{
    node *Front;
    node *rear;

public:
    Deque();
    void insertatrear(int);
    void insertatFront(int);
    void deleteatFront();
    void deleteatrear();
    int getFront();
    int getrear();
    bool isempty();
    ~Deque();
};
Deque::Deque()
{
    Front = rear = NULL;
}
Deque::~Deque()
{
    while (Front)
        deleteatFront();
}
void Deque::insertatrear(int data)
{
    node *n = new node;
    n->item = data;
    n->next = NULL;
    if (rear == NULL)
    {
        n->prev = NULL;
        rear = Front = n;
    }
    else
    {
        rear->next = n;
        n->prev = rear;
        rear = n;
    }
}
void Deque::insertatFront(int data)
{
    node *n = new node;
    n->item = data;
    n->prev = NULL;
    if (rear == NULL)
    {
        n->next = NULL;
        rear = Front = n;
    }
    else
    {
        n->next = Front;
        Front->prev = n;
        Front = n;
    }
}
void Deque::deleteatFront()
{
    if (Front)
    {
        node *t = Front;
        if (rear == Front)
        {
            delete Front;
            Front = rear = NULL;
        }
        else
        {
            Front = Front->next;
            Front->prev = NULL;
            delete t;
        }
    }
}
void Deque::deleteatrear()
{
    if (rear)
    {
        node *t = rear;
        if (rear == Front)
        {
            delete Front;
            Front = rear = NULL;
        }
        else
        {
            rear = rear->prev;
            rear->next = NULL;
            delete t;
        }
    }
}
int Deque::getFront()
{
    if (Front)
        return Front->item;
    else
        return -1;
}
int Deque::getrear()
{
    if (rear)
        return rear->item;
    else
        return -1;
}
bool Deque::isempty()
{
    if (rear == NULL)
        return true;
    return false;
}
int main()
{
    return 0;
}