// Program to create transpose of a matrix (without a second matrix)
#include <stdio.h>

void transpose(int a[][100], int m, int n)
{
    int temp;
    for(int i = 0; i <= m; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            temp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = temp;
        }
    }
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
    transpose(a, m, n);

    printf("The Matrix after transposition is: \n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            printf("%4d", a[i][j]);

        printf("\n");
    }

    return 0;
}