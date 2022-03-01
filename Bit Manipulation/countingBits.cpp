// Counting Bits: https://leetcode.com/problems/counting-bits/

class Solution
{
public:
    vector<int> countBits(int n)
    {
        if (n == 0)
        {
            return vector<int>(1, 0);
        }

        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        for (int i = 2; i < dp.size(); i++)
        {
            dp[i] = (i % 2 == 0 ? dp[i / 2] : dp[i / 2] + 1);
        }

        return dp;
    }
};