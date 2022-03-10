// Program to check wheter path exists between two given nodes in graph or not
#include <bits/stdc++.h>
using namespace std;

unordered_map<int, vector<int>> adj;

void addEdge(int u, int v)
{
    adj[u].push_back(v);
}

bool isConnected(int source, int dest)
{
    unordered_map<int, bool> visited;
    queue<int> q;

    q.push(source);
    visited[source] = true;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        if (node == dest)
            return true;

        for (int i : adj[node])
        {
            if (visited[i] == false)
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
    return false;
}

int main()
{
    int n;
    cin >> n;

    vector<int> nodes(n);
    for (int &x : nodes)
        cin >> x;

    int e;
    cin >> e;
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
    }
    int source, dest;
    cin >> source >> dest;

    cout << isConnected(source, dest) << endl;
    return 0;
}