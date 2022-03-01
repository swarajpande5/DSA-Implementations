// Number of islands: https://leetcode.com/problems/number-of-islands/
class Solution 
{
public:
    
    void dfs(vector<vector<char>>& grid, int i, int j)
    {
        // Checking boundary condition
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())
            return;
    
        // Returning if current position is already visited or is water
        if(grid[i][j] == '2' || grid[i][j] == '0')
            return;
    
        // Marking the grid as visited
        grid[i][j] = '2';
        
        // Calling dfs in all 4 directions
        dfs(grid, i + 1, j);
        dfs(grid, i, j - 1);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
    }
    
    int numIslands(vector<vector<char>>& grid) 
    {
        int count = 0;
        
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                // If cell not visited and there is land, we call dfs
                if(grid[i][j] == '1')
                {
                    dfs(grid, i, j);
                    count++;
                }
            }
        }
        
        return count;
    }
};