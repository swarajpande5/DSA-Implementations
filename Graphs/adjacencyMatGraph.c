// Graph Implementation (Adjacency Matrix)

#include <stdio.h>
#define MAX 50
#define INF 99999

int adjMat[MAX][MAX];
int nodes;

int main()
{
    int maxEdges, i, j, origin, dest, weight;
    char graphType, weighted;

    printf("Enter number of nodes in graph: ");
    scanf("%d", &nodes);
    printf("Enter type of graph, undirected or directed (u/d): ");
    scanf(" %c", &graphType);
    printf("Is the graph type weighted or not (y/n): ");
    scanf(" %c", &weighted);

    if(graphType == 'u')
        maxEdges = nodes*(nodes-1)/2;
    else 
        maxEdges = nodes*(nodes-1);


    if(weighted == 'y')
    {
        // Setting every value in the matrix to be INF
        for(i = 0; i < nodes; i++)
        {
            for(j = 0; j < nodes; j++)
            {
                if(i != j)
                adjMat[i][j] = INF;
            }
        }

        for(i = 1; i <= maxEdges; i++)
        {
            printf("Enter edge %d (-1 -1 -1 to Quit): ", i);
            scanf("%d%d%d", &origin, &dest, &weight);

            if(origin == -1 && dest == -1 && weight == -1)
                break;
            if(origin > nodes || dest > nodes || origin < 0 || dest < 0 || weight < 0)
            {
                printf("Invalid Edge \n");
                i--;
            }
            else
            {
                adjMat[origin][dest] = weight;
                if(graphType == 'u')
                    adjMat[dest][origin] = weight;
            }
        }

    }

    if(weighted == 'n')
    {
        for(i = 1; i <= maxEdges; i++)
        {
            printf("Enter edge %d (-1 -1 to Quit): ", i);
            scanf("%d%d", &origin, &dest);

            if(origin == -1 && dest == -1)
                break;
            if(origin > nodes || dest > nodes || origin < 0 || dest < 0)
            {
                printf("Invalid Edge \n");
                i--;
            }
            else
            {
                adjMat[origin][dest] = 1;
                if(graphType == 'u')
                    adjMat[dest][origin] = 1;
            }
        }
    }

    printf("The adjacency matrix of the graph is: \n");
    for(i = 0; i < nodes; i++)
    {
        for(j = 0; j < nodes; j++)
            if(adjMat[i][j] == INF)
                printf("%4s", "INF");
            else 
                printf("%4d", adjMat[i][j]);
        printf("\n");
    }

    return 0;
}