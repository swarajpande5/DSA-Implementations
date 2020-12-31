// Recursive BFS on an Undirected Unweighted Graph
#include <stdio.h>
#include <stdlib.h>

// Unweighted Undirect Graph Implementation
typedef struct Node
{
    int dest;
    struct Node* link; 
}Node;

typedef struct AdjList
{
    Node *head;
}AdjList;

typedef struct Graph
{
    int vertices;
    AdjList *array;
    int *visited;
}Graph;

Node *newNode(int dest)
{
    Node *in;
    in = (Node *)malloc(sizeof(Node));
    in -> dest = dest;
    in -> link = NULL;

    return in;
}

Graph *createGraph(int v)
{
    Graph *graph;
    graph = (Graph *)malloc(sizeof(Graph));
    
    graph -> vertices = v;
    graph -> array = (AdjList *)malloc(v * sizeof(AdjList));
    graph -> visited = (int *)malloc(v * sizeof(int));

    for(int i = 0; i < v; i++)
    {
        graph -> array[i].head = NULL;
        graph -> visited[i] = 0;
    }

    return graph;
}

void addEdge(Graph *graph, int src, int dest)
{

    Node *in = newNode(dest);
    in -> link = graph -> array[src].head;
    graph -> array[src].head = in;

    in = newNode(src);
    in -> link = graph -> array[dest].head;
    graph -> array[dest].head = in;
}

void printGraph(Graph *graph)
{
    for(int v = 0; v < graph -> vertices; v++)
    {
        Node *curr = graph -> array[v].head;
        printf("Adjacency list of vertex %d\nHEAD ", v);
        while(curr != NULL)
        {
            printf("-> %d", curr -> dest);
            curr = curr -> link;
        }
        printf("-> NULL\n");
    }
}

void dfs(Graph *graph, int startVertex)
{
    graph -> visited[startVertex] = 1;
    printf("Visited %d\n", startVertex);
    
    Node *currNode = graph -> array[startVertex].head;
    
    while(currNode != NULL)
    {
        int connectedVertex = currNode -> dest;

        if(graph -> visited[connectedVertex] == 0)
            dfs(graph, connectedVertex);

        currNode = currNode -> link;
    }
}

int main()
{
    int v = 5;
    Graph *graph = createGraph(5);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 4);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);

    dfs(graph, 0);

    return 0;
}