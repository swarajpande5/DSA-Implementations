// Dijkstra's Algorithm with restoration using Predecessor Array 
// https://cp-algorithms.com/graph/dijkstra.html
#include <bits/stdc++.h>
using namespace std;

#define vpii vector<pair<int, int>> 
#define INF 1e9

void dijkstra(int n, vpii adj[], int source, vector<int> &dist, vector<int> &pred)
{
    dist.assign(n, INF);
    pred.assign(n, -1);

    vector<bool> visited(n, false);

    dist[source] = 0;

    for(int i = 0; i < n; i++)
    {
        int v = -1;
        for(int j = 0; j < n; j++)
        {
            if(!visited[j] && (v == -1 || dist[j] < dist[v]))
                v = j;
        }

        if(dist[v] == INF)
        break;

        visited[v] = true;
        for(auto edge : adj[v])
        {
            int to = edge.first;
            int weight = edge.second;

            if(dist[v] + weight < dist[to])
            {
                dist[to] = dist[v] + weight;
                pred[to] = v;
            }
        }
    }
}

vector<int> restorePath(int s, int t, vector<int> const &pred)
{
    vector<int> path;

    for(int v = t; v != s; v = pred[v])
        path.push_back(v);
    path.push_back(s);

    reverse(path.begin(), path.end());

    return path;
}

int main()
{
    int nodes, edges, source, terminal;
    int u, v, w;

    cout << "Enter nodes and edges: ";
    cin >> nodes >> edges;

    // (Adjacency Matrix with weights) 2-D vector containing node-weight pairs for an undireted graph
    vpii adj[nodes + 1];

    cout << "Enter edges with weights: \n";
    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    cout << "Enter source: ";
    cin >> source;

    vector<int> dist, pred;
    dijkstra(nodes, adj, source, dist, pred);

    cout << "Distances: ";
    for(auto ele: dist)
        cout << ele << " ";
    cout << "\n";

    cout << "Predecessors: ";
    for(auto ele: pred)
        cout << ele << " ";
    cout << "\n";

    cout << "Enter terminal: ";
    cin >> terminal;

    vector<int> path = restorePath(source, terminal, pred);

    cout << "Path: ";
    for(auto ele: path)
        cout << ele << " ";
    cout << "\n";

    return 0;
}

