// Best time to buy and sell stock with cooldown: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

class Solution 
{
public:
    
    int solve(vector<int> &prices, int day, bool buy, vector<vector<int>> &dp)
    {
        if(day >= prices.size())
            return 0;
        
        if(dp[day][buy] != -1)
            return dp[day][buy]; 
        
        // No transaction this day
        int ans1 = solve(prices, day + 1, buy, dp);
        
        // Transaction this day 
        int ans2 = 0;
        if(buy)
            ans2 = -prices[day] + solve(prices, day + 1, false, dp); 
        else 
            ans2 = prices[day] + solve(prices, day + 2, true, dp); 
        
        return dp[day][buy] = max(ans1, ans2);
    }
    
    int maxProfit(vector<int>& prices) 
    {
        vector<vector<int>> dp(prices.size() + 1, vector<int>(2, -1)); 
        return solve(prices, 0, true, dp);
    }
};