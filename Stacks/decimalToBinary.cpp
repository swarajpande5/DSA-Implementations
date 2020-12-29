// Program to calculate binary of a decimal number using stacks
#include <bits/stdc++.h>
using namespace std;

void binary(int n)
{
    int rem, top;
    stack<int> s;

    while(n > 0)
    {
        rem = n % 2;
        n = n / 2;
        s.push(rem);
    }
    while(!s.empty())
    {
        top = s.top();
        s.pop();
        cout << top;
    }
    cout << "\n";
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << "Binary: ";
    binary(n);

    return 0;
}