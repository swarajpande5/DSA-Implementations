// Maximum area of island: https://leetcode.com/problems/max-area-of-island/

class Solution
{
private:
    int n, m;

    int travel(int i, int j, vector<vector<int>> &grid)
    {
        if(i < 0 || j < 0 || i >= n || j >= m ||!grid[i][j])
            return 0;
        
        grid[i][j] = 0;
        return  1 + travel(i - 1, j, grid) + travel(i, j - 1, grid) 
                + travel(i + 1, j, grid) + travel(i, j + 1, grid);
    }

public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int ans = 0;
        n = grid.size(), m = grid[0].size();

        for(int i = 0 ; i < n; i++)
            for(int j = 0; j < m; j++)
                if(grid[i][j])
                    ans = max(ans, travel(i, j, grid));
        
        return ans;
    }
};

// Unit Area of largest regions of 1's: https://practice.geeksforgeeks.org/problems/length-of-largest-region-of-1s-1587115620/1

const int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dy[] = {0, 1, 0, -1, -1, 1, -1, 1};
class Solution
{
    public:
    
    int dfs(int i, int j, vector<vector<int>> &grid)
    {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || !grid[i][j])
            return 0; 
        
        grid[i][j] = 0; 
        
        int count = 1; 
        for(int idx = 0; idx < 8; idx++)
            count += dfs(i + dx[idx], j + dy[idx], grid);
            
        return count;
    }
    
    //Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>>& grid) 
    {
        int ans = INT_MIN; 
        
        for(int i = 0; i < grid.size(); i++)
            for(int j = 0; j < grid[0].size(); j++)
                if(grid[i][j])
                    ans = max(ans, dfs(i, j, grid));
        
        return ans;
    }
};