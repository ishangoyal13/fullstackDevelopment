#include <iostream>
using namespace std;
#include <string.h>
class stack
{
    int top;
    char *elements;
    int capacity;

public:
    stack();
    stack(int);
    stack(const stack &);
    void operator=(const stack &);
    bool isfull();
    bool isempty();
    bool push(char);
    char pop();
    ~stack();
};
// Default constructor
stack::stack()
{
    top = -1;
    capacity = 20;
    elements = new char[capacity];
}
// Destructor
stack::~stack() {
    delete elements;
}
// Parameterised constructor
stack::stack(int x)
{
    capacity = x;
    elements = new char[capacity];
}
// Copy constructor
stack::stack(const stack &b)
{
    top = -1;
    capacity = b.capacity;
    elements = new char[capacity];
}

// Checking stack is full or no
bool stack::isfull()
{
    if (top >= capacity - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Checking stack is empty or no
bool stack::isempty()
{
    if (top < 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
// Pushing the element to the stack
bool stack::push(char x)
{
    if (isfull() == true)
    {
        return false;
    }
    else
    {
        top++;
        elements[top] = x;
        return true;
    }
}
// Removing the element from the stack
char stack::pop()
{
    char c = ' ';
    if (isempty())
    {
        return c;
    }
    else
    {
        char x = elements[top--];
        return x;
    }
}

int main()
{
    stack s, s1(5);
    stack s2 = s1;
    char string[20];
    int len, flag = 0;
    cin >> string;
    len = strlen(string);
    for (int i = 0; i < len; i++)
    {
        if (string[i] == '(')
            s.push(string[i]);
        else if (s.pop() == ' ')
        {
            flag = 1;
            break;
        }
    }
    if (!s.isempty())
        flag = 1;
    if (flag == 0)
        cout << "Balanced";
    else
        cout << "Not balanced";
}