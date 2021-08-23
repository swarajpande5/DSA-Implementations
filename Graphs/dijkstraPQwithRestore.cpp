// Dijkstra's algorithm for single source shortest paths using Priority Queue
// with restorations using Predecessor array.
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<vector<pair<int, int>>> Graph;

#define INF 1e9

vi dijkstraPQ(Graph graph, int nodes, int source, vector<int> &pred)
{
    pred.assign(nodes, -1);

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
                pred[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

vi restorePath(int source, int terminal, vi &pred)
{
    vi path;

    for(int v = terminal; v != source; v = pred[v])
        path.push_back(v);
    path.push_back(source);

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

    vi pred;
    vi dist = dijkstraPQ(graph, nodes, source, pred);

    cout << "The distances are: ";
    for (auto ele: dist)
        cout << ele << " ";
    cout << "\n";

    cout << "The predecessors are: ";
    for(auto ele: pred)
        cout << ele << " ";
    cout << "\n";


    cout << "Enter Terminal: ";
    cin >> terminal;
    vi path = restorePath(source, terminal, pred);

    cout << "The path is: ";
    for(auto ele: path)
        cout << ele << " ";
    cout << "\n";

    return 0;
}