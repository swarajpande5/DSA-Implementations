// Program to Right rotate a square matrix
#include <stdio.h>

void rightRotateMat(int arr[][100], int size, int rotations)
{
    int temp;
    for(int t = 0; t < rotations; t++)
    {
        for(int i = 0; i < size/2; i++)
        {
            for(int j = i; j < size-1-i; j++)
            {
                temp = arr[i][j];
                arr[i][j] = arr[size-1-j][i];
                arr[size-1-j][i] = arr[size-1-i][size-1-j];
                arr[size-1-i][size-1-j] = arr[j][size-1-i];
                arr[j][size-1-i] = temp;
            }
        }
    }
}

int main()
{
    int arr[100][100], size, rotations;
    
    printf("Enter size of square matrix: ");
    scanf("%d", &size);

    printf("Enter matrix elements: \n");
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
            scanf("%d", &arr[i][j]);
    }

    printf("Enter number of right rotations: ");
    scanf("%d", &rotations);

    rightRotateMat(arr, size, rotations);

    printf("Matrix after %d right rotations: \n", rotations);
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
            printf("%4d", arr[i][j]);
        printf("\n");
    }

    return 0;
}