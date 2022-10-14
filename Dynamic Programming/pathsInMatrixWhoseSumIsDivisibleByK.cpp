// Paths in matrix whose sum is divisble by k: https://leetcode.com/problems/paths-in-matrix-whose-sum-is-divisible-by-k/

class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        
        const int mod = 1e9 + 7;
        
        int n = grid.size(); 
        int m = grid[0].size(); 
        
        
        long long dp[n][m][k]; 
        memset(dp, 0LL, sizeof dp); 
        
        dp[0][0][grid[0][0] % k] = 1;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                grid[i][j] %= k;
            }
        }
        
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < k; j++) {
                dp[i][0][j] = dp[i - 1][0][(j - grid[i][0] + k) % k];
            }
        }
        
        for(int i = 1; i < m; i++) {
            for(int j = 0; j < k; j++) {
                dp[0][i][j] = dp[0][i - 1][(j - grid[0][i] + k) % k];
            }
        }
        
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                for(int l = 0; l < k; l++) {
                    dp[i][j][l] = (
                        dp[i - 1][j][(l - grid[i][j] + k) % k] + 
                        dp[i][j - 1][(l - grid[i][j] + k) % k]
                    ) % mod;
                }
            }
        }
        
        return dp[n - 1][m - 1][0];
    }
};