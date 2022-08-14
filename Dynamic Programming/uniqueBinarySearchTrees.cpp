// Unique binary search trees: https://leetcode.com/problems/unique-binary-search-trees/

// Recursive approach (T.C. = O(3 ^ n))
class RecursiveSolution
{
public:
    int numTrees(int n)
    {
        if(n <= 1)
            return 1; 
        
        int ans = 0;
        for(int i = 1; i <= n; i++)
            ans += numTrees(i - 1) * numTrees(n - i);
        
        return ans;
    }
};

// Top Down Memoization (T.C. = O(n ^ 2))
class TopDownSolution
{
public: 
    vector<int> dp(20, 0);

    int numTrees(int n)
    {
        if(n <= 1)
            return 1; 
        if(dp[n])
            return dp[n];
        
        for(int i = 1; i <= n; i++)
            dp[n] += numTrees(i - 1) * numTrees(n - i);

        return dp[n];
    }
};

// Bottom Up Tabulation (T.C. = O(n ^ 2))
class BottomUpSolution
{
public:
    int numTrees(int n)
    {
        vector<int> dp(n + 1); 
        dp[0] = dp[1] = 1; 

        for(int i = 2; i <= n; i++)
            for(int j = 1; j <= i; j++)
                dp[i] += dp[j - 1] * dp[i - j];
        
        return dp[n];
    }
};

// Optimal Solution using Catalan numbers (T.C. = O(n))
class Solution
{
public:
    long long ncr(int n, int r)
    {
        long long ans = 1;
        for(int i = 0; i < r; i++)
        {
            ans *= (n - i);
            ans /= (i + 1);
        }

        return ans;
    }

    int numTrees(int n)
    {
        return ncr(2 * n, n) / (n + 1);
    }
};