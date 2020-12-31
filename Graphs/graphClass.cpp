#include <bits/stdc++.h>
using namespace std;

// Class definition for Undirected Graph
class Graph
{
    int nodes;
    vector<int> *adjList;

public:

    Graph(int inNodes);     // Constructor
    ~Graph();               // Destructor
    void addEdge(int src, int dest);    // Method to add edge
    void fillAdjList(int edges);        // Method to fill adjacency list
    void printAdjList();                // Method to print adjacency list
    void bfs(int startNode);            // Iterative Breadth-first search
    void dfs(int startNode);            // Iterative Depth-first search
    void rbfsUtility(vector<bool> visited, queue<int> q);   // Recursive function to be called inside rbfs
    void rbfs(int startNode);                               // Recursive Breadth-first search                                    
    void rdfsUtility(int startNode, vector<bool> visited);  // Recursive function to be called inside rdfs
    void rdfs(int startNode);                               // Recursive Depth-first search
    
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
    adjList[src].push_back(dest);   // Adding dest in adjacency list of src
    adjList[dest].push_back(src);   // Adding src in adjacency list of dest (Undirected)
}

void Graph::fillAdjList(int edges)
{
    int src, dest;
    for(int i = 0; i < edges; i++)
    {
        cin >> src >> dest;
        this -> addEdge(src, dest);
    }
}

void Graph::printAdjList()
{
    for(int i = 0; i < nodes; i++)
    {
        cout << "Adjacency List of vertex " << i << ": HEAD";
        
        for(auto ele: adjList[i])
            cout << "-> " << ele;
        
        cout << "\n";
    }
}

void Graph::bfs(int startNode)
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

void Graph::dfs(int startNode)
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

        if(visited[currNode] == false)
        {
            visited[currNode] = true;
            cout << "-> " << currNode;
        }

        for(auto ele: adjList[currNode])
        {
            if(visited[ele] == false)
                s.push(ele);
        }
    }
    cout << "\n";
}

void Graph::rbfsUtility(vector<bool> visited, queue<int> q)
{
    if(q.empty())
        return;

    int currNode = q.front();
    q.pop();
    cout << currNode << " ";

    for(auto ele: adjList[currNode])
    {
        if(visited[ele] == false)
        {
            visited[ele] = true;
            q.push(ele);
        }
    }
    rbfsUtility(visited, q);

}

void Graph::rbfs(int startNode)
{
    vector<bool> visited(nodes, false);
    queue<int> q;
    cout << "r-BFS on node " << startNode << " is: ";
    visited[startNode] = true;
    q.push(startNode);
    rbfsUtility(visited, q);
    cout << "\n";
}

void Graph::rdfsUtility(int startNode, vector<bool> visited)
{
    visited[startNode] = true;
    cout << startNode << " ";

    for(auto iter: adjList[startNode])
    {
        if(visited[iter] == false)
            rdfsUtility(iter, visited);
    }
}
void Graph::rdfs(int startNode)
{
    vector<bool> visited(nodes, false);
    cout << "r-DFS on node " << startNode << " is: ";
    rdfsUtility(startNode, visited);
    cout << "\n";
}

// Main
int main()
{
    int src, dest, nodes, edges, startNode;
    cout << "Enter number of Nodes and Edges: ";
    cin >> nodes >> edges;

    Graph graph(nodes);

    cout << "Enter edges (source destination): \n";
    graph.fillAdjList(edges);
    graph.printAdjList();

    cout << "Enter starting Node for Traversal: ";
    cin >> startNode;
    graph.bfs(startNode);
    graph.dfs(startNode);
    graph.rbfs(startNode);
    graph.rdfs(startNode);
    return 0;
}