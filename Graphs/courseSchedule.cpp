// Course schedule: https://leetcode.com/problems/course-schedule/
// Using Kahn's algorithm for topological sorting
class Solution 
{
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        // Creating adjacency matrix
        int V = numCourses;
        vector<vector<int>> adj(numCourses);
        
        for(auto p: prerequisites)
            adj[p[0]].push_back(p[1]);
    
        // Toposort BFS Kahn's algorithm
        vector<int> topo;
        vector<int> inDeg(V, 0);
        queue<int> q;
        
        for(int i = 0; i < V; i++)
            for(auto x: adj[i])
                inDeg[x]++;
    
        for(int i = 0; i < V; i++)
            if(inDeg[i] == 0)
                q.push(i);
    
        while(!q.empty())
        {
            int t = q.front();
            q.pop();
            
            topo.push_back(t);
            
            for(auto x: adj[t])
            {
                inDeg[x]--;
                if(inDeg[x] == 0)
                    q.push(x);
            }   
        }
        
        return topo.size() == V;
        
    }
};