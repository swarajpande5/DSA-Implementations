// Is Graph Bipartite: https://leetcode.com/problems/is-graph-bipartite/

class Solution 
{
public:
    bool isBipartite(vector<vector<int>>& graph) 
    {
        int n = graph.size();
        
        // 0: uncolored, 1: color A, -1: color B
        vector<int> color(n);
        
        queue<int> q;
        
        for(int i = 0; i < n; i++)
        {
            // Skipping already colored nodes
            if(color[i])
                continue;
            
            // BFS with seed node i to color neighbors with opposite color
            color[i] = 1;
            q.push(i);
            
            while(!q.empty())
            {
                int curr = q.front();
                q.pop();
                
                for(int nbr: graph[curr])
                {
                    // If uncolored, color with opposite color as of adjacent node
                    if(!color[nbr])
                    {
                        color[nbr] = -color[curr];
                        q.push(nbr);
                    }
                    
                    // If adjacent node already has the same color, it can't be bipartite
                    else if(color[nbr] == color[curr])
                        return false;
                }
            }
        }
        
        return true;
    }
};