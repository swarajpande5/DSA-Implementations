// Out of boundary paths: https://leetcode.com/problems/out-of-boundary-paths/

// Top Down Solution (Memoization)
class Solution 
{
public:
    
    int mod = 1e9 + 7;
    
    int solve(int i, int j, int currMoves, int &m, int &n, int &maxMoves, vector<vector<vector<int>>> &dp)
    {
        if(i < 0 || j < 0 || i >= m || j >= n)
            return 1; 
    
        if(currMoves == maxMoves)
            return 0; 
    
        if(dp[currMoves][i][j] != -1)
            return dp[currMoves][i][j] % mod;
        
        int temp = 0; 
        temp = (temp + solve(i, j - 1, currMoves + 1, m, n, maxMoves, dp)) % mod;
        temp = (temp + solve(i - 1, j, currMoves + 1, m, n, maxMoves, dp)) % mod;
        temp = (temp + solve(i + 1, j, currMoves + 1, m, n, maxMoves, dp)) % mod;
        temp = (temp + solve(i, j + 1, currMoves + 1, m, n, maxMoves, dp)) % mod;
        
        return dp[currMoves][i][j] = temp % mod;
    }
    
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) 
    {
        vector<vector<vector<int>>> dp(maxMove + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, -1))); 
        dp[maxMove][m][n] = solve(startRow, startColumn, 0, m, n, maxMove, dp);
        
        return dp[maxMove][m][n];
    }
};