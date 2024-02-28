#include <iostream>
using namespace std;
class Queue
{
    int size;
    int Front;
    int rear;
    int *ptr;

public:
    Queue(int);
    void insert(int);
    int getrear();
    bool isempty();
    bool isFull();
    int getFront();
    int Delete();
    int count();
    ~Queue();
};
Queue::Queue(int cap)
{
    size = cap;
    ptr = new int[size];
    Front = rear = -1;
}
Queue::~Queue()
{
    delete[] ptr;
}
void Queue::insert(int data)
{
    if (isFull())
    {
        cout << "queue is overFlow";
    }
    else if (isempty())
    {
        Front = rear = 0;
        ptr[rear] = data;
    }
    else if (rear == size - 1)
    {
        rear = 0;
        ptr[rear] = data;
    }
    else
    {
        rear++;
        ptr[rear] = data;
    }
}
int Queue::getrear()
{
    if (isempty())
        return -1;
    return ptr[rear];
}
int Queue::getFront()
{
    return ptr[Front];
}
bool Queue::isempty()
{
    return Front == -1;
}
bool Queue::isFull()
{
    return rear - Front == size - 1 || rear == Front - 1;
}
int Queue::Delete()
{
    int temp;
    if (isempty())
    {
        cout << "Queue is empty";
        return -1;
    }
    else if (rear == Front)
    {
        temp = ptr[Front];
        rear = Front = -1;
    }
    else if (Front == size - 1)
    {
        temp = ptr[Front];
        Front = 0;
    }
    else
    {
        temp = ptr[Front];
        Front++;
    }
    return temp;
}
int Queue::count()
{
    if (isempty())
        return 0;
    else if (rear >= Front)
    {
        return rear - Front + 1;
    }
    else
        return size + rear - Front + 1;
}
int main()
{
    Queue Q(5);
    Q.insert(1);
    Q.insert(2);
    Q.insert(3);
    Q.insert(4);
    Q.insert(5);
    Q.Delete();
    Q.Delete();
    Q.Delete();
    Q.Delete();
    Q.Delete();
    Q.insert(1);
    Q.insert(2);
    cout << Q.getFront() << " ";
    // cout<<Q.getrear();
    cout << Q.count();
    return 0;
}