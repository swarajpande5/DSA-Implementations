// Program to display intersection between two sets
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

    // Intersection Logic
    printf("Intersection : ");
    i = j = 0;
    while(i < sizeA && j < sizeB)
    {
        if(A[i] < B[j])
            i++;
        else if(A[i] > B[j])
            j++;
        else
        {
            printf("%d ", B[j]);
            i++;
            j++;
        }
    }
    
    return 0;
}