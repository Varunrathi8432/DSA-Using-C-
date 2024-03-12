#include <iostream>
using namespace std;
class stack
{
    int size;
    int top;
    int *ptr;

public:
    stack(int);
    ~stack();
    void push(int);
    int peek();
    void pop();
    bool isFull();
    bool isempty();
    void reverse();
    int min();
    void display();
};
stack::stack(int len)
{
    top = -1;
    size = len;
    ptr = new int[size];
}
stack::~stack()
{
    delete[] ptr;
}
void stack::push(int data)
{
    if (top == size - 1)
        cout << "stack overFlow" << endl;
    else
    {
        top++;
        ptr[top] = data;
    }
}
int stack::peek()
{
    if (top != -1)
    {
        return ptr[top];
    }
    return -1;
}
void stack::pop()
{
    if (top == -1)
        cout << "stack underFlow" << endl;
    else
    {
        top--;
    }
}
bool stack::isempty()
{
    if (top == -1)
        return true;
    return false;
}
bool stack::isFull()
{
    if (top == size - 1)
        return true;
    return false;
}
void stack::reverse()
{
    if (top != -1)
    {
        int i = 0;
        int j = top;
        while (j >= i)
        {
            swap(ptr[i], ptr[j]);
            i++;
            j--;
        }
    }
}
int stack::min()
{
    if (top != -1)
    {
        int min = ptr[0];
        for (int i = 1; i <= top; i++)
        {
            if (ptr[i] < min)
                min = ptr[i];
        }
        return min;
    }
    return -1;
}
void stack::display()
{
    while (top != -1)
    {
        cout << ptr[top];
        pop();
    }
}
int main()
{
    stack s(4);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    // s.pop();
    // cout<<s.min();
    // s.reverse();
    s.display();
    return 0;
}