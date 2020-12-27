// Program to reverse individual words in a string, using stack
#include <bits/stdc++.h>
using namespace std;

void reverseEachWord(string str)
{
    stack<char> s;

    for(char ele : str)
    {
        if(ele != ' ')
            s.push(ele);
        
        else 
        {
            while(!s.empty())
            {
                cout << s.top();
                s.pop();
            }
            cout << " ";
        }
    }

    while(!s.empty())
    {
        cout << s.top();
        s.pop();
    }
    cout << "\n";
}

int main()
{
    string str;
    cout << "Enter the string: ";
    getline(cin, str);

    cout << "After reversing: ";
    reverseEachWord(str);

    return 0;
}