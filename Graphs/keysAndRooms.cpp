// Keys and rooms: https://leetcode.com/problems/keys-and-rooms/

class Solution 
{
public:
    
    void dfs(vector<vector<int>> &graph, int node, vector<bool> &visited)
    {
        visited[node] = true;
        
        for(auto neighbor: graph[node])
        {
            if(!visited[neighbor])
                dfs(graph, neighbor, visited);
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) 
    {
        int n = rooms.size();
        vector<bool> visited(n, false);
        
        dfs(rooms, 0, visited);
        
        for(int i = 0; i < n; i++)
            if(!visited[i])
                return false;
        
        return true;
    }
};