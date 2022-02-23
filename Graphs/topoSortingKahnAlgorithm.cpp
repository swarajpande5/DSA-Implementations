// Kahn's algorithm for Topological Sort
// https://www.geeksforgeeks.org/topological-sorting-indegree-based-solution/
// https://iq.opengenus.org/kahns-algorithm-topological-sort/

// Pair contains topological ordering in vector and a boolean value indicating whether cycle exists or not
// BFS based solution
#include <bits/stdc++.h>
using namespace std;

pair<vector<int>, bool> kahn(int V, vector<vector<int>>& adj) 
{
    vector<int> topo;
    vector<int> inDeg(V, 0);
    queue<int> q;
    
    int visited = 0;

    for(int i = 0; i < V; i++)
        for(auto x: adj[i])
            inDeg[x]++;

    for(int i = 0; i < V; i++)
        if(inDeg[i] == 0)
            q.push(i);

    while(!q.empty())
    {
        visited++;
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
    
    return {topo, visited != V};
}

int main()
{
    int x, y, V, e;
    cin >> V >> e;
    vector<vector<int>> adj(V);
    
    for(int i = 0; i < e; i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);
    }

    pair<vector<int>, bool> topo = kahn(V, adj);

    for(int i = 0; i < topo.first.size(); i++)
        cout << topo.first[i] << " ";
    cout << "\n";

    if(topo.second)
        cout << "Cycle exists in graph\n";
    else 
        cout << "No cycle exists in graph\n";

    return 0;
}