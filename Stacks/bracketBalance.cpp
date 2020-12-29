/*
    Program to check whether the given bracket sequence
    is balanced or not.
*/
#include <bits/stdc++.h>
using namespace std;

bool isBracketBalanced(string exp)
{
    stack<char> s;
    char ch;

    for(char ele: exp)
    {
        if(ele == '(' || ele == '[' || ele == '{')
        {
            s.push(ele);
            continue;
        }

        if(s.empty())
            return false;

        switch(ele)
        {
            case ')':
                        ch = s.top();
                        s.pop();
                        if(ch == '{' || ch == '[')
                            return false;
                        break;
            
            case ']':
                        ch = s.top();
                        s.pop();
                        if(ch == '(' || ch == '{')
                            return false;
                        break;

            case '}':
                        ch = s.top();
                        s.pop();
                        if(ch == '(' || ch == '[')
                            return false;
                        break;
        }
    }
    
    return (s.empty());
}

int main()
{
    string expr = "({()}[])"; 

    if (isBracketBalanced(expr)) 
        cout << "Balanced\n"; 
    else
        cout << "Not Balanced\n"; 
    return 0; 
}