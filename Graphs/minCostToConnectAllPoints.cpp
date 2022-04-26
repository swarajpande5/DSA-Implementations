// Min cost to connect all points: https://leetcode.com/problems/min-cost-to-connect-all-points/

class Solution 
{
public:
    
    // Min priority queue comparator according to the second value of the pair
    struct comp
    {
        bool operator() (pair<int, int> &a, pair<int, int> &b)
        {
            return a.second > b.second;
        }
    };
    
    int getDistance(vector<int> &v1, vector<int> &v2)
    {
        return abs(abs(v1[0] - v2[0]) + abs(v1[1] - v2[1]));
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) 
    {
        int n = points.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
        
        vector<vector<pair<int, int>>> graph(n);
        
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                graph[i].push_back({j, getDistance(points[i], points[j])});
                graph[j].push_back({i, getDistance(points[i], points[j])});
            }
        }
        
        vector<bool> visited(n, false);
        int ans = 0;
        
        pq.push({0, 0});
        while(!pq.empty())
        {
            auto [node, weight] = pq.top();
            pq.pop();
            
            if(visited[node])
                continue;
            
            visited[node] = true;
            
            ans += weight;
            
            for(auto [nbr, nbrWeight]: graph[node])
                if(!visited[nbr])
                    pq.push({nbr, nbrWeight});
        }
        
        return ans;
    }
};