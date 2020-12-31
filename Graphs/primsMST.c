// Prims's Algorithm Implementation for Minimum Spanning Tree
#include <stdio.h>
#include <stdlib.h>

int **adjMat;
int nodes;

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

void prims()
{
    int edgeCount, minWeight, selected[nodes]; // Array to track selected vertex
    int x, y;   // row and column number

    // Setting selected[] to false
    for(int i = 0; i < nodes; i++)
        selected[i] = 0;

    edgeCount = 0;
    minWeight = 0;
    selected[0] = 1;

    printf("Prim's Minimum Spanning Tree: \n");
    printf("Edge \tWeight\n");
    while(edgeCount < nodes - 1)
    {
        int min = __INT_MAX__;
        x = 0;
        y = 0;

        for(int i = 0; i < nodes; i++)
        {
            if(selected[i])
            {
                for(int j = 0; j < nodes; j++)
                {
                    if(!selected[j] && adjMat[i][j])
                    {
                        if(min > adjMat[i][j])
                        {
                            min = adjMat[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        minWeight = minWeight + adjMat[x][y];
        printf("%d - %d \t%d \n", x, y, adjMat[x][y]);
        selected[y] = 1;
        edgeCount++;
    }
    printf("\nThe weight of MST is: %d\n", minWeight);
}

int main()
{
    printf("Enter number of nodes: ");
    scanf("%d", &nodes);

    makeAdjMat();
    printAdjMat();

    prims();

    free(adjMat);

    return 0;
}
