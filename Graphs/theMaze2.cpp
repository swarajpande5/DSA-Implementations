// The maze 2: https://www.lintcode.com/problem/788/

class Solution 
{
public:
    /**
     * @param maze: the maze
     * @param start: the start
     * @param destination: the destination
     * @return: the shortest distance for the ball to stop at the destination
     */
    int shortestDistance(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination) 
    {
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        int n = maze.size();
        int m = maze[0].size();
        
        priority_queue< 
            pair<int,pair<int,int>>, 
            vector<pair<int,pair<int,int>>>,   
            greater<pair<int,pair<int,int>>>> pq; 

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX)); 
        
        dist[start[0]][start[1]] = 0; 
        pq.push({0, {start[0], start[1]}}); 

        while(!pq.empty())
        {
            int dis = pq.top().first;
            int x = pq.top().second.first; 
            int y = pq.top().second.second; 
            pq.pop(); 

            for(int idx = 0; idx < 4; idx++)
            {
                int newX = x;
                int newY = y; 
                int cnt = 0; 

                while(newX >= 0 && newY >= 0 && newX < n && newY < m && maze[newX][newY] == 0)
                {
                    newX += dx[idx];
                    newY += dy[idx];
                    cnt++;
                }

                // Just come one step back, as the above loop will end at an invalid cell
                newX -= dx[idx]; 
                newY -= dy[idx]; 
                cnt--; 

                if(dis + cnt < dist[newX][newY]) 
                {
                    dist[newX][newY] = dis + cnt; 
                    pq.push({dis + cnt,{newX,  newY}}); 
                }
            }   
        }

        if(dist[destination[0]][destination[1]] == INT_MAX)  
            return -1;
        
        return dist[destination[0]][destination[1]];
    }
};