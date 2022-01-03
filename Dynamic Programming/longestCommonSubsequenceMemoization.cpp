// Longest Common Subsequence (by Memoization) : https://www.geeksforgeeks.org/longest-common-subsequence-dp-using-memoization/
#include <bits/stdc++.h>
using namespace std;

int t[1001][1001];      // DP matrix

int LCS(string X, string Y, int n, int m)
{
    // Base case
    if(n == 0 || m == 0)
        t[n][m] = 0;

    // If already computed then use that value
    if(t[n][m] != -1)
        return t[n][m];

    // Choice diagram
    // When last characters in both the strings are same
    if(X[n - 1] == Y[m - 1])
        t[n][m] = 1 + LCS(X, Y, n - 1, m - 1);

    // When they are not same, then take one string full and another by leaving the last character and vice versa.
    else 
        t[n][m] =  max(LCS(X, Y, n - 1, m), LCS(X, Y, n, m - 1));
    
    // Finally return the answer
    return t[n][m];
}

int main()
{
    string X, Y;
    cin >> X >> Y;
    memset(t, -1, sizeof(t));

    cout << LCS(X, Y, X.length(), Y.length()) << "\n";

    return 0;
}