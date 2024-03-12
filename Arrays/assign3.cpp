#include <iostream>
using namespace std;
class Dynarray
{
    int size;
    int lastindex;
    int *ptr;

protected:
    void doublearray();
    void halFarray();

public:
    Dynarray(int);
    ~Dynarray();
    void append(int);
    void display();
    int getsize();
    bool isempty();
    bool isFull();
    void insert(int, int);
    void edit(int, int);
    void Delete(int);
    int getdata(int);
    int count();
    int search(int);
};
Dynarray::Dynarray(int size)
{
    this->size = size;
    ptr = new int[size];
    lastindex = -1;
}
Dynarray::~Dynarray()
{
    delete[] ptr;
}
int Dynarray::getsize()
{
    return size;
}
bool Dynarray::isempty()
{
    return lastindex == -1;
}
bool Dynarray::isFull()
{
    return lastindex == size - 1;
}
void Dynarray ::doublearray()
{
    size = size * 2;
    int *temp;
    temp = new int[size];
    for (int i = 0; i < size; i++)
    {
        temp[i] = ptr[i];
    }
    delete[] ptr;
    ptr = temp;
}
void Dynarray::append(int data)
{
    if (isFull())
    {
        doublearray();
    }
    ptr[lastindex + 1] = data;
    lastindex += 1;
}
void Dynarray::display()
{
    for (int i = 0; i <= lastindex; i++)
    {
        cout << ptr[i] << endl;
    }
    cout << endl;
}

void Dynarray::halFarray()
{
    size = size / 2;
    int *temp;
    temp = new int[size];
    for (int i = 0; i < size; i++)
    {
        temp[i] = ptr[i];
    }
    delete[] ptr;
    ptr = temp;
}

void Dynarray::insert(int index, int data)
{
    if (index > lastindex + 1 || index < 0)
        return;
    if (isFull())
        doublearray();
    for (int i = lastindex; i >= index; i--)
    {
        ptr[i + 1] = ptr[i];
    }
    ptr[index] = data;
    lastindex += 1;
}

void Dynarray::edit(int index, int data)
{
    if (index < 0 || index > lastindex)
        cout << "\ninvalid index";
    else
        ptr[index] = data;
}

void Dynarray::Delete(int index)
{
    if (index < 0 || index > lastindex)
        return;
    for (int i = index; i < lastindex; i++)
    {
        ptr[i] = ptr[i + 1];
    }
    lastindex -= 1;
    if (size > 1 && lastindex + 1 <= size / 2)
        halFarray();
}
int Dynarray::getdata(int index)
{
    if (index < 0 || index > lastindex)
    {
        cout << "\n invalid index" << endl;
        throw new exception();
    }
    return ptr[index];
}

int Dynarray::count()
{
    return lastindex + 1;
}

int Dynarray::search(int data)
{
    for (int i = 0; i <= lastindex; i++)
    {
        if (ptr[i] == data)
            return i;
    }
    return -1;
}
int main()
{
    Dynarray d1(2);
    d1.append(21);
    d1.append(21);
    d1.append(21);
    d1.append(21);
    d1.append(21);
    d1.Delete(1);
    cout << d1.getsize() << endl;
    d1.display();
    return 0;
}