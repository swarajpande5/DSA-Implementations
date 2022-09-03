// Burst Balloons: https://leetcode.com/problems/burst-balloons/

class Solution 
{
public:
    int maxCoins(vector<int>& nums) 
    {
        int n = nums.size();
        
        int dp[n][n]; 
        memset(dp, 0, sizeof dp); 
        
        for(int gap = 0; gap < n; gap++)
        {
            for(int i = 0, j = gap; j < n; i++, j++)
            {
                int maxPrice = INT_MIN;
                
                for(int k = i; k <= j; k++)
                {   
                    // Cost of left and right of the current selections
                    int left = (k == i ? 0: dp[i][k - 1]); 
                    int right = (k == j? 0: dp[k + 1][j]); 
                    
                    // Cost of current selection
                    int currCoins = (i == 0 ? 1: nums[i - 1]) * nums[k] * (j == n - 1 ? 1: nums[j + 1]); 
                    
                    int temp = left + right + currCoins; 
                    maxPrice = max(temp, maxPrice);
                }
                
                dp[i][j] = maxPrice;
            }
        }
        
        return dp[0][n - 1];
    }
};