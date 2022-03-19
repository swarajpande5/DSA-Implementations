// House robber: https://leetcode.com/problems/house-robber/


// Recursive Solution
class RecursiveSolution
{
public:
    int getMaxAmount(vector<int> nums, int n)
    {
        if(n < 0)
            return 0;
        if(n == 0)
            return nums[0];
        if(n == 1)
            return max(nums[0], nums[1]);
        
        return max(nums[n] + getMaxAmount(nums, n - 2), getMaxAmount(nums, n - 1));
    }

    int rob(vector<int> &nums)
    {
        if(nums.size() == 0)
            return 0;

        return getMaxAmount(nums, nums.size() - 1);
    }
};

// Top Down DP Solution
class TopDownDPSolution
{
public:
    int getMaxAmount(vector<int> &nums, int start, vector<int> &dp)
    {
        if(start >= nums.size())
            return 0;
        
        if(dp[start] != -1)
            return dp[start];
        
        return dp[start] = max(
            nums[start] + getMaxAmount(nums, start + 2, dp),
            getMaxAmount(nums, start + 1, dp)
        );
    }

    int rob(vector<int> &nums)
    {
        if(nums.size() == 1)
            return nums[0];
        
        vector<int> dp(nums.size() - 1);
        return getMaxAmount(nums, 0, dp);
    }
};

// Bottom Up DP Solution
class Solution
{
public: 
    int rob(vector<int>& nums)
    {
        int n = nums.size();

        if(n == 1)
            return nums[0];
        
        vector<int> dp(n);

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for(int i = 2; i < n; i++)
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        
        return dp[n - 1];
    }
};