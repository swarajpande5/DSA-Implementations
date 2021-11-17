// Longest Common Substring (Longest Common Subsequence variation) : https://practice.geeksforgeeks.org/problems/longest-common-substring1452/1
#include <bits/stdc++.h>
using namespace std;

int LCSubstring(string X, string Y, int n, int m)
{
    int t[n + 1][m + 1];    // DP matrix

    for(int i = 0; i < n + 1; i++)
    {
        for(int j = 0; j < m + 1; j++)
        {
            if(i == 0 || j == 0)        // Base condition
                t[i][j] = 0;
            
            else if(X[i - 1] == Y[j - 1])
                t[i][j] = 1 + t[i - 1][j - 1];
            
            // Variation from LCS, as last characters are not equal we make the count zero 
            // in order to ascertain discontinuity
            else                        
                t[i][j] = 0;
        }
    }

    // Finding the max element in the dp matrix
    int mx = INT_MIN;
    for(int i = 0; i < n + 1; i++)
        for(int j = 0; j < m + 1; j++)
            mx = max(mx, t[i][j]);
    
    return mx;
}

int main()
{
    string X, Y;
    cin >> X >> Y;

    cout << LCSubstring(X, Y, X.length(), Y.length()) << "\n";

    return 0;
}