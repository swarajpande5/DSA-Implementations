// Program to evaluate Prefix expression
#include <bits/stdc++.h>
using namespace std;

float scanNum(char ch)
{
    int value = ch;
    return float(value - '0');
}

bool isOperator(char ch)
{
    return (ch == '+'|| ch == '-'|| ch == '*'|| ch == '/' || ch == '^');
}

bool isOperand(char ch)
{
    return (ch >= '0' && ch <= '9');
}

float operation(int a, int b, char op)
{
    if(op == '+')
        return a + b;
    
    else if(op == '-')
        return a - b;
    
    else if(op == '*')
        return a * b;
    
    else if(op == '/')
        return a / b;
    
    else if(op == '^')
        return pow(a, b);
    
    else 
        return INT_MIN;
}

float prefixEval(string exp)
{
    int a, b;
    stack<float> s;

    for(auto it = exp.rbegin(); it != exp.crend(); it++)
    {
        if(isOperator(*it))
        {
            a = s.top();
            s.pop();
            b = s.top();
            s.pop();
            s.push(operation(a, b, *it));
        }

        else if(isOperand(*it))
        {
            s.push(scanNum(*it));
        }
    }
    return s.top();
}

int main()
{
    string exp = "-+7*45+20";
    cout << "The result is: " << prefixEval(exp) << "\n";

    return 0;
}