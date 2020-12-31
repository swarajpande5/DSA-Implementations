// Iterative BFS on an Undirected Unweighted Graph
#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

// Queue Implementation for BFS
typedef struct Queue
{
    int items[SIZE];
    int front;
    int rear;
}Queue;

Queue *createQueue()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q -> front = -1;
    q -> rear = -1;

    return q;
}

int isQueueEmpty(Queue *q)
{
    if(q -> rear == -1)
        return 1;
    else 
        return 0;
}

void enQueue(Queue *q, int value)
{
    if(q -> rear == SIZE -1)
        printf("Queue Overflow !\n");
    else
    {
        if(q -> front = -1)
            q -> front = 0;
        
        q -> rear++;
        q -> items[q -> rear] = value;
    }
}

int deQueue(Queue *q)
{
    int item;
    if(isQueueEmpty(q))
    {
        printf("Queue Underflow !\n");
        item = -1;
    }
    else
    {
        item = q -> items[q -> front];
        (q -> front)++;

        if(q -> front > q -> rear)
            q -> front = q -> rear = -1;
    }
    return item;
}

void printQueue(Queue *q)
{
    if(isQueueEmpty(q))
        printf("Queue Overflow !\n");
    else
    {
        printf("FRONT");
        for(int i = q -> front; i < q-> rear+1; i++)
            printf(" -> %d", q -> items[i]);
        
        printf(" -> NULL\n");
    }
}

// Unweighted Undirected Graph Implementation
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

// Breadth First Search Function
void bfs(Graph *graph, int startVertex)
{
    Queue *q = createQueue();


    graph -> visited[startVertex] = 1;
    enQueue(q, startVertex);
    printf("Visited %d\n", startVertex);
    while(!isQueueEmpty(q))
    {
        int currVertex = deQueue(q);

        Node *currNode = graph -> array[currVertex].head;
        while(currNode != NULL)
        {
            int adjVertex = currNode -> dest;

            if(graph -> visited[adjVertex] == 0)
            {
                graph -> visited[adjVertex] = 1;
                printf("Visited %d\n", adjVertex);
                enQueue(q, adjVertex);
            }
            currNode = currNode -> link;
        }
    }
}

int main()
{
    int v = 7;
    Graph *graph = createGraph(v);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 0, 6);
    addEdge(graph, 4, 5);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 5);
    addEdge(graph, 5, 6);

    bfs(graph, 0);

    return 0;
}