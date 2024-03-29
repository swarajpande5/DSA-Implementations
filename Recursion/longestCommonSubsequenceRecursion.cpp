// Longest Common Subsequence Recursion : https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/
#include <bits/stdc++.h>
using namespace std;

int LCS(string X, string Y, int n, int m)
{
    // Base case
    if(n == 0 || m == 0)
        return 0;

    // Choice diagram
    // When last characters in both the strings are same
    if(X[n - 1] == Y[m - 1])
        return 1 + LCS(X, Y, n - 1, m - 1);

    // When they are not same, then take one string full and another by leaving the last character and vice versa.
    else 
        return max(LCS(X, Y, n - 1, m), LCS(X, Y, n, m - 1));
}

int main()
{
    string X, Y;
    cin >> X >> Y;
    
    cout << LCS(X, Y, X.length(), Y.length()) << "\n";

    return 0;
}