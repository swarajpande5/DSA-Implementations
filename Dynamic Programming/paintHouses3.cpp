// Paint House 3: https://leetcode.com/problems/paint-house-iii/ 

// Memoization solution
class Solution 
{
public:
    
    const int MAX = 1e9;
    
    int solve(vector<int> &houses, vector<vector<int>> &cost, int target, int idx, int count, int prev, vector<vector<vector<int>>> &dp)
    {
        // Base cases
        if(idx == houses.size())
            return (count == target ? 0 : MAX); 
        if(idx > houses.size())
            return MAX; 
        
        if(dp[idx][count][prev] != -1)
            return dp[idx][count][prev];
        
        int minCost = MAX; 
        
        // If house is already painted 
        if(houses[idx])
        {
            // If previous house is of different colour, increase the count by 1 
            if(houses[idx] != prev)
                minCost = solve(houses, cost, target, idx + 1, count + 1, houses[idx], dp); 
            else 
                minCost = solve(houses, cost, target, idx + 1, count, houses[idx], dp);
        }
        // Otherwise, we have to try all the colors
        else 
        {
            for(int j = 0; j < cost[0].size(); j++)
            {
                int tempCost;
                
                // If previous house is of different color, increase the count by 1 
                if((j + 1) != prev)
                    tempCost = cost[idx][j] + solve(houses, cost, target, idx + 1, count + 1, j + 1, dp);
                else 
                    tempCost = cost[idx][j] + solve(houses, cost, target, idx + 1, count, j + 1, dp);
                
                minCost = min(minCost, tempCost);
            }
        }
        
        return dp[idx][count][prev] = minCost;
    }
    
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) 
    {
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>> (m + 1, vector<int>(n + 1, -1)));    
        
        int ans = solve(houses, cost, target, 0, 0, 0, dp);
        
        if(ans == MAX)
            return -1; 
        
        return ans;
    }
};