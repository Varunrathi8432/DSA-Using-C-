#include <iostream>
using namespace std;
void t1(int n)
{
    if (n > 0)
    {
        t1(n - 1);
        cout << n << " ";
    }
}
void t2(int n)
{
    if (n > 0)
    {
        cout << n << " ";
        t2(n - 1);
    }
}
void t3(int n)
{
    if (n > 0)
    {
        t3(n - 1);
        cout << 2 * n - 1 << " ";
    }
}
void t4(int n)
{
    if (n > 0)
    {
        cout << 2 * n - 1 << " ";
        t4(n - 1);
    }
}
void t5(int n)
{
    if (n > 0)
    {
        t5(n - 1);
        cout << 2 * n << " ";
    }
}
void t6(int n)
{
    if (n > 0)
    {
        cout << 2 * n << " ";
        t6(n - 1);
    }
}
void t7(int n)
{
    if (n > 0)
    {
        t7(n - 1);
        cout << n * n << " ";
    }
}
void t8(int n)
{
    if (n > 0)
    {
        cout << n * n << " ";
        t8(n - 1);
    }
}
void t9(int n)
{
    if (n > 0)
    {
        t9(n - 1);
        cout << n * n * n << " ";
    }
}
void t10(int n)
{
    if (n > 0)
    {
        cout << n * n * n << " ";
        t10(n - 1);
    }
}
int main()
{
    t10(10);
    return 0;
}