// Program to display Union between two sets
#include <stdio.h>

int main()
{
    int i, j, sizeA, sizeB, A[100], B[100];

    printf("Enter size of set A and B respectively: ");
    scanf("%d%d", &sizeA, &sizeB);
    printf("Enter Set elements in ascending order.\n");

    printf("Enter elements of set A: ");
    for(i = 0; i < sizeA; i++)
        scanf("%d", &A[i]);
    printf("Enter elements of set B: ");
    for(i = 0; i < sizeB; i++)
        scanf("%d", &B[i]);
    
    // Union Logic
    printf("Union : ");
    i = j = 0;
    while(i < sizeA && j < sizeB)
    {
        if(A[i] < B[j])
        {
            printf("%d ", A[i]);
            i++;
        }
        else if(A[i] > B[j])
        {
            printf("%d ", B[j]);
            j++;
        }
        else
        {
            printf("%d ", B[j]);
            i++;
            j++;
        }
    }

    while(i < sizeA)
    {
        printf("%d ", A[i]);
        i++;
    }
    
    while(j < sizeB)
    {
        printf("%d ", B[j]);
        j++;
    }
    printf("\n");

    return 0;
}