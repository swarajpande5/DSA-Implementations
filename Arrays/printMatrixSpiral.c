// Program to print a given matrix in spiral form
#include <stdio.h>
void printSpiral(int a[][100], int m, int n)
{
    int i, k, l;
    
    k = l = 0;

    printf("The Matrix in Spiral form is: \n");
    while(k < m & l < n)
    {
        for(i = l; i < n; i++)
            printf("%d ", a[k][i]);
        
        k++;

        for(i = k; i < m; i++)
            printf("%d ", a[i][n - 1]);

        n--;

        if(k < m)
        {
            for(i = n - 1; i >= l; i--)
                printf("%d ", a[m - 1][i]);

            m--;
        }

        if(l < n)
        {
            for(i = m - 1; i >= k; i--)
                printf("%d ", a[i][l]);
            
            l++;
        }
    }
    printf("\n");   
}

int main()
{
    int a[100][100], m, n;
    printf("Enter sizes of the matrix (m & n): ");
    scanf("%d%d", &m, &n);

    printf("Enter matrix elements: \n");
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    }
    printSpiral(a, m, n);

    return 0;
}