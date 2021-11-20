// Longest Palindromic Subsequence (LCS Variation) : https://www.geeksforgeeks.org/longest-palindromic-subsequence-dp-12/
#include <bits/stdc++.h>
using namespace std;

string LCS(string X, string Y, int n, int m)
{
    int t[n + 1][m + 1];        // DP matrix

    for(int i = 0; i < n + 1; i++)
    {
        for(int j = 0; j < m + 1; j++)
        {
            if(i == 0 || j == 0)
                t[i][j] = 0;
            
            else if(X[i - 1] == Y[j - 1]) 
                t[i][j] = 1 + t[i - 1][j - 1];
            
            else 
                t[i][j] = max(t[i][j - 1], t[i - 1][j]);
        }
    }

    int i = n, j = m;
    string res = "";

    while(i > 0 && j > 0)
    {
        // When character is equal in table, we store in the result string (res)
        // and decrement i and j
        if(X[i - 1] == Y[j - 1])
        {
            res += X[i - 1];
            i--;
            j--;
        }

        // else we move to the larger side 
        else 
        {
            if(t[i][j - 1] > t[i - 1][j])
                j--;
            else 
                i--;
        }
    }

    // Here as the LCS itself is a palindrome, we do not reverse the LCS and simply return it
    return res;
} 

string LPS(string s)
{
    // Longest Palindromic Subsequence = LCS(string, reverse(string))
    // We can also just return length of LPS, by reducing the problem.
    string Y(s);
    reverse(Y.begin(), Y.end());

    return LCS(s, Y, s.length(), Y.length());
}

int main()
{
    string s;
    cin >> s;
    cout << LPS(s) << "\n";

    return 0;
}