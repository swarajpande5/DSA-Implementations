// Combination Sum 4: https://leetcode.com/problems/combination-sum-iv/

// Recursive solution
class RecursiveSolution 
{
public:
    int combinationSum4(vector<int>& nums, int target) 
    {
        if(target == 0)
            return 1;
        
        int ans = 0;
        for(int &num: nums)
            // Pick an element if it is less than target to be achieved, and recurse for remaining amount
            if(num <= target)
                ans += combinationSum4(nums, target - num);           
    
        return ans;
    }
};

// Top Down Solution (Memoization)
class TopDownSolution 
{
public:
    
    int solve(vector<int> &nums, int target, vector<int> &dp)
    {
        if(target == 0)
            return 1;
        
        if(dp[target] != -1)
            return dp[target];
        
        dp[target] = 0;
        for(int num: nums)
            if(num <= target)
                dp[target] += solve(nums, target - num, dp);
        
        return dp[target];
    }
    
    int combinationSum4(vector<int>& nums, int target) 
    {
        vector<int> dp(target + 1, -1);
        return solve(nums, target, dp);
    }
};

// Bottom Up Solution
class Solution 
{
public:

    int combinationSum4(vector<int>& nums, int target) 
    {
        vector<uint> dp(target + 1); 
        dp[0] = 1;
        for (int curTarget = 1; curTarget <= target; curTarget++) 
            for (auto& num : nums)     
                if (num <= curTarget)  
                    dp[curTarget] += dp[curTarget - num];   
        return dp[target];
    }
};