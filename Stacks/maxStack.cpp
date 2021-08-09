// Stack returning max element in O(1) time and space complexity
#include <bits/stdc++.h>
using namespace std;

class Stack
{
    stack<int> s;
    int max;

public:
    void push(int x);
    void pop();
    int peek();
    int getMax();
};

void Stack::push(int x)
{
    if(s.empty())
    {
        max = x;
        s.push(x);
    }

    if(x > max)
    {
        s.push(2 * x - max);
        max = x;
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

    if(t > max)
        max = 2 * max - t;
}

int Stack::peek()
{
    if(s.empty())
    {
        cout << "Stack Underflow !\n";
        return -1;
    }

    int t = s.top();
    
    if(t > max)
        return max;
    else 
        return t;
}

int Stack::getMax()
{
    if(s.empty())
    {
        cout << "Stack Underflow !\n";
        return -1;
    }
    else 
        return max;
}