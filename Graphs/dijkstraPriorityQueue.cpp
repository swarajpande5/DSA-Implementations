// Dijkstra's algorithm for single source shortest paths using Priority Queue
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<vector<pair<int, int>>> Graph;

#define INF 1e9

vi dijkstraPQ(Graph graph, int nodes, int source)
{
    vi dist(nodes, INF); // For storing distance from source
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        for (auto &next : graph[u])
        {
            int v = next.first;
            int w = next.second;

            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main()
{
    int nodes, edges, source;
    int u, v, w;

    cout << "Enter nodes and edges: ";
    cin >> nodes >> edges;

    // (Adjacency Matrix with weights) 2-D vector containing node-weight pairs for an undirected graph
    Graph graph(nodes + 1);

    cout << "Enter edges with weights: \n";
    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    cout << "Enter source: ";
    cin >> source;

    vi dist = dijkstraPQ(graph, nodes, source);

    cout << "The distances are: ";
    for (int i = 0; i < nodes; i++)
        cout << dist[i] << " ";
    cout << "\n";

    return 0;
}
