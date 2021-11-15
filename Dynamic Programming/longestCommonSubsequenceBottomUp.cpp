// Longest Common Subsequence (using Bottom - Up DP) : https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/
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

int main()
{
    string X, Y;
    cin >> X >> Y;

    cout << LCS(X, Y, X.length(), Y.length()) << "\n";

    return 0;
}