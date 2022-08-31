// Pacific Atlantic Water Flow: https://leetcode.com/problems/pacific-atlantic-water-flow/

class Solution 
{
public:
    
    int m, n;
    
    // Denotes cells reachable starting from atlantic and pacific edged cells respectively
    vector<vector<bool>> atlantic, pacific;
    
    vector<vector<int>> ans; 
    
    void dfs(vector<vector<int>> &mat, vector<vector<bool>> &visited, int i, int j)
    {
        if(visited[i][j])
            return;
        
        // Marking the current cell as visited 
        visited[i][j] = true; 
        
        // If cell reachable from both the oceans, insert into the final answer
        if(atlantic[i][j] && pacific[i][j])
            ans.push_back({i, j});
        
        // DFS from current cell only when height of next cell is greater
        if(i + 1 < m && mat[i + 1][j] >= mat[i][j]) dfs(mat, visited, i + 1, j);
        if(i - 1 >= 0 && mat[i - 1][j] >= mat[i][j]) dfs(mat, visited, i - 1, j);
        if(j + 1 < n && mat[i][j + 1] >= mat[i][j]) dfs(mat, visited, i, j + 1);
        if(j - 1 >= 0 && mat[i][j - 1] >= mat[i][j]) dfs(mat, visited, i, j - 1);
        
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) 
    {
        if(heights.size() == 0)
            return ans; 
        
        m = heights.size();
        n = heights[0].size(); 
        
        atlantic = pacific = vector<vector<bool>> (m, vector<bool>(n, false)); 
        
        // Performing DFS on all edge cells (ocean-connected cells)
        for(int i = 0; i < m; i++)
        {
            dfs(heights, pacific, i, 0); 
            dfs(heights, atlantic, i, n - 1);
        }
        for(int i = 0; i < n; i++)
        {
            dfs(heights, pacific, 0, i); 
            dfs(heights, atlantic, m - 1, i);
        }
        
        return ans;
    }
};