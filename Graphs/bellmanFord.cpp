// Bellman Ford Algorithm :
#include <bits/stdc++.h>
using namespace std;

typedef struct Edge
{
    int src, dest, weight;
}Edge;

void bellmanFord(Edge edge[], int v, int e, int src)
{
    int dist[v];

    // Initializing distances from src to all other vertices as infinite.
    for(int i = 0; i < v; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;

    // Relaxing all the edges |V| - 1 times
    for(int i = 0; i < v - 1; i++)
    {
        for(int j = 0; j < e; j++)
        {
            int u = edge[j].src;
            int v = edge[j].dest;
            int w = edge[j].weight;

            if(dist[u] != INT_MAX && dist[v] > dist[u] + w)
                dist[v] = dist[u] + w;
        }
    }

    // Checking for negative-weight cycles. If we get a negative cycle, we return.
    for(int j = 0; j < e; j++)
    {
        int u = edge[j].src;
        int v = edge[j].dest;
        int w = edge[j].weight;

        if(dist[u] != INT_MAX && dist[v] > dist[u] + w)
        {
            cout << "Negative cycle!\n";
            return;
        }
    }

    // Finally printing the distance array
    for(int i = 0; i < v; i++)
        cout << dist[i] << " ";
    cout << "\n";
}

int main()
{
    int v, e;
    cin >> v >> e;
    Edge edge[e];
    for(int i = 0; i < e; i++)
        cin >> edge[i].src >> edge[i].dest >> edge[i].weight;

    bellmanFord(edge, v, e, 0);

    return 0;
}