// Topological sort of a directed graph
#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int nodes;
    vector<int> *adjList;

    void topologicalSortUtil(int v, bool visited[], stack<int> &st);

public:
    Graph(int inNodes);
    ~Graph();
    void addEdge(int src, int dest);

    void topologicalSort();
};

Graph::Graph(int inNodes)
{
    nodes = inNodes;
    adjList = new vector<int>[inNodes];
}

Graph::~Graph()
{
    delete[] adjList;
}

void Graph::addEdge(int src, int dest)
{
    adjList[src].push_back(dest);
}

void Graph::topologicalSortUtil(int v, bool visited[], stack<int> &st)
{
    visited[v] = true;

    for (auto i = adjList[v].begin(); i != adjList[v].end(); i++)
        if (!visited[*i])
            topologicalSortUtil(*i, visited, st);
    st.push(v);
}

void Graph::topologicalSort()
{
    stack<int> st;

    bool visited[nodes];
    for (int i = 0; i < nodes; i++)
        visited[i] = false;

    for (int i = 0; i < nodes; i++)
        if (visited[i] == false)
            topologicalSortUtil(i, visited, st);

    while (st.empty() == false)
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << "\n";
}

int main()
{
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    g.topologicalSort();

    return 0;
}

// Easier way of writing the same topological sort function
class Solution
{
public:
    void topoSortUtil(vector<int> adj[], int node, stack<int> &st, vector<int> &visited)
    {
        visited[node] = 1;
        for (auto nbr : adj[node])
            if (!visited[nbr])
                topoSortUtil(adj, nbr, st, visited);

        st.push(node);
    }

    // Function to return list containing vertices in Topological order.
    vector<int> topoSort(int V, vector<int> adj[])
    {
        stack<int> st;
        vector<int> visited(V, 0);
        for (int i = 0; i < V; i++)
            if (!visited[i])
                topoSortUtil(adj, i, st, visited);

        vector<int> ans;
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};