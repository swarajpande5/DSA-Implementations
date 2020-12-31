#include <bits/stdc++.h>
using namespace std;

void fillAdjList(vector<int> adjList[], int nodes, int edges)
{
    int x, y;
    for(int i = 0; i < edges; i++)
    {
        cin >> x >> y;
        adjList[x].push_back(y); // Inserting y in adjacency list of x
        adjList[y].push_back(x); // Inserting x in adjacency list of y (Undirected)

    }
}

void printAdjList(vector<int> adjList[], int nodes)
{
    for(int i = 0; i < nodes; i++)
    {
        cout << "Adjacency List of vertex " << i << ": HEAD";
        
        for(auto ele: adjList[i])
            cout << "-> " << ele;
        
        cout << "\n";
    }
}

// Iterative BFS
void bfs(vector<int> adjList[], int nodes, int startNode)
{
    queue<int> q;
    vector<int> level(nodes, 0);
    vector<bool> visited(nodes, false);
    q.push(startNode);
    level[startNode] = 0; 
    visited[startNode] = true;

    cout << "BFS on node " << startNode << " is: " << startNode;

    while(!q.empty())
    {
        int currNode = q.front();
        q.pop();
        for(auto ele: adjList[currNode])
        {
            if(visited[ele] == false)
            {
                level[ele] = level[currNode] + 1;
                q.push(ele);
                visited[ele] = true;
                cout << "-> " << ele;
            }
        }
    }
    cout << "\n";
}

// Iterative DFS
void dfs(vector<int> adjList[], int nodes, int startNode)
{
    stack<int> s;
    vector<bool> visited(nodes, false);

    s.push(startNode);
    visited[startNode] = true;
    cout << "DFS on node " << startNode << " is: " << startNode;

    while(!s.empty())
    {
        int currNode = s.top();
        s.pop();
        for(auto ele: adjList[currNode])
        {
            if(visited[ele] == false)
            {
                s.push(ele);
                visited[ele] = true;
                cout << "-> " << ele;
            }
        }
    }
    cout << "\n";
}

int main()
{
    int x, y, nodes, edges, startNode;
    cout << "Enter number of Nodes and Edges: ";
    cin >> nodes >> edges;

    vector<int> adjList[nodes];

    cout << "Enter Edges (source destination): ";
    fillAdjList(adjList, nodes, edges);
    printAdjList(adjList, nodes);

    cout << "Enter starting Node for Traversal: ";
    cin >> startNode;
    bfs(adjList, nodes, startNode);
    dfs(adjList, nodes, startNode);

    return 0;
}