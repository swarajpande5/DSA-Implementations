#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int vertex;
    struct node *next;
}Node;

typedef struct Graph
{
    int numVertices;
    struct node **adjLists;
}Graph;

Node *createNode(int value)
{
    Node *in = (Node *)malloc(sizeof(Node));
    in -> vertex = value;
    in -> next = NULL;

    return in;
}

Graph *createGraph(int vertices)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph -> numVertices = vertices;

    graph -> adjLists = malloc(vertices * sizeof(Node *));

    for(int i = 0; i < vertices; i++)
        graph -> adjLists[i] = NULL;

    return graph;
}

void addEdge(Graph *graph, int src, int dest)
{
    Node *newNode = createNode(dest);
    newNode -> next = graph -> adjLists[src];
    graph -> adjLists[src] = newNode;

    newNode = createNode(src);
    newNode -> next = graph -> adjLists[dest];
    graph -> adjLists[dest] = newNode;
}

void printGraph(Graph *graph)
{
    for(int v = 0; v < graph -> numVertices; v++)
    {
        Node *curr = graph -> adjLists[v];
        printf("Adjacency list of vertex %d\nHEAD ", v);
        while(curr != NULL)
        {
            printf("-> %d", curr -> vertex);
            curr = curr -> next;
        }
        printf("\n");
    }
}

int main() 
{
    Graph* graph = createGraph(4);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 0, 3);
    addEdge(graph, 1, 2);

    printGraph(graph);

    return 0;
}