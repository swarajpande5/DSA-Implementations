// Program to check whether a square matrix is symmetric or not
#include <stdio.h>

int isSymmetric(int arr[][100], int size)
{
    int flag = 1;
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            if(arr[i][j] != arr[j][i])
            {
                flag = 0; 
                break;
            }
        }
        if(flag == 0)
            break;
    }
    
    return flag;
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

    if(isSymmetric(arr, size))
        printf("The matrix is symmetric. \n");
    else 
        printf("The matrix is not symmetric. \n");

    return 0;
}