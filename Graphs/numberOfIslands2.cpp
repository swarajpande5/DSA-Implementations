// Number of islands 2 (LC Premium): https://www.lintcode.com/problem/434/

/**
 * Definition for a point.
 * struct Point 
 * {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

class DSU 
{
private:
    vector<int> parent, size;

public: 
    DSU(int n)
    {
        for(int i = 0; i <= n; i++)
        {
            parent.push_back(i);
            size.push_back(1);
        }
    }

    int findParent(int node)
    {
        if(parent[node] == node)
            return node;
        
        // Path compression 
        return parent[node] = findParent(parent[node]);
    }

    void unionSize(int u, int v)
    {
        int pu = findParent(u);
        int pv = findParent(v);

        if(pu == pv)
            return; 
        
        // Size optimization
        if(size[pu] < size[pv])
        {
            parent[pu] = pv; 
            size[pv] += size[pu];
        }
        else 
        {
            parent[pv] = pu; 
            size[pu] += size[pv];
        }
    }
};

class Solution 
{
public:
    /**
     * @param n: An integer
     * @param m: An integer
     * @param positions: an array of point
     * @return: an integer array
     */
    vector<int> numIslands2(int n, int m, vector<Point> &positions) 
    {
        DSU dsu(n * m + 1);
        int count = 0; 

        vector<int> ans; 
        vector<vector<int>> grid(n, vector<int>(m, 0));

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        for(auto pos: positions)
        {
            int x = pos.x;
            int y = pos.y; 

            if(grid[x][y] == 1)
            {
                ans.push_back(count);
                continue; 
            }

            count++;

            grid[x][y] = 1; 

            // Converting 2D coordinate to 1D coordinate
            int idx1 = x * m + (y + 1);

            for(int dir = 0; dir < 4; dir++)
            {
                int newX = x + dx[dir];
                int newY = y + dy[dir];

                int idx2 = newX * m + (newY + 1);

                if( newX >= 0 && newY >= 0 && newX < n && newY < m && grid[newX][newY] == 1 
                    && dsu.findParent(idx1) != dsu.findParent(idx2))
                {
                    dsu.unionSize(idx1, idx2);
                    count--;
                }
            }

            ans.push_back(count);
        }

        return ans;
    }
};