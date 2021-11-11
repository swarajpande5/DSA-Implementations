// Coin Change - 2 (Minimum number of coins) (Unbounded Knapsack variation) : https://practice.geeksforgeeks.org/problems/number-of-coins1824/1

#include <bits/stdc++.h>
using namespace std;

#define INF INT_MAX - 1

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