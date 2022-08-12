// The maze (LC Premium): https://www.lintcode.com/problem/787/

class Solution
{
public:
    /**
     * @param maze: the maze
     * @param start: the start
     * @param destination: the destination
     * @return: whether the ball could stop at the destination
     */
    bool hasPath(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination)
    {
        int m = maze.size();
        int n = maze[0].size();

        queue<pair<int, int>> q;
        q.push({start[0], start[1]});

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        vis[start[0]][start[1]] = true;

        while (!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if (x == destination[0] && y == destination[1])
                return true;

            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, 1, 0, -1};

            for (int idx = 0; idx < 4; idx++)
            {
                int newX = x;
                int newY = y;
                // Keep moving in a single direction till
                while (newX >= 0 && newX < m && newY >= 0 && newY < n && maze[newX][newY] == 0)
                {
                    newX += dx[idx];
                    newY += dy[idx];
                }

                // After this, we are sure that either we have crossed boundary or stopped at 1
                // Hence we revert back to the last position of the ball
                newX -= dx[idx];
                newY -= dy[idx];

                if (vis[newX][newY] == 0)
                {
                    vis[newX][newY] = true;
                    q.push({newX, newY});
                }
            }
        }

        return false;
    }
};