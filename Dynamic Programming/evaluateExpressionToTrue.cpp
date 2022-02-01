// Evaluate expression to true (Top down DP): https://practice.geeksforgeeks.org/problems/boolean-parenthesization5610/1/

#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> ump;

int solve(string x, int i, int j, bool isTrue)
{
    string key = to_string(i) + " " + to_string(j) + " " + (isTrue ? "T" : "F");

    if (ump.find(key) != ump.end())
        return ump[key];

    if (i >= j)
    {
        if (isTrue)
            ump[key] = x[i] == 'T';
        else
            ump[key] = x[i] == 'F';

        return ump[key];
    }

    int ans = 0;

    for (int k = i + 1; k < j; k++)
    {
        int lT = solve(x, i, k - 1, true);
        int lF = solve(x, i, k - 1, false);
        int rT = solve(x, k + 1, j, true);
        int rF = solve(x, k + 1, j, false);

        if (x[k] == '|')
        {
            if (isTrue)
                ans += lT * rT + lT * rF + lF * rT;
            else
                ans += lF * rF;
        }

        else if (x[k] == '&')
        {
            if (isTrue)
                ans += lT * rT;
            else
                ans += lT * rF + lF * rT + lF * rF;
        }

        else if (x[k] == '^')
        {
            if (isTrue)
                ans += lT * rF + lF * rT;
            else
                ans += lT * rT + lF * rF;
        }
    }

    return ump[key] = ans;
}

// // Using 3D Array
// const int D = 1001;
// int dp[2][D][D]; // i,j and istrue and false is changing

// int Solve(string X, int i, int j, bool isTrue)
// {
//     if (i >= j)
//     {
//         if (isTrue)
//             dp[1][i][j] = X[i] == 'T';
//         else
//             dp[0][i][j] = X[i] == 'F';
//         return dp[isTrue][i][j];
//     }

//     if (dp[isTrue][i][j] != -1)
//         return dp[isTrue][i][j];

//     int ans = 0;
//     for (int k = i + 1; k < j; k += 2)
//     {
//         int l_T = Solve(X, i, k - 1, true);
//         int l_F = Solve(X, i, k - 1, false);
//         int r_T = Solve(X, k + 1, j, true);
//         int r_F = Solve(X, k + 1, j, false);

//         if (X[k] == '|')
//         {
//             if (isTrue == true)
//                 ans += l_T * r_T + l_T * r_F + l_F * r_T;
//             else
//                 ans += l_F * r_F;
//         }
//         else if (X[k] == '&')
//         {
//             if (isTrue == true)
//                 ans += l_T * r_T;
//             else
//                 ans += l_T * r_F + l_F * r_T + l_F * r_F;
//         }
//         else if (X[k] == '^')
//         {
//             if (isTrue == true)
//                 ans += l_T * r_F + l_F * r_T;
//             else
//                 ans += l_T * r_T + l_F * r_F;
//         }
//     }

//     dp[isTrue][i][j] = ans;

//     return ans;
// }

// int main()
// {
//     string X;
//     cin >> X;

//     memset(dp[0], -1, sizeof(dp[0]));
//     memset(dp[1], -1, sizeof(dp[1]));

//     cout << Solve(X, 0, X.length() - 1, true) << endl;
//     return 0;
// }