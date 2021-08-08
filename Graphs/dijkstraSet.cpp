// Dijkstra's algorithm for single source shortest paths using Set
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<vector<pair<int, int>>> Graph;

#define INF 1e9

vi dijkstraSet(Graph graph, int nodes, int source)
{
    vi dist(nodes, INF); // For storing distance from source
    set<pii> s;

    dist[source] = 0;
    s.insert({0, source});

    while (!s.empty())
    {
        auto top = s.begin();
        int u = top -> second;
        s.erase(top);

        for (auto &next : graph[u])
        {
            int v = next.first;
            int w = next.second;

            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                s.insert({dist[v], v});
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

    // (Adjacency Matrix with weights) 2-D vector containing node-weight pairs for an undireted graph
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

    vi dist = dijkstraSet(graph, nodes, source);

    cout << "The distances are: ";
    for (int i = 0; i < nodes; i++)
        cout << dist[i] << " ";
    cout << "\n";

    return 0;
}