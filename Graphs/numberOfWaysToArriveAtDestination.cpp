// Number of ways to arrive at destination: https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/

class Solution 
{
public:
    int countPaths(int n, vector<vector<int>>& roads) 
    {
        long long mod = 1e9 + 7; 
        
        vector<long long> ways(n , 0);
        vector<long long> dist(n, 1e18L);
        
        ways[0] = 1;
        dist[0] = 0;
        
        // Creating the graph 
        vector<pair<long long,long long>> adj[n]; 
        for(auto it : roads) 
        {
            adj[it[0]].push_back({it[1], it[2]}); 
            adj[it[1]].push_back({it[0], it[2]}); 
        }
        
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq; 
        
        // {distance, node}
        pq.push({0, 0});
        
        while(!pq.empty())
        {
            long long dis = pq.top().first;    
            long long node = pq.top().second;
            pq.pop(); 
            
            for(auto nbr: adj[node])
            {
                long long adjNode = nbr.first;
                long long wt = nbr.second; 
                
                if(wt + dis < dist[adjNode])
                {
                    dist[adjNode] = wt + dis; 
                    ways[adjNode] = ways[node];
                    
                    pq.push({dist[adjNode], adjNode});
                }
                else if(wt + dis == dist[adjNode])
                {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }
        
        return ways[n - 1];
    
    }
};