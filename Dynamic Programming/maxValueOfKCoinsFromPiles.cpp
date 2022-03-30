// Maximum value of k coins from piles: https://leetcode.com/problems/maximum-value-of-k-coins-from-piles/

/*
    Let dp[i][j] be the max value of j coins using piles i ~ (n-1). 
    Then the answer is dp[0][k]
    
    For dp[i][j], we can try using t elements from A[i] (0 <= t <= min(j, A[i].size())), 
    getting A[i][0] + ... + A[i][t-1] value plus dp[i+1][j-t] value.
    Here, dp[i+1][j-t] is the max value of j-t coins using piles i+1 ~ (n-1).
    
    We try different values of t and assign the max value to dp[i][j].
    
    dp[i][j] = max( dp[i+1][j-t] + sum(i, t) | 0 <= t <= min(j, A[i].size()) )
    where, 
        sum(i, t) = A[i][0] + ... + A[i][t-1]
*/
class Solution 
{
public:
    int maxValueOfCoins(vector<vector<int>>& A, int k) 
    {
        int n = A.size();
        int m[1001][2001] = {};
        memset(m, -1, sizeof(m));
            
        function<int(int, int)> dp = [&](int i, int j)
        {
            if(m[i][j] != -1)
                return m[i][j];
            
            if(i == n)
                return 0;
        
            int ans = dp(i + 1, j);
            int sum = 0;
            
            for(int t = 1; t <= j && t <= A[i].size(); t++)
            {
                sum += A[i][t - 1];
                ans = max(ans, dp(i + 1, j - t) + sum);
            }
            
            return m[i][j] = ans;
        };
        
        return dp(0, k);
    }
};