// Program to generate Prefix expression from Infix expression
#include <bits/stdc++.h>
using namespace std;

int precedence(char op)
{
    if(op == '^')
        return 3;

    else if(op == '*' || op == '/')
        return 2;

    else if(op == '+' || op == '-')
        return 1;

    else 
        return -1;
}

int isChar(char c)
{
    return ((c >= 'a' && c <= 'z') ||  
            (c >= 'A' && c <= 'Z'));
}

string infixToPostfix(string exp)
{
    stack<char> s;
    s.push('N');

    int l = exp.length();
    char c;

    string newExp;

    for(int i = 0; i < l; i++)
    {
        if(isChar(exp[i]))
            newExp = newExp + exp[i];
        
        else if(exp[i] == '(')
            s.push('(');
        
        else if(exp[i] == ')')
        {
            while(s.top() != 'N' && s.top() != '(')
            {
                c = s.top();
                s.pop();

                newExp = newExp + c;
            }
            if(s.top() == '(')
            {
                c = s.top();
                s.pop();
            }
        }

        else
        {
            while(s.top() != 'N' && precedence(exp[i]) <= precedence(s.top()))
            {
                c = s.top();
                s.pop();

                newExp = newExp + c;
            }
            s.push(exp[i]);
        }
    }

    while(s.top() != 'N')
    {
        c = s.top();
        s.pop();

        newExp = newExp + c;
    }

    return newExp;
}

void infixToPrefix(string exp)
{
    int l = exp.length();

    reverse(exp.begin(), exp.end());

    for(int i = 0; i < l; i++)
    {
        if(exp[i] == '(')
        {
            exp[i] = ')';
            i++;
        }
        else if(exp[i] == ')')
        {
            exp[i] = '(';
            i++;
        }
    }

    string newExp = infixToPostfix(exp);
    reverse(newExp.begin(), newExp.end());

    cout << newExp << "\n";
}

int main()
{
    string exp = "(a-b/c)*(d/e-f)"; 
    infixToPrefix(exp); 
    
    return 0; 
}