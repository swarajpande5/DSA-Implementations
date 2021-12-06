// M - Coloring Problem : https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1
#include <bits/stdc++.h>
using namespace std;

bool isSafe(int v, bool graph[101][101], int color[101], int c, int V)
{
    // Checking if the connected nodes to v have same colour as c
    for(int i = 0; i < V; i++)
        if(graph[v][i] && c == color[i])
            return false;
    
    // Returning true if no connected node has same colour
    return true;
}

bool graphColoringUtil(bool graph[101][101], int m, int color[101], int v, int V)
{
    // If all vertices have been assigned colour then returning true
    if(v == V)
        return true;
    
    for(int c = 1; c <= m; c++)
    {
        // Checking if this colour can be given to a particular node
        if(isSafe(v, graph, color, c, V))
        {
            // assigning this color
            color[v] = c;

            // calling the function recursively and checking if other nodes can be assigned other colors
            if(graphColoringUtil(graph, m, color, v + 1, V) == true)
                return true;
            
            // if not true, then we backtrack and remove the color for that node
            color[v] = 0;
        }

        
    }
    // if no color can be assigned, returning false
    return false;
}

bool graphColoring(bool graph[101][101], int m, int V)
{
    int color[V];
    memset(color, 0, sizeof(color));

    if(graphColoringUtil(graph, m, color, 0, V) == false)
        return false;

    return true;
}

int main()
{
    int n, m, e;
    cin >> n >> m >> e;
    
    bool graph[101][101];
    for(int i = 0; i < n; i++)
        memset(graph[i], 0, sizeof(graph[i]));

    for(int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;

        graph[a - 1][b - 1] = 1;
        graph[b - 1][a - 1] = 1;
    }

    cout << graphColoring(graph, m, n) << "\n";

    return 0;
}