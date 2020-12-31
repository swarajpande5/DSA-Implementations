// Floyd Warshall Algorithm Implementation for All pairs shortest paths
#include <stdio.h>
#include <stdlib.h>
#define INF 99999

int **adjMat;
int nodes;

void makeAdjMat()
{
    int maxEdges, origin, dest, weight;
    
    // Allocating 2D array
    adjMat = (int **)malloc(nodes * sizeof(int *));
    for(int i = 0; i < nodes; i++)
        adjMat[i] = (int *)malloc(nodes * sizeof(int));

    // Setting every value in the matrix to be __INT_MAX__ i.e. INF
    for(int i = 0; i < nodes; i++)
    {
        for(int j = 0; j < nodes; j++)
        {
            if(i!=j)
                adjMat[i][j] = INF;
        }
    }

    // Calcualting max edges for directed weighted 
    maxEdges = nodes*(nodes-1);

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
            adjMat[origin][dest] = weight;
        
    }
}

void printMat(int **mat, int nodeSize)
{
    printf("\nThe matrix is: \n");
    for(int i = 0; i < nodeSize; i++)
    {
        for(int j = 0; j < nodeSize; j++)
        {
            if(mat[i][j] == INF)
                printf("%4s", "INF");
            else 
                printf("%4d", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void floydWarshall(int **adjMat, int nodes)
{
    int **dist;
    dist = (int **)malloc(nodes * sizeof(int *));
    for(int i = 0; i < nodes; i++)
        dist[i] = (int *)malloc(nodes * sizeof(int));

    // Initializing the solution matrix same as the adjacency Matrix
    for(int i = 0; i < nodes; i++)
    {
        for(int j = 0; j < nodes; j++)
            dist[i][j] = adjMat[i][j];
    }

    for(int k = 0; k < nodes; k++)
    {
        for(int i = 0; i < nodes; i++)
        {
            for(int j = 0; j < nodes; j++)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j]) 
                    dist[i][j] = dist[i][k] + dist[k][j]; 
            }
        }
    }

    printMat(dist, nodes);
    free(dist);
}


int main()
{
    printf("Enter number of nodes: ");
    scanf("%d", &nodes);

    makeAdjMat();
    printMat(adjMat, nodes);

    floydWarshall(adjMat, nodes);

    free(adjMat);
}