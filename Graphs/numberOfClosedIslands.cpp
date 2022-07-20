// Number of closed islands: https://leetcode.com/problems/number-of-closed-islands/

class Solution 
{
public:
    
    bool outOfBounds(int m, int n, int i, int j)
    {
        return i < 0 || j < 0 || i >= m || j >= n;
    }
    
    int dfs(vector<vector<int>> &grid, int i, int j)
    {
        if(outOfBounds(grid.size(), grid[0].size(), i, j))
            return 0; 
        
        if(grid[i][j])
            return 1;
        
        // Marking the current cell as visited
        grid[i][j] = 1;
        
        int l = dfs(grid, i - 1, j); 
        int r = dfs(grid, i + 1, j); 
        int d = dfs(grid, i, j - 1); 
        int u = dfs(grid, i, j + 1); 
        
        return l && r && d && u;
    }
    
    int closedIsland(vector<vector<int>>& grid) 
    {
        int count = 0; 
        for(int i = 0; i < grid.size(); i++)
            for(int j = 0; j < grid[0].size(); j++)
                if(!grid[i][j])    
                    count += dfs(grid, i, j);
        
        return count;
    }
};