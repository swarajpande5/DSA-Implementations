// Progran for Vector representation of sparse matrix
#include <stdio.h>
#define MAX 255

typedef struct Sparse
{
    int row;
    int col;
    int data;
}Sparse;

void printVectorSparse(int arr[][MAX], int m, int n)
{
    Sparse svec[MAX];
    int size = 0;

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(arr[i][j] != 0)
            {
                svec[size].row = i+1;
                svec[size].col = j+1;
                svec[size].data = arr[i][j];
                size++;
            }
        }
    }

    printf("\nVector Representation: \n");
    printf("Row\tColumn\tData\n");
    for(int i = 0; i < size; i++)
        printf("%d\t%d\t%d\n", svec[i].row, svec[i].col, svec[i].data);

}

int main()
{
    int arr[MAX][MAX], m, n;
    
    printf("Enter rows and columns: ");
    scanf("%d%d", &m, &n);

    printf("Enter sparse matrix elements: \n");
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
            scanf("%d", &arr[i][j]);
    }

    printVectorSparse(arr, m, n);

    return 0;
}