// Wildcard matching:   https://leetcode.com/problems/wildcard-matching/
//                      https://leetcode.com/problems/wildcard-matching/discuss/752350/Recursion-Brute-force-to-top-down-DP-and-Bottom-up

class Solution
{
public:
    bool isMatch(string s, string p)
    {

        int m = s.size();
        int n = p.size();

        if (p == "*")
            return true;

        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

        dp[0][0] = 1;

        for (int i = 1; i < n + 1; i++)
        {
            if (p[i - 1] == '*')
                dp[0][i] = 1;
            else
                break;
        }

        for (int i = 1; i < m + 1; i++)
        {
            for (int j = 1; j < n + 1; j++)
            {
                if (s[i - 1] == p[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];

                else if (p[j - 1] == '?')
                    dp[i][j] = dp[i - 1][j - 1];

                else if (p[j - 1] == '*')
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1] || dp[i - 1][j - 1];
            }
        }

        return dp[m][n];
    }
};