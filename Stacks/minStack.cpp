// Stack returning min element in O(1) time and space complexity
#include <bits/stdc++.h>
using namespace std;

class Stack
{
    stack<int> s;
    int min;

public:
    void push(int x);
    void pop();
    int peek();
    int getMin();
};

void Stack::push(int x)
{
    if(s.empty())
    {
        min = x;
        s.push(x);
    }

    if(x < min)
    {
        s.push(2 * x - min);
        min = x;
    }
    else 
        s.push(x);
}

void Stack::pop()
{
    if(s.empty())
    {
        cout << "Stack Underflow !\n";
        return;
    }

    int t = s.top();
    s.pop();

    if(t < min)
        min = 2 * min - t;
}

int Stack::peek()
{
    if(s.empty())
    {
        cout << "Stack Underflow !\n";
        return -1;
    }

    int t = s.top();
    
    if(t < min)
        return min;
    else 
        return t;
}

int Stack::getMin()
{
    if(s.empty())
    {
        cout << "Stack Underflow !\n";
        return -1;
    }
    else 
        return min;
}