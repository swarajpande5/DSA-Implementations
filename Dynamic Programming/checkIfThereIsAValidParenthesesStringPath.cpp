// Check if there is a valid parentheses string path: https://leetcode.com/problems/check-if-there-is-a-valid-parentheses-string-path/
// https://leetcode.com/problems/check-if-there-is-a-valid-parentheses-string-path/discuss/2017937/Simple-DFS-%2B-DP

class Solution 
{
public:
    
    int m, n;
    int dp[100][100][205];
    
    bool dfs(vector<vector<char>> &grid, int i, int j, int k)
    {
        if(i >= m || j >= n)
            return 0;
        
        if(grid[i][j] == '(')
            k++;
        else 
            k--;
        
        // Number of closing braces is greater than number of opening braces
        if(k < 0)
            return 0;
        
        // If we at the last cell, we return whether the value of k is zero
        if(i == m - 1 && j == n - 1)
            return k == 0;
        
        if(dp[i][j][k] != -1)
            return dp[i][j][k];
        
        return dp[i][j][k] = (dfs(grid, i + 1, j, k) | dfs(grid, i, j + 1, k));
    }
    
    bool hasValidPath(vector<vector<char>>& grid) 
    {
        m = grid.size();
        n = grid[0].size();
        
        memset(dp, -1, sizeof(dp));
        
        return dfs(grid, 0, 0, 0);
    }
};