// K Inverse pairs array: https://leetcode.com/problems/k-inverse-pairs-array/
// https://leetcode.com/problems/k-inverse-pairs-array/discuss/846076/C%2B%2B-4-solutions-with-picture

// Top Down Solution T.C. = O(n*k*k)
class RecursiveSolution 
{
public:
    
    int mod = 1e9 + 7;
    int dp[1001][1001] = {};
    
    int kInversePairs(int n, int k) 
    {
        if(k <= 0)
            return k == 0;
        if(dp[n][k] == 0)
        {    
            dp[n][k] = 1;
            for(int i = 0; i < n; i++)
                dp[n][k] = (dp[n][k] + kInversePairs(n - 1, k - i)) % mod; 
        }
        
        return dp[n][k] - 1;
    }
};

// Bottom Up Solution T.C. = O(n*k*k)
class BottomUpSolution
{
public:
    
    int mod = 1e9 + 7;
    
    int kInversePairs(int n, int k)
    {
        int dp[1001][1001] = {1}; 
        for(int nn = 1; nn <= n; nn++)
            for(int kk = 0; kk <= k; kk++)
                for(int i = 0; i <= min(kk, nn - 1); i++)
                    dp[nn][kk] = (dp[nn][kk] + dp[nn - 1][kk - i]) % mod;
    
        return dp[n][k];
    }
};

// Optimal Solution T.C. = O(n * k)
int dp[1001][1001] = { 1 };
class Solution 
{
public:
    int kInversePairs(int n, int k) 
    {
        if (dp[n][k])
            return dp[n][k];
        
        for (int nn = 1; nn <= n; nn++)
            for (int kk = 0; kk <= k; kk++) 
            {
                dp[nn][kk] = (dp[nn - 1][kk] + (kk > 0 ? dp[nn][kk - 1] : 0)) % 1000000007;
                
                if (kk >= nn)
                    dp[nn][kk] = (1000000007 + dp[nn][kk] - dp[nn - 1][kk - nn]) % 1000000007;
            }
        
        return dp[n][k];
    }
};