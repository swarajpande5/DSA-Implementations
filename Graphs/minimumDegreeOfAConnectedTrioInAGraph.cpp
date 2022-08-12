// Minimum degree of a connected trio in a graph: https://leetcode.com/problems/minimum-degree-of-a-connected-trio-in-a-graph/

class Solution
{
public: 
    int minTrioDegree(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(n + 1, vector<int>(n + 1, 0)); 
        vector<int> degree(n + 1, 0); 

        for(auto edge: edges)
        {
            int u = edge[0], v = edge[1]; 

            adj[u][v] = 1;
            adj[v][u] = 1; 
            degree[u]++;
            degree[v]++;
        }

        int mn = INT_MAX; 

        for(int i = 1; i <= n; i++)
        {
            for(int j = i + 1; j <= n; j++)
            {
                for(int k = j + 1; k <= n; k++)
                {
                    if(adj[i][j] && adj[j][k] && adj[k][i])
                        mn = min(mn, degree[i] + degree[j] + degree[k] - 6);
                }
            }
        }

        if(mn == INT_MAX)
            return -1;
        
        return mn;
    }
};