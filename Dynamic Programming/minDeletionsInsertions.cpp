// Minimum number of deletions and insertions (LCS Variation) : https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions0209/1
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

pair<int, int> minInsertDel(string X, string Y, int m, int n)
{
    pair<int, int> res;

    int lcs = LCS(X, Y, m, n);

    // Using the formula as estabilished earlier
    res.first = m - lcs;
    res.second = n - lcs;

    return res;
}

int main()
{
    string X, Y;
    cin >> X >> Y;

    pair<int, int> res = minInsertDel(X, Y, X.length(), Y.length());
    cout << res.first << " " << res.second << "\n";

    return 0;
}