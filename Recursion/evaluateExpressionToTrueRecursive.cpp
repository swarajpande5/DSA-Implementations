// Evaluate expression to true (recursive): https://www.geeksforgeeks.org/boolean-parenthesization-problem-dp-37/
#include <bits/stdc++.h>
using namespace std;

int solve(string s, int i, int j, bool isTrue)
{
    if(i >= j)
    {
        if(isTrue)
            return s[i] == 'T';
        else 
            return s[i] == 'F';
    }

    int ans = 0;
    for(int k = i + 1; k < j; k += 2)
    {
        int l_T = solve(s, i, k - 1, true);
        int l_F = solve(s, i, k - 1, false);
        int r_T = solve(s, k + 1, j, true);
        int r_F = solve(s, k + 1, j, false);

        if(s[k] == '|')
        {
            if(isTrue)
                ans += (l_T * r_T) + (l_T * r_F) + (l_F * r_T);
            else 
                ans += (l_F * r_F);
        }

        else if(s[k] == '&')
        {
            if(isTrue)
                ans += (l_T * r_T);
            else 
                ans += (l_F * r_F) + (l_T * r_F) + (l_F * r_T);
        }

        else if(s[k] == '^')
        {
            if(isTrue)
                ans += (l_T * r_F) + (l_F * r_T);
            else 
                ans += (l_T * r_T) + (l_F * r_F);
        }
    }

    return ans;
}

int main()
{
    string s;
    cin >> s;
    cout << solve(s, 0, s.length() - 1, true) << "\n";

    return 0;
}