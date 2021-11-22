// Printing Shortest Common Supersequence (LCS Variation)
#include <bits/stdc++.h>
using namespace std;

string SCS(string X, string Y, int n, int m)
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

        // else we move to the larger side and also append the characters in the string
        else 
        {
            if(t[i][j - 1] > t[i - 1][j])
            {
                res += Y[j - 1];
                j--;
            }
            else
            {
                res += X[i - 1];
                i--;
            } 
        }
    }

    // The string may contains characters hence we append the string that is left
    while(i > 0)
    {
        res += X[i - 1];
        i--;
    }

    while(j > 0)
    {
        res += Y[j - 1];
        j--;
    }

    // finally reversing the string to get the lcs
    reverse(res.begin(), res.end());

    return res;
}

int main()
{
    string X, Y;
    cin >> X >> Y;

    cout << SCS(X, Y, X.length(), Y.length()) << "\n";

    return 0;
}