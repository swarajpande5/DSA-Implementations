// Frog jump: https://leetcode.com/problems/frog-jump/

class Solution 
{
public:
    bool canCross(vector<int>& stones) 
    {
        
        int m = stones.size();
        
        // dp[i][k] = there is a jump of size k which successfully reaches stones[i].
        // The largest step to reach ith position is k = i. 
        vector<vector<int>> dp(m, vector<int>(m + 1));
        
        if(stones[1] == 1)
            dp[1][1] = true;
        
        for(int i = 1; i < m; i++)
        {
            for(int j = i + 1; j < m; j++)
            {
                int diff = stones[j] - stones[i];
                
                if(diff <= j)
                    dp[j][diff] = dp[i][diff - 1] || dp[i][diff] || dp[i][diff + 1];
            }
        }
        
        return accumulate(dp[m - 1].begin(), dp[m - 1].end(), 0) > 0;
    }
};