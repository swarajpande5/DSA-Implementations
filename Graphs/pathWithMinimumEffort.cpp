// Path with minimum effort: https://leetcode.com/problems/path-with-minimum-effort/
/*
    Intuition:  
    We want the minimum possible value for the max absolute difference 
    in any path that will help us to reach at the bottom corner of the matrix.
    -   So if we assume a threshold value (in binary search called as mid) and check
        whether there exists a path through which we can reach to end, then that might be the answer.
        Else we look for some bigger values.
    -   For traversing the matrix, we may use either BFS or DFS. Here we use BFS.
*/

class Solution 
{
public:
    
    // Change in direction coordinates
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};
    
    // To check whether the current path chosen under bounds
    bool isValid(int x, int y, int n, int mid)
    {
        return x >= 0 && x < n && y >= 0 && y < mid;
    }
    
    bool bfs(vector<vector<int>> heights, int k)
    {
        int rows = heights.size();
        int cols = heights[0].size();
        
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        queue<pair<int, int>> q;
        
        q.push({0, 0});
        visited[0][0] = 1;
        
        while(!q.empty())
        {
            auto [cx, cy] = q.front();
            q.pop();
            
            if(cx == rows - 1 && cy == cols - 1)
                return true;
            
            for(int i = 0; i < 4; i++)
            {
                int x = cx + dx[i];
                int y = cy + dy[i];
                
                if(isValid(x, y, rows, cols) && !visited[x][y])
                {
                    // If the new (x, y) are valid, checking whether absolute difference is less than mid or not
                    if(abs(heights[cx][cy] - heights[x][y]) <= k)
                    {
                        q.push({x, y});
                        visited[x][y] = true;
                    }
                }
            }
        }
        
        return false;
    }
    
    int minimumEffortPath(vector<vector<int>>& heights) 
    {
        int low = 0;
        int high = 1e6;
        int ans = -1;
        
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            
            // If bfs on the current mid value is true, there might be other smaller values than mid which can be the answer
            if(bfs(heights, mid))
            {
                ans = mid;
                high = mid - 1;
            }
            else 
            {
                low = mid + 1;
            }
        }
        
        return ans;
    }
};