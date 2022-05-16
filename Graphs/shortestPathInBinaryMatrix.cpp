// Shortest path in binary matrix:  https://leetcode.com/problems/shortest-path-in-binary-matrix/
//                                  https://leetcode.com/problems/shortest-path-in-binary-matrix/discuss/901706/Simple-C%2B%2B-with-explanation-and-why-it's-not-rotten-oranges-problem

/*
    Intuition:
    If starting or ending cell is blocked simply return -1.
    Do BFS traversal on grid in 8 directions, using queue.
    At each iteration, 
    add 1 to next unblocked cell, grid[nrow][ncol] = grid[row][col] + 1
    If at any point row = n - 1 and col = n - 1, the destination is reached
    and return the value of grid[n - 1][n - 1].
*/
class Solution 
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
        vector<vector<int>> directions = 
            {   {-1,-1}, {-1, 0}, {-1, 1}, {0, -1},
                {0,  1}, {1, -1}, {1,  0}, {1,  1}
            };
        
        int n = grid.size();
        
        // if starting or ending cell is blocked
        if(grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;
        
        queue<pair<int, int>> q;
        
        q.push({0, 0});
        grid[0][0] = 1;
        
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            
            // if destination already reached then return current grid cell value
            if(row == n - 1 && col == n - 1)
                return grid[row][col];
            
            // iterating on all 8 directions
            for(auto dir: directions)
            {
                int nrow = row + dir[0];
                int ncol = col + dir[1];
                
                // Bound checking and no obstacle condition
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && grid[nrow][ncol] == 0)
                {
                    q.push({nrow, ncol});
                    grid[nrow][ncol] = grid[row][col] + 1;  // Increase value for that cell
                }
            }
            
            q.pop();
        }
        
        // If destination not found
        return -1;
    }
};

class Solution2 
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
        vector<vector<int>> moves = {{-1,-1}, {-1, 0}, {-1, 1}, {0, -1},{0, 1}, {1, -1}, {1, 0}, {1, 1}};
        int n = grid.size() - 1;
        int m = grid[0].size() - 1;
        
        queue<vector<int>> q;
        
        if(grid[0][0] || grid[n][m])
            return -1;
        
        q.push({0, 0, 1});
        
        while(!q.empty())
        {
            vector<int> top = q.front();
            q.pop();
            
            if(top[0] == n && top[1] == m)
                return top[2];
            
            for(vector<int> move: moves)
            {
                int x = top[0] + move[0];
                int y = top[1] + move[1];
                
                if(0 <= x && x <= n && 0 <= y && y <= m && grid[x][y] == 0)
                {
                    grid[x][y] = 1;             // Mark visited
                    q.push({x, y, top[2] + 1});
                }
            }
        }
        
        return -1;
    }
};