// Coin Change - 1 (Maximum number of ways) (Unbounded Knapsack variation) : https://practice.geeksforgeeks.org/problems/coin-change2448/1
#include <bits/stdc++.h>
using namespace std;

int maxWays(int coins[], int n, int sum)
{
    int t[n + 1][sum + 1];

    // Initialization
    for (int i = 0; i < sum + 1; i++)
        t[0][i] = 0;
    for (int i = 0; i < n + 1; i++)
        t[i][0] = 1;

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (coins[i - 1] <= j)
                t[i][j] = t[i - 1][j] + t[i][j - coins[i - 1]];
            else
                t[i][j] = t[i - 1][j];
        }
    }

    return t[n][sum];
}

int main()
{
    int n;
    cin >> n;
    int coins[n];
    for (int i = 0; i < n; i++)
        cin >> coins[i];
    int sum;
    cin >> sum;

    cout << maxWays(coins, n, sum) << "\n";

    return 0;
}

// CSES: https://cses.fi/problemset/task/1635
int mod = 1e9 + 7;
void solve()
{
    // Logic
    int n, target;

    cin >> n >> target;

    vector<int> c(n);
    for (int &x : c)
        cin >> x;

    // dp[i] = number of way so to make value i
    vector<int> dp(target + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= target; i++)
        for (int j = 0; j < n; j++)
            if (i - c[j] >= 0)
                dp[i] = (dp[i] + dp[i - c[j]]) % mod;       // Transition

    cout << dp[target] << endl;
}