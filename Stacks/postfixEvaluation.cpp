// Program to evaluate Postfix expression
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
        return b + a;
    
    else if(op == '-')
        return b - a;
    
    else if(op == '*')
        return b * a;
    
    else if(op == '/')
        return b / a;
    
    else if(op == '^')
        return pow(b, a);
    
    else 
        return INT_MIN;
}

float postfixEval(string exp)
{
    int a, b;
    stack<float> s;

    for(char ch: exp)
    {
        if(isOperator(ch))
        {
            a = s.top();
            s.pop();
            b = s.top();
            s.pop();
            s.push(operation(a, b, ch));
        }

        else if(isOperand(ch))
        {
            s.push(scanNum(ch));
        }
    }
    return s.top();
}

int main()
{
    string exp = "53+62/*35*+";
    cout << "The result is: " << postfixEval(exp) << "\n";

    return 0;
}