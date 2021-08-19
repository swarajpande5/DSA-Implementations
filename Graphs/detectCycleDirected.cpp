// Detect cycle in a directed graph : https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<int> adj[], int s, vector<bool> &visited, vector<bool> &ances)
{
    visited[s] = true;
    ances[s] = true;

    for(auto u: adj[s])
    {
        if(ances[u])
            return true;
        else if(!visited[u] && dfs(adj, u, visited, ances))
            return true;
    }

    ances[s] = false;
    return false;
}

bool isCyclic(int V, vector<int> adj[])
{
    vector<bool> visited(V, false);
    vector<bool> ances(V, false);

    for(int i = 0; i < V; i++)
        if(dfs(adj, i, visited, ances))
            return true;
    return false;
}

int main()
{
    int V, E;
    cin >> V >> E;

    vector<int> adj[V];

    for(int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    cout << isCyclic(V, adj) << "\n";

    return 0;
}