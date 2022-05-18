// Critical connections in a network: https://leetcode.com/problems/critical-connections-in-a-network/submissions/

class Solution 
{
public:
    
    vector<vector<int>> ans;
    
    void dfs(vector<vector<int>> &adj, int node, int parent, vector<bool> &visited, vector<int> &tin, vector<int> &low, int &timer)
    {
        visited[node] = true;
        tin[node] = low[node] = timer;
        timer++;
        
        for(auto to: adj[node])
        {
            if(to == parent)
                continue;
            if(!visited[to])
            {
                dfs(adj, to, node, visited, tin, low, timer);
                
                low[node] = min(low[node], low[to]);
                
                if(low[to] > tin[node])
                    ans.push_back({node, to});
            }
            
            else 
                low[node] = min(low[node], tin[to]);
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) 
    {
        vector<vector<int>> adj(n);
        for(auto edge: connections)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<int> tin(n, -1);
        vector<int> low(n, -1);
        vector<bool> visited(n, false);
        int timer = 0;
        
        for(int i = 0; i < n; i++)
            if(!visited[i])
                dfs(adj, i, -1, visited, tin, low, timer);
        
        return ans;
    }
};