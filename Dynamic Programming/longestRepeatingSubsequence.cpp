// Longest Repeating Subsequence (LCS Variation) : https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1
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
            
            // just adding an condition that character at ith index should not be equal to character at jth index
            else if(X[i - 1] == Y[j - 1] && i != j)        
                t[i][j] = 1 + t[i - 1][j - 1];
            
            else 
                t[i][j] = max(t[i][j - 1], t[i - 1][j]);
        }
    }

    return t[m][n];

    // We can also generate the string using the same logic as printing LCS
}

int main()
{
    string X;
    cin >> X;

    cout << LCS(X, X, X.length(), X.length()) << "\n";

    return 0;
}