// Course schedule: https://leetcode.com/problems/course-schedule-ii/

class Solution 
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        // Creating adjacency matrix 
        int v = numCourses;
        vector<vector<int>> adj(v);
        
        for(auto p: prerequisites)
            adj[p[0]].push_back(p[1]);
        
        // Toposort BFS Kahn's algorithm
        vector<int> topo;
        vector<int> inDeg(v, 0);
        queue<int> q;
        
        for(int i = 0; i < v; i++)
            for(auto x: adj[i])
                inDeg[x]++;
        
        for(int i = 0; i < v; i++)
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
        
        if(topo.size() != v)
            return {};
        
        reverse(topo.begin(), topo.end());
        return topo;
    }
};