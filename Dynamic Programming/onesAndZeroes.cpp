// Ones and zeroes: https://leetcode.com/problems/ones-and-zeroes/

class Solution 
{
public:
    int findMaxForm(vector<string>& strs, int m, int n) 
    {
        // Knapsack variation
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for(auto str: strs)
        {
            int zeroes = count(str.begin(), str.end(), '0');
            int ones = str.size() - zeroes;
            
            for(int i = m; i >= zeroes; i--)
                for(int j = n; j >= ones; j--)
                    dp[i][j] = max(dp[i][j],                        // Either leave the current string 
                                   dp[i - zeroes][j - ones] + 1);   // Or pick the current string and add one to balance
        }
        return dp[m][n];
    }
};