// Coin Change - 2 (Minimum number of coins) (Unbounded Knapsack variation) : https://practice.geeksforgeeks.org/problems/number-of-coins1824/1
// Coin Change: https://leetcode.com/problems/coin-change/

#include <bits/stdc++.h>
using namespace std;

#define INF INT_MAX - 1

// Recursive Solution 
class RecursiveSolution
{
public:
    int solve(vector<int> wt, int w, int n)
    {
        if(n == 0 || w == 0)
            return (w == 0) ? 0 : INF;
        
        // If denomination of coin is greater than the total 
        if(wt[n - 1] > w)
            return solve(wt, w, n - 1);
        //  return 0 + solve(wt, w - 0, n - 1)

        else 
            return min(solve(wt, w, n - 1), 1 + solve(wt, w - wt[n - 1], n));
    }

    int coinChange(vector<int> &coins, int amount)
    {
        int minCoins = solve(coins, amount, coins.size());
        return minCoins = (INF ? -1 : minCoins);
    }
};

// Memoization Solution (Top down DP)
class Memoization
{
public:
    vector<int> dp(10001, vector<int>(13, -1));     // Size from constraint

    int solve(vector<int> &wt, int w, int n)
    {
        if(n == 0 || w == 0)
            return (w == 0) ? 0 : INF;
        
        if(dp[w][n] != -1)
            return dp[w][n];

        // If denomination of coin is greater than the total 
        if(wt[n - 1] > w)
            return dp[w][n] = solve(wt, w, n - 1);
        //  return 0 + solve(wt, w - 0, n - 1)

        else 
            return dp[w][n] = min(solve(wt, w, n - 1), 1 + solve(wt, w - wt[n - 1], n));
    }

    int coinChange(vector<int> &coins, int amount)
    {
        int minCoins = solve(coins, amount, coins.size());
        return minCoins = (INF ? -1 : minCoins);
    }
};

// Tabulation Solution (Bottom up DP)
int minCoins(int coins[], int n, int sum)
{
    int t[n + 1][sum + 1];

    // Initialization
    for(int i = 0; i < n + 1; i++)
    {
        for(int j = 0; j < sum + 1; j++)
        {
            if(i == 0)
                t[i][j] = INF;
            if(j == 0)
                t[i][j] = 0;
            if(i == 1)
            {
                if(j % coins[i - 1] == 0)
                    t[i][j] = j / coins[i - 1];
                else 
                    t[i][j] = INF;
            }
        }
    }

    // DP
    for(int i = 1; i < n + 1; i++)
    {
        for(int j = 1; j < sum + 1; j++)
        {
            if(coins[i - 1] <= j)
                t[i][j] = min(t[i - 1][j], 1 + t[i][j - coins[i - 1]]);
            else 
                t[i][j] = t[i - 1][j];
        }
    }

    return t[n][sum] == INF ? -1 : t[n][sum];
}

int main()
{
    int n;
    cin >> n;
    int coins[n];
    for(int i = 0; i < n; i++)
        cin >> coins[i];
    int sum;
    cin >> sum;

    cout << minCoins(coins, n, sum) << "\n";

    return 0;
}