// Detect cycle in an undirected graph: 

class Solution 
{
  public:
  
    // Utility function to detect cycle in undirected graph using BFS 
    bool bfs(int node, vector<int> adj[], vector<bool> &visited)
    {
        queue<pair<int, int>> q;
        q.push({node, -1});
        visited[node] = true; 
        
        while(!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for(auto nbr: adj[node])
            {
                if(!visited[nbr])
                {
                    q.push({nbr, node});
                    visited[nbr] = true;
                }
                else if(visited[nbr] == true && nbr != parent)
                    return true;
            }
        }
        
        return false;
    }
  
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) 
    {
        
        bool flag = false;
        vector<bool> visited(V, false);
        for(int i = 0; i < V; i++)
        {
            if(!visited[i])
            {
                if(bfs(i, adj, visited))
                {
                    flag = true;
                    break;
                }
            }
        }
        
        return flag;
    }
};