// Program to display Cartesian product between two sets
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

    // Cartesian Product Logic
    printf("The Cartesian product of the sets is: ");
    for(i = 0; i < sizeA; i++)
    {
        for(j = 0; j < sizeB; j++)
            printf("(%d,%d) ", A[i], B[j]);
    }
    printf("\n");

    return 0;
}