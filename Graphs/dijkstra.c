// Single Source Shortest Paths Implementation using Dijkstra's Algorithm

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

    // Setting every value in the matrix to be INF
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

int minDistance(int *dist, int *sptSet)
{
    int minIndex, min = INF;

    for(int i = 0; i < nodes; i++)
    {
        if(sptSet[i] == 0 && dist[i] <= min)
        {
            min = dist[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void dijkstra(int src)
{
    int dist[nodes], sptSet[nodes];
    
    // Initializing the arrays
    for(int i = 0; i < nodes; i++)
    {
        dist[i] = INF;
        sptSet[i] = 0;
    }

    dist[src] = 0;
    for(int i = 0; i < nodes - 1; i++)
    {
        int u = minDistance(dist, sptSet);
        sptSet[u] = 1;

        for(int v = 0; v < nodes; v++)
        {
            if( !sptSet[v] && adjMat[u][v] && dist[u] != INF
                && dist[u] + adjMat[u][v] < dist[v]  )
            {
                dist[v] = dist[u] + adjMat[u][v];
            }
        }
    }

    // Printing the distance array
    printf("Vertex \t\t Distance from Source\n"); 
    for (int i = 0; i < nodes; i++)
    {
        if(dist[i] == INF)
            printf("%d \t\t %s\n", i, "INF");
        else 
            printf("%d \t\t %d\n", i, dist[i]);
    }
}

int main()
{
    int src;

    printf("Enter number of nodes: ");
    scanf("%d", &nodes);

    makeAdjMat();
    printMat(adjMat, nodes);

    printf("Enter Source node: ");
    scanf("%d", &src);
    dijkstra(src);

    free(adjMat);

    return 0;
}