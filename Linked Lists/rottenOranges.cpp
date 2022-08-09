// Rotting Oranges: https://leetcode.com/problems/rotting-oranges/
// Rotten Oranges: https://practice.geeksforgeeks.org/problems/rotten-oranges2536/1

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        if (grid.empty()) // if there is no orange.
            return 0;

        int countFreshOranges = 0;
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q; // queue to store the index of the cell where rotten oranges are placed.

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                    countFreshOranges++;
                else if (grid[i][j] == 2)
                    q.push({i, j});
            }
        }

        int time = 0;
        // four adjacent positions at which the oranged placed will get rotten.
        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

        while (countFreshOranges != 0 && !q.empty())
        {
            int qsize = q.size();

            for (int i = 0; i < qsize; i++)
            {
                int rottenI = q.front().first;
                int rottenJ = q.front().second;
                q.pop();

                for (auto d : dirs)
                {
                    int newX = rottenI + d.first;
                    int newY = rottenJ + d.second;
                    // if we got any fresh orange adjacent to the rotten orange then it will get rotten and
                    // count of fresh oranges will reduce and we will push the new index of rotten orange in
                    // the queue.
                    if (newX >= 0 && newX < m && newY >= 0 && newY < n && grid[newX][newY] == 1)
                    {
                        grid[newX][newY] = 2;
                        countFreshOranges--;
                        q.push({newX, newY});
                    }
                }
            }
            time++;
        }
        return countFreshOranges == 0 ? time : -1;
    }
};

// GFG Solution (Striver)
struct node 
{
    int x, y, time;
    node(int _x, int _y, int _time) 
    {
        x = _x;
        y  = _y;
        time = _time;
    }
};

class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size(); 
        
        queue<node> q;
        int cntOranges = 0;
        for(int i = 0; i < m; i++)
        {    for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 2)
                q.push(node(i, j, 0));
        
                if(grid[i][j] != 0)
                    cntOranges++;
            }
        }
        
        int maxTime = 0;
        int rottenCount = 0;
        
        while(!q.empty())
        {
            int x = q.front().x;
            int y = q.front().y;
            int time = q.front().time;
            q.pop();
            
            maxTime = max(maxTime, time);
            rottenCount++;
            
            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, 1, 0, -1};
            
            for(int idx = 0; idx < 4; idx++)
            {
                int newX = x + dx[idx];
                int newY = y + dy[idx];
                
                if(newX >= 0 && newX < m && newY >= 0 && newY < n && grid[newX][newY] == 1)
                {
                    grid[newX][newY] = 2;
                    q.push(node(newX, newY, time + 1));
                }
            }
        }
        
        if(rottenCount == cntOranges)
            return maxTime;
        
        return -1;
    }
};