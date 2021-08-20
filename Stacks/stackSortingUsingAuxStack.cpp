// Sorting a stack using auxiliary stack
#include<bits/stdc++.h>
using namespace std;

stack<int> sortStack(stack<int> &s)
{
    stack<int> aux;

    while(!s.empty())
    {
        int temp = s.top();
        s.pop();

        while(!aux.empty() && (aux.top() > temp))
        {
            s.push(aux.top());
            aux.pop();
        }

        aux.push(temp);
    }

    return aux;
}

int main()
{
    stack<int> s;

    s.push(34);
    s.push(14);
    s.push(31);
    s.push(10);
    s.push(5);

    stack<int> aux = sortStack(s);
    
    while(!aux.empty())
    {
        cout << aux.top() << " ";
        aux.pop();
    }
    cout << "\n";

    return 0;
}