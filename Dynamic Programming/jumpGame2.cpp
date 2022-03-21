// Jump game 2: https://leetcode.com/problems/jump-game-ii/
//              https://leetcode.com/problems/jump-game-ii/discuss/1192401/Easy-Solutions-w-Explanation-or-Optimizations-from-Brute-Force-to-DP-to-Greedy-BFS

/*
// Recursive solution (Top Down DP)
class Solution
{
    int util(int idx, vector<int> &nums, vector<int> &dp)
    {
        if(idx >= nums.size() - 1)
            return 0;
        
        if(dp[idx] != -1)
            return dp[idx];

        int mn = INT_MAX;
        for(int i = 1; i <= nums[idx]; i++)
        {
            int val = util(idx + i, nums, dp);
            if(val != INT_MAX)
                mn = min(val + 1, mn);
        }

        return dp[idx] = mn;
    }
};
*/

/*
// DP O(n^2)
class Solution 
{
public:
    int jump(vector<int>& nums)
    {
        int n = size(nums);
        vector<int> dp(n, 10001);
        dp[n - 1] = 0;  
        for(int i = n - 2; i >= 0; i--) 
            for(int jumpLen = 1; jumpLen <= nums[i]; jumpLen++) 
                dp[i] = min(dp[i], 1 + dp[min(n - 1, i + jumpLen)]); 
        return dp[0];
    }
};
*/

// Greedy BFS O(n)
class Solution
{
public:
    int jump(vector<int>& nums)
    {
        int n = nums.size();
        int maxReachable = 0;
        int lastJumpedPos = 0;
        int jumps = 0;
        int i = 0;

        while(lastJumpedPos < n - 1)
        {
            maxReachable = max(maxReachable, i + nums[i]);
            
            if(i == lastJumpedPos)
            {
                lastJumpedPos = maxReachable;
                jumps++;
            }

            i++;
        }

        return jumps;
    }
};