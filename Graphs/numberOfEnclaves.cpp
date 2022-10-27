// Number of enclaves: https://leetcode.com/problems/number-of-enclaves/

class Solution {
public:

    const int dx[4] = {1, 0, -1, 0}; 
    const int dy[4] = {0, 1, 0, -1};

    void dfs(vector<vector<int>> &grid, int x, int y) {
        if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] != 1)
            return; 

        grid[x][y] = 0;

        for(int i = 0; i < 4; i++)
            dfs(grid, x + dx[i], y + dy[i]);
    }

    int numEnclaves(vector<vector<int>>& grid) {
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(i * j == 0 || i == grid.size() - 1 || j == grid[0].size() -1)
                    dfs(grid, i, j);
            }
        }

        int count = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j]) 
                    count++;
            }
        }

        return count;
    }
};