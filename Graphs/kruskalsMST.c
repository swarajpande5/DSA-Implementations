// Kruskal's Algorithm Implementation for Minimum Spanning Tree
#include <stdio.h>
#include <stdlib.h>

// Structure for a single edge
typedef struct Edge
{
    int origin;
    int dest;
    int weight;
}Edge;

// Structure for an array of 'edge'
typedef struct EdgeList
{
    Edge *edgeArray;
    int size;
}EdgeList;


int **adjMat;
int nodes;
EdgeList list, spanTree;

// Function to make Adjacency Matrix
void makeAdjMat()
{
    int maxEdges, origin, dest, weight;
    
    // Allocating 2D array
    adjMat = (int **)malloc(nodes * sizeof(int *));
    for(int i = 0; i < nodes; i++)
        adjMat[i] = (int *)malloc(nodes * sizeof(int));

    // Calcualting max edges for Undirected Weighted 
    maxEdges = nodes*(nodes-1)/2;

    printf("Enter edges with weight (-1 -1 -1 to quit): \n");
    for(int i = 1; i <= maxEdges; i++)
    {
        scanf("%d%d%d", &origin, &dest, &weight);

        if(origin == -1 && dest == -1 && weight == -1)
            break;
        if(origin >= nodes || dest >= nodes || origin < 0 || dest < 0)
        {
            printf("Invalid Edge \n");
            i--;
        }
        else
        {
            adjMat[origin][dest] = weight;
            adjMat[dest][origin] = weight;
        }
    }
}

// Function to allocate edgeArrays of 'list' and 'spanTree'
void initList()
{
    list.edgeArray = (Edge *)malloc(2 * nodes * sizeof(Edge));
    spanTree.edgeArray = (Edge *)malloc(2 * nodes * sizeof(Edge));
}

// Find function 
int find(int nodeSet[], int node)
{
    return nodeSet[node];
}

// Union function
void setUnion(int nodeSet[], int x, int y)
{
    for(int i = 0; i < nodes; i++)
    {
        if(nodeSet[i] == y)
            nodeSet[i] = x;
    }
}

// Sort function to sort edges in 'list'
void sort()
{
    Edge temp;
    for(int i = 0; i < list.size; i++)
    {
        for(int j = 0; j < list.size - 1; j++)
        {
            if(list.edgeArray[j].weight > list.edgeArray[j + 1].weight)
            {
                temp = list.edgeArray[j];
                list.edgeArray[j] = list.edgeArray[j + 1];
                list.edgeArray[j + 1] = temp;
            }
        }
    }
}

// kruskal's algorithm for finding Minimum Spanning Tree 'spanTree'
void kruskal()
{
    initList();
    int *nodeSet = (int *)malloc(nodes * sizeof(int));
    int x, y;

    list.size = 0;
    
    for(int i = 0; i < nodes; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(adjMat[i][j] != 0)
            {
                list.edgeArray[list.size].origin = i;
                list.edgeArray[list.size].dest = j;
                list.edgeArray[list.size].weight = adjMat[i][j];

                list.size++;
            }
        }
    }

    // Sorting edges according to their weight
    sort();

    // Initializing the disjoint 'nodeSet'
    for(int i = 0; i < nodes; i++)
        nodeSet[i] = i;
    
    spanTree.size = 0;

    for(int i = 0; i < list.size; i++)
    {
        x = find(nodeSet, list.edgeArray[i].origin);
        y = find(nodeSet, list.edgeArray[i].dest);

        if(x != y)
        {
            spanTree.edgeArray[spanTree.size] = list.edgeArray[i];
            spanTree.size++;
            setUnion(nodeSet, x, y);
        }
    }
    
    free(nodeSet);
    free(list.edgeArray);
}

// Function to print Adjacency Matrix
void printAdjMat()
{
    printf("\nThe adjacency matrix of the graph is: \n");
    for(int i = 0; i < nodes; i++)
    {
        for(int j = 0; j < nodes; j++)
            printf("%4d", adjMat[i][j]);
        printf("\n");
    }
    printf("\n");
}

void printKruskalMST()
{
    int totalWeight = 0;
    int origin, dest, weight;

    printf("Kruskal's Minimum Spanning Tree: \n");
    printf("Edge \tWeight");
    for(int i = 0; i < spanTree.size; i++)
    {
        origin = spanTree.edgeArray[i].origin;
        dest = spanTree.edgeArray[i].dest;
        weight = spanTree.edgeArray[i].weight;
        printf("\n%d - %d\t%d", origin, dest, weight);

        totalWeight = totalWeight + weight;
    }
    printf("\nThe weight of MST is: %d\n", totalWeight);
}

int main()
{
    printf("Enter number of nodes: ");
    scanf("%d", &nodes);

    makeAdjMat();
    printAdjMat();

    kruskal();
    printKruskalMST();


    free(spanTree.edgeArray);
    return 0;
}