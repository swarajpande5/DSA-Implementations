// Network delay time: https://leetcode.com/problems/network-delay-time/

class Solution 
{
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
        // Simple Bellman Ford algorithm will return 
        // the distances to all the nodes from the source node 
        
        vector<int> dist(n + 1, INT_MAX);
        
        dist[k] = 0;
        for(int i = 0; i < n; i++)
        {
            for(vector<int> e: times)
            {
                int u = e[0];
                int v = e[1];
                int w = e[2];
                if(dist[u] != INT_MAX && dist[v] > dist[u] + w)
                    dist[v] = dist[u]+ w;
            }
        }
        int mx = 0;
        for(int i = 1; i <= n; i++)
            mx = max(mx, dist[i]);
        
        return mx == INT_MAX ? -1 : mx;
    }
};