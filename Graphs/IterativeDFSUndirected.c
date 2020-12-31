// Iterative DFS on Undirected Unweighted Graph
#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

// Stack Implementation for DFS
typedef struct Stack
{
    int items[SIZE];
    int top;
}Stack;

Stack *createStack()
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s -> top = -1;

    return s;
}

int isStackEmpty(Stack *s)
{
    if(s -> top == -1)
        return 1;
    else 
        return 0;
}

void push(Stack *s, int value)
{
    if(s -> top == SIZE -1)
        printf("Stack Overflow !\n");
    else 
    {
        s -> top++;
        s -> items[s -> top] = value;
    }
}

int pop(Stack *s)
{
    int item;
    if(isStackEmpty(s))
    {
        printf("Stack Underflow !\n");
        item = -1;
    }
    else 
    {
        item = s -> items[s -> top];
        s -> top--;
    }
    return item;
}

int peek(Stack *s)
{
    return s -> top;
}

void printStack(Stack *s)
{
    if(isStackEmpty(s))
        printf("Stack Underflow !\n");
    else
    {
        printf("TOP");
        for(int i = s -> top; i >= 0; i--)
            printf(" -> %d", s -> items[i]);

        printf("\n");
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

void dfs(Graph *graph, int startVertex)
{
    Stack *s = createStack();
    graph -> visited[startVertex] = 1;
    push(s, startVertex);
    
    while(!isStackEmpty(s))
    {
        int currVertex = pop(s);
        printf("Visited %d\n", currVertex);

        Node *currNode = graph -> array[currVertex].head;
        while(currNode != NULL)
        {
            int adjVertex = currNode -> dest;

            if(graph -> visited[adjVertex] == 0)
            {
                graph -> visited[adjVertex] = 1;
                push(s, adjVertex);
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
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 5);
    addEdge(graph, 2, 6);

    dfs(graph, 0);

    return 0;
}