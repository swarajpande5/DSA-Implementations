// Array description: https://cses.fi/problemset/task/1746

// dp[i][v] = number of ways to fill the array up to index i, if arr[i] = v
ll dp[100001][101];

void solve()
{
    // Logic
    int n, m;
    cin >> n >> m;

    int arr[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // We treat i = 0 separately. Either arr[0] = 0, so we can replace it by anything i.e. dp[0][v] = 1 for all v.
    // Otherwise x[0] = v, so dp[0][v] = 1 is the only allowed value.
    if (arr[0] == 0)
        fill(dp[0], dp[0] + 101, 1LL);
    else
        dp[0][arr[0]] = 1;

    // Now to the other indices i > 0. 
    
    // If arr[i] = 0, we can replace it by any value. However, if we replace it by v, the previous
    // value must be either v - 1, v or v + 1. Thus the number of ways to fill the array up to i, 
    // is the sum of the previous value begin v - 1, v, and v + 1.

    // If arr[i] = v from the input, only dp[i][v] is allowed. (i.e. dp[i][j] = 0 if j != v). 
    // Still dp[i][v] = dp[i - 1][v - 1] + dp[i - 1][v] + dp[i - 1][v + 1].

    for (int i = 1; i < n; i++)
    {
        if (arr[i] == 0)
        {
            for (int j = 1; j <= m; j++)
            {
                dp[i][j] += dp[i - 1][j];

                if (j - 1 > 0)
                    dp[i][j] += dp[i - 1][j - 1];
                if (j + 1 <= m)
                    dp[i][j] += dp[i - 1][j + 1];

                dp[i][j] %= mod;
            }
        }
        else
        {
            dp[i][arr[i]] += dp[i - 1][arr[i]];

            if (arr[i] - 1 > 0)
                dp[i][arr[i]] += dp[i - 1][arr[i] - 1];
            if (arr[i] + 1 <= m)
                dp[i][arr[i]] += dp[i - 1][arr[i] + 1];

            dp[i][arr[i]] %= mod;
        }
    }

    // Final answer is the sum of every value in the last row.

    ll ans = 0;
    for (int i = 1; i <= m; i++)
    {
        ans += dp[n - 1][i];
        ans %= mod;
    }

    cout << ans;
}