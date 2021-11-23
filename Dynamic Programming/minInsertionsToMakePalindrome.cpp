// Minimum number of insertions in a string to make it a palindrome (LCS Variation): https://practice.geeksforgeeks.org/problems/form-a-palindrome1455/1
#include <bits/stdc++.h>
using namespace std;

int LCS(string X, string Y, int m, int n)
{
    int t[m + 1][n + 1];

    for(int i = 0; i < m + 1; i++)
    {
        for(int j = 0; j < n + 1; j++)
        {
            if(i == 0 || j == 0)
                t[i][j] = 0;
            
            else if(X[i - 1] == Y[j - 1])
                t[i][j] = 1 + t[i - 1][j - 1];
            
            else 
                t[i][j] = max(t[i][j - 1], t[i - 1][j]);
        }
    }

    return t[m][n];
}

int minInsertions(string s)
{
    // Minimum Insertions = Minimum deletions = length(s) - LPS 
    // Minimum Insertions = Minimum deletions = length(s) - LCS(s, reverse(s))

    string Y(s);
    reverse(Y.begin(), Y.end());

    return s.length() - LCS(s, Y, s.length(), Y.length());
}

int main()
{
    string s;
    cin >> s;

    cout << minInsertions(s) << "\n";

    return 0;
}