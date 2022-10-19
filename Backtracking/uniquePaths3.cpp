// Unique paths 3: https://leetcode.com/problems/unique-paths-iii/

class Solution {
public:
    
    int ans = 0; 
    const int dx[4] = {1, 0, -1, 0}; 
    const int dy[4] = {0, 1, 0, -1};
    
    
    bool isValid(vector<vector<int>> &grid, int i, int j) {
        return i >= 0 && j >= 0 && i < grid.size() && j < grid[0].size() && grid[i][j] != -1 && grid[i][j] != 3;
    }
    
    void dfs(vector<vector<int>> &grid, int i, int j, int cellsToVisit) {
        if(!isValid(grid, i, j))
            return; 
        
        // Reached end cell
        if(grid[i][j] == 2) {
            if(cellsToVisit == 0)
                ans++; 
            
            return;
        }
        
        // Mark cell as visited 
        grid[i][j] = 3; 
        
        // Explore all directions 
        for(int k = 0; k < 4; k++) 
            dfs(grid, i + dx[k], j + dy[k], cellsToVisit - 1); 
        
        // Backtrack 
        grid[i][j] = 0;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int startRow, startCol, cellsToVisit = 0; 
        
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1) {
                    startRow = i;
                    startCol = j;
                }
                else if(grid[i][j] != -1)
                    cellsToVisit++;
            }
        }
        
        dfs(grid, startRow, startCol, cellsToVisit); 
        return ans;
    }
};