// Coin Combinations 2: https://cses.fi/problemset/task/1636

void solve()
{
    // Logic
    int n, target;

    cin >> n >> target;
    vector<int> c(n);
    for (int &x : c)
        cin >> x;

    // dp[i][x] = number of ways to pick coins with sum x, using the first i coins.
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= target; j++)
        {
            // Not picking the current coin
            dp[i][j] = dp[i - 1][j];

            // Picking the current coin
            if (j - c[i - 1] >= 0)
                dp[i][j] = (dp[i][j] + dp[i][j - c[i - 1]]) % mod;
        }
    }

    cout << dp[n][target] << endl;
}