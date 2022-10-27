// Count sub islands: https://leetcode.com/problems/count-sub-islands/

class Solution {
public:
    
    const int dx[4] = {1, 0, -1, 0};
    const int dy[4] = {0, 1, 0, -1};
    
    void dfs(vector<vector<int>> &grid1, vector<vector<int>> &grid2, int x, int y, int &res) {
        int m = grid1.size(); 
        int n = grid1[0].size(); 
        
        if(x < 0 || y < 0 || x >= m || y >= n)
            return;
        
        // If the corresponding cell in grid1 is zero, we make res equal to false
        if(grid1[x][y] == 0 && grid2[x][y] == 1)
            res = false;
        
        if(grid2[x][y] == 0)
            return; 
        
        grid2[x][y] = 0;
        
        for(int i = 0; i < 4; i++)
            dfs(grid1, grid2, x + dx[i], y + dy[i], res);
        
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size();
        int n = grid1[0].size();
        
        int ans = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid2[i][j] == 1) {
                    int res = true; 
                    dfs(grid1, grid2, i, j, res); 
                    ans += res;
                }
            }
        }
        
        return ans;
    }
};