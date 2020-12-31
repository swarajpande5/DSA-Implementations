/* 
    Program to generate Adjacency List for 
    Directed Weighted Graph.
*/ 
#include <stdio.h>
#include <stdlib.h>

// Structure to represent an adjacency list node
typedef struct Node
{
    int dest, weight;
    struct Node* link; 
}Node;

// Structure to represent an adjcency list
typedef struct AdjList
{
    Node *head;
}AdjList;

/*
Structure to represent a graph. A graph 
is an array of adjacency lists. 
Size of this array will be 'vertices'
*/
typedef struct Graph
{
    int vertices;
    AdjList *array;
}Graph;

// Function to create a new adjacency list node
Node *newNode(int dest, int weight)
{
    Node *in;
    in = (Node *)malloc(sizeof(Node));
    in -> dest = dest;
    in -> weight = weight;
    in -> link = NULL;

    return in;
}

// Function to create a graph of 'v' vertices
Graph *createGraph(int v)
{
    Graph *graph;
    graph = (Graph *)malloc(sizeof(Graph));
    
    // Creating array of adjacency list
    graph -> vertices = v;
    graph -> array = (AdjList *)malloc(v * sizeof(AdjList));

    // Initializing head of each adjacency list as NULL
    for(int i = 0; i < v; i++)
        graph -> array[i].head = NULL;

    return graph;
}

// Function to add an Edge to directed graph
void addEdge(Graph *graph, int src, int dest, int weight)
{
    /* Adding an edge from src to dest, 
    this new node is added to adjacency list of src 
    at the beginning. */
    Node *in = newNode(dest, weight);
    in -> link = graph -> array[src].head;
    graph -> array[src].head = in;
}

void fillAdjList(Graph *graph, int edges)
{
    int srcIn, destIn, weightIn;
    for(int i = 0; i<edges; i++)
    {
        scanf("%d%d%d", &srcIn, &destIn, &weightIn);
        addEdge(graph, srcIn, destIn, weightIn);
    }
}

// Function to print adjacency lists of all the nodes
void printGraph(Graph *graph)
{
    for(int v = 0; v < graph -> vertices; v++)
    {
        Node *curr = graph -> array[v].head;
        printf("Adjacency list of vertex %d\nHEAD ", v);
        while(curr != NULL)
        {
            printf("-> %d(%d)", curr -> dest, curr -> weight);
            curr = curr -> link;
        }
        printf("-> NULL\n");
    }
}

int main()
{
    int verticesIn, edges;
    scanf("%d%d", &verticesIn, &edges);
    
    Graph *graph = createGraph(verticesIn);
    
    fillAdjList(graph, edges);

    printGraph(graph);

    return 0;
}
