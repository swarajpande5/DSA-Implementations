// Number of operations to make network connected: https://leetcode.com/problems/number-of-operations-to-make-network-connected/

class Solution {
public:
    
    void dfs(vector<vector<int>> &graph, vector<bool> &visited, int src) {
        visited[src] = true; 
        for(int nbr: graph[src]) 
            if(!visited[nbr])
                dfs(graph, visited, nbr);
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n - 1)
            return -1; 
        
        vector<vector<int>> graph(n); 
        for(auto edge: connections) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        vector<bool> visited(n, false); 
        int connComp = 0;
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                dfs(graph, visited, i);
                connComp++;
            }
        }
        
        return connComp - 1;
    }
};