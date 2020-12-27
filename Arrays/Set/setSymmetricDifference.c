// Program to display Symmetric Difference between two sets
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

    // Symmetric difference Logic
    printf("The Symmetric difference of the sets is: ");
    i = j = 0;

    while(i <= sizeA && j <= sizeB)
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
            i++;
            j++;
        }
    }
    printf("\n");

    return 0;
}