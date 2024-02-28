#include <iostream>
using namespace std;
struct node
{
    char item;
    node *next;
};
class stack
{
    node *top;

public:
    stack();
    ~stack();
    void push(char);
    node *peek();
    char pop();
    stack &operator=(stack &);
    bool operator==(stack &);
    void display();
};
stack::stack()
{
    top = NULL;
}
stack::~stack()
{
    while (top)
    {
        pop();
    }
}
void stack::push(char data)
{
    node *n = new node;
    n->item = data;
    n->next = top;
    top = n;
}
node *stack::peek()
{
    if (top == NULL)
    {
        return NULL; // Return NULL when the stack is empty
    }
    return top;
}
char stack::pop()
{
    char x;
    if (top == NULL)
    {
        cout << "empty stack" << endl;
    }
    else if (top->next == NULL)
    {
        x = top->item;
        delete top;
        top = NULL;
    }
    else
    {
        node *t = top;
        top = top->next;
        x = t->item;
        delete t;
    }
    return x;
}
stack &stack::operator=(stack &s)
{
    if (this != &s)
    {
        while (top)
        {
            pop();
        }
        node *top = NULL;
        node *temp = s.peek();
        while (temp)
        {
            node *newnode = new node;
            newnode->item = temp->item;
        }
    }
    return *this;
}
bool stack::operator==(stack &s)
{
    node *t1 = top;
    node *t2 = s.top;

    while (t1 && t2)
    {
        if (t1->item != t2->item)
        {
            return false;
        }
        t1 = t1->next;
        t2 = t2->next;
    }
    return true;
}
void stack::display()
{
    node *t = top;
    while (t)
    {
        cout << t->item;
        t = t->next;
    }
}
void reversestack(stack &s)
{
    stack s1;
    while (s.peek())
    {
        s1.push(s.peek()->item);
        s.pop();
    }
    while (s1.peek())
    {
        cout << s1.peek()->item;
        s1.pop();
    }
}
bool palindrome(stack &s)
{
    stack s1;
    node *temp = s.peek();
    while (temp)
    {
        s1.push(temp->item);
        temp = temp->next;
    }
    return s1 == s;
}
int precedence(char c)
{
    if (c == '(')
        return 3;
    if (c == '*' || c == '/')
        return 2;
    if (c == '+' || c == '-')
        return 1;
    return 0;
}
string intopost(string q)
{
    stack s1;
    string p;
    s1.push('(');
    q = q + ')';
    for (int i = 0; i < q.size(); i++)
    {
        if (q[i] != '*' && q[i] != '/' && q[i] != '-' && q[i] != '+' && q[i] != ')' && q[i] != '(')
        {
            p += q[i];
        }
        else if (q[i] == '(' || s1.peek()->item == '(')
        {
            s1.push(q[i]);
        }
        else if (q[i] == ')')
        {
            while (s1.peek() != NULL && s1.peek()->item != '(')
            {
                p += s1.pop();
            }
            if (s1.peek() != NULL && s1.peek()->item == '(')
            {
                s1.pop(); // Pop '(' from the stack
            }
        }
        else if (precedence(q[i]) > precedence(s1.peek()->item))
        {
            s1.push(q[i]);
        }
        else
        {
            while (s1.peek() != NULL && s1.peek()->item != '(' && precedence(q[i]) <= precedence(s1.peek()->item))
            {
                p += s1.pop();
            }
            s1.push(q[i]);
        }
    }
    while (s1.peek() != NULL)
    {
        if (s1.peek()->item != '(')
        {
            p += s1.pop();
        }
        else
        {
            s1.pop(); // Pop any remaining '('
        }
    }
    return p;
}
int prec(char c)
{
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

void infixToPostfix(string s)
{

    stack st;
    string result;

    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];

        // If the scanned character is
        // an operand, add it to output string.
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            result += c;

        // If the scanned character is an
        // ‘(‘, push it to the stack.
        else if (c == '(')
            st.push('(');

        // If the scanned character is an ‘)’,
        // pop and add to output string from the stack
        // until an ‘(‘ is encountered.
        else if (c == ')')
        {
            while (st.peek()->item != '(')
            {
                result += st.peek()->item;
                st.pop();
            }
            st.pop();
        }

        // If an operator is scanned
        else
        {
            while (st.peek() != NULL && prec(s[i]) <= prec(st.peek()->item))
            {
                result += st.peek()->item;
                st.pop();
            }
            st.push(c);
        }
    }

    // Pop all the remaining elements from the stack
    while (st.peek() != NULL)
    {
        result += st.peek()->item;
        st.pop();
    }

    cout << result << endl;
}
int main()
{
    stack s1;
    string q;
    cin >> q;
    infixToPostfix(q);
    return 0;
}
