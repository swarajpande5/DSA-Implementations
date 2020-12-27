// Program to multiply two Matrices and display the result
#include <stdio.h>

int main()
{
    int a[100][100], b[100][100], c[100][100];
    int m, n, p, q;
    int i, j, k;

    printf("Enter sizes of first matrix (m & n): ");
    scanf("%d%d", &m, &n);
    printf("Enter sizes of second matrix (p & q): ");
    scanf("%d%d", &p, &q);

    printf("Enter elements of first matrix: \n");
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    }

    printf("Enter elements of second matrix: \n");
    for(i = 0; i < p; i++)
    {
        for(j = 0; j < q; j++)
            scanf("%d", &b[i][j]);
    }

    // Matrix Multiplication logic
    if(n == p)
    {
        for(i = 0; i < m; i++)
        {
            for(j = 0; j < q; j++)
            {
                c[i][j] = 0;
                for(k = 0; k < p; k++)
                    c[i][j] = c[i][j] + a[i][k]*b[k][j];
            }
        }

        printf("After Multiplication: \n");
        for(i = 0; i < m; i++)
        {
            for(j = 0; j < q; j++)
                printf("%4d", c[i][j]);

            printf("\n");
        }
    }
    else 
        printf("Matrix multiplication cannot be performed.\n");

    return 0;
}