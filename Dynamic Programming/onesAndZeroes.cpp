// Ones and zeroes: https://leetcode.com/problems/ones-and-zeroes/

class Solution
{
public:
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        // 3D vector store [index][zeros][ones] 
        vector<vector<vector<int>>> dp(strs.size() + 1, vector<vector<int>> (m + 1, vector<int> (n + 1, 0)));

        for(int i = 1; i < strs.size() + 1; i++)
        {
            // Counting zeroes and ones
            int zeroes = count(strs[i - 1].begin(), strs[i - 1].end(), '0');
            int ones = strs[i - 1].size() - zeroes; 

            for(int j = 0; j < m + 1; j++)
            {
                for(int k  = 0; k < n + 1; k++)
                {
                    // If the current string obeys the rule of atmost m 0's and n 1's 
                    // then we have a choice to either pick or not pick. 
                    // Otherwise, we have only one choice i.e. to not pick.
                    if(zeroes <= j && ones <= k)
                        dp[i][j][k] = max(1 + dp[i - 1][j - zeroes][k - ones], dp[i - 1][j][k]); 
                    else 
                        dp[i][j][k] = dp[i - 1][j][k]; 
                }
            }
        }

        return dp[strs.size()][m][n];
    }
};

class SpaceOptimalSolution 
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