// Shortest path in a grid with obstacle elimination: https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/
// https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/discuss/1364224/C%2B%2B-or-EXPLAINED-or-BFS-or-Simplest-Solution

class Solution 
{
public:
    int shortestPath(vector<vector<int>>& grid, int k) 
    {
        int m = grid.size(); 
        int n = grid[0].size();
        
        vector<vector<int>> visited(m, vector<int>(n, -1));
        
        queue<vector<int>> q; 
        
        // {x, y, currentRemovalsLeft, currentPathLength}
        q.push({0, 0, k, 0});
        
        int dx[4] = {0, 1, 0, -1}; 
        int dy[4] = {1, 0, -1, 0}; 
        
        while(!q.empty())
        {
            auto it = q.front(); 
            q.pop(); 
            
            int x = it[0]; 
            int y = it[1]; 
            int kLeft = it[2]; 
            int pathLen = it[3]; 
            
            // If we reached the final destination, we return the current path length 
            if(x == m - 1 && y == n - 1)
                return pathLen;
            
            // If the current cell is obstacle, we decrement kLeft 
            if(grid[x][y] == 1)
                kLeft--; 
            
            for(int i = 0; i < 4; i++)
            {
                int newX = x + dx[i]; 
                int newY = y + dy[i]; 
                
                // Bound check and visited[x][y] is less than kLeft, then we consider it.
                // As if this cell is already visited with a k value less than this one,
                // we would want to save k for future use. 
                if(newX >= 0 && newX < m && newY >= 0 && newY < n && visited[newX][newY] < kLeft)
                {
                    // Marking the node as visited, with the current k value left.
                    visited[newX][newY] = kLeft; 
                    
                    q.push({newX, newY, kLeft, pathLen + 1});
                }
            }
        }
        
        // If no pathLen returned, hence we return -1.
        return -1;
    }
};