// Book Shop: https://cses.fi/problemset/task/1158

// General 0/1 Knapsack approach (using 2D DP)
void solve()
{
    int n, x;
    cin >> n >> x;

    vector<int> page(n), price(n);

    for (int &i : price)
        cin >> i;

    for (int &i : page)
        cin >> i;

    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= x; j++)
        {
            dp[i][j] = dp[i - 1][j]; // not take the current

            // If possible to take the current
            if (j >= price[i - 1])
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - price[i - 1]] + page[i - 1]);
            }
        }
    }

    cout << dp[n][x] << endl;
}

// 1D DP Approach
void solve()
{
    // Logic
    int n, target;

    cin >> n >> target;

    vector<int> price(n), pages(n);
    for (int &x : price)
        cin >> x;
    for (int &x : pages)
        cin >> x;

    // dp[i] = maximum pages in sum value of target
    vector<int> dp(target + 1, 0);

    for (int i = 0; i < n; i++)
        for (int j = target; j >= price[i]; j--)
            dp[j] = max(dp[j], (dp[j - price[i]] + pages[i]));

    cout << dp[target] << endl;
}