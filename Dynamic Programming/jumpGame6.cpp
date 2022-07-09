// Jump Game 6: https://leetcode.com/problems/jump-game-vi/

// Recursive Solution (T.C. = O(k^n))
class RecursiveSolution
{
    int maxResult(vector<int> &nums, int k, int i = 0)
    {
        if (i >= nums.size() - 1)
            return nums.back();

        int score = INT_MIN;
        for (int j = 1; j <= k; j++)
            score = max(score, nums[i] + maxResult(nums, k, i + j));

        return score;
    }
};

// Top Down Solution (T.C. = O(k*n))
class TopDownSolution
{
    int solve(vector<int> &nums, vector<int> &dp, int k, int i)
    {
        if (dp[i] != INT_MIN)
            return dp[i];

        for (int j = 1; j <= k; j++)
            if (i + j < nums.size())
                dp[i] = max(dp[i], nums[i] + solve(nums, dp, k, i + j));

        return dp;
    }

    int maxResult(vector<int> &nums, int k)
    {
        vector<int> dp(nums.size(), INT_MIN);
        dp[nums.size() - 1] = nums[nums.size() - 1];
        return solve(nums, dp, k, 0);
    }
};

// Bottom Up Solution (T.C. = O(k*n))
class BottomUpSolution
{
    int maxResult(vector<int> &nums, int k)
    {
        vector<int> dp(nums.size(), INT_MIN);
        dp[0] = nums[0];

        for (int i = 1; i < nums.size(); i++)
            for (int j = 1; j <= k && i - j >= 0; j++)
                dp[i] = max(dp[i], dp[i - j] + nums[i]);

        return dp.back();
    }
};

// Space Optimization (T.C. = O(n))
class OptimalSolution
{
    int maxResult(vector<int> &nums, int k)
    {
        vector<int> dp(nums.size());
        dp[0] = nums[0];

        deque<int> q{0};

        for (int i = 1; i < nums.size(); i++)
        {
            // Cannot reach the current index stored in q
            if (q.front() < i - k)
                q.pop_front();

            // Updting max score for current index
            dp[i] = nums[i] + dp[q.front()];

            // Pop indices which won't be ever chosen in the future
            while (!q.empty() && dp[q.back()] <= dp[i])
                q.pop_back();

            // Insert current index
            q.push_back(i);
        }

        return dp.back();
    }
};