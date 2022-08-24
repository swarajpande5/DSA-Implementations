// Dice combinations: https://cses.fi/problemset/task/1633

/*
    State: 
        dp[i] = number of ways to get sum == i 
    
    Transition: 
        dp[i] = dp[i - 1] + dp[i - 2] + ... + dp[i - 6]

    Final Subproblem: 
        dp[n]
*/

int dp[n + 1];

int diceCombinations(int n)
{
    if(n < 0)
        return 0;

    if(n == 0)
        return 1; 
    
    if(dp[n] != -1)
        return dp[n]; 
    
    dp[n] = 0;
    for(int i = 1; i <= 6; i++)
        dp[n] = (dp[n] + diceCombinations(n - i)) % mod;

    return dp[n];
}


// Bottom Up Implementation
int diceCombinations(int n)
{
	int dp[n + 1];

	dp[0] = 1;

	for (int i = 1; i < n + 1; i++)
	{
		int sum = 0;
		int j = 1;
		while (i - j >= 0 && j <= 6)
		{
			sum = (sum + dp[i - j]) % mod;
			j++;
		}

		dp[i] = sum % mod;
	}

	return dp[n];
}