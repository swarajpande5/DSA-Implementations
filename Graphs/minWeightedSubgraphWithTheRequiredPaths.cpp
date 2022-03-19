// Minimum weighted subgraphs with the required path: https://leetcode.com/problems/minimum-weighted-subgraph-with-the-required-paths/
//                                                    https://leetcode.com/problems/minimum-weighted-subgraph-with-the-required-paths/discuss/1844091/C%2B%2B-Dijkstra-3-times-with-illustration

class Solution 
{   
public:
    
    void djikstra(vector<vector<pair<long, long>>> graph, int source, vector<long> &dist)
    {
        priority_queue<pair<long, long>, vector<pair<long, long>>, greater<pair<long, long>>> pq;
        dist[source] = 0;
        pq.emplace(0, source);
        
        while(pq.size())
        {
            auto [cost, u] = pq.top();
            pq.pop();
            
            if(cost > dist[u])
                continue;
            
            for(auto &[v, c]: graph[u])
            {
                if(dist[v] > dist[u] + c)
                {
                    dist[v] = dist[u] + c;
                    pq.emplace(dist[v], v);
                }
            }
        }
    }
    
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) 
    {
        vector<vector<pair<long, long>>> graph(n), reversedGraph(n);
        for(auto &edge: edges)
        {
            long u = edge[0];
            long v = edge[1];
            long w = edge[2];
            
            graph[u].emplace_back(v, w);
            reversedGraph[v].emplace_back(u, w);
        }
        
        vector<long> da(n, LONG_MAX), db(n, LONG_MAX), dd(n, LONG_MAX);
        
        djikstra(graph, src1, da);
        djikstra(graph, src2, db);
        djikstra(reversedGraph, dest, dd);
        
        long ans = LONG_MAX;
        for(int i = 0; i < n; i++)
        {
            if(da[i] == LONG_MAX || db[i] == LONG_MAX || dd[i] == LONG_MAX)
                continue;
            
            ans = min(ans, da[i] + db[i] + dd[i]);
        }
        
        return ans == LONG_MAX ? -1 : ans;
    }
};