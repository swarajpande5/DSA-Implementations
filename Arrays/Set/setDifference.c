// Program to display difference between two sets
#include <stdio.h>

int isPresent(int A[], int size, int value)
{
    if(size == 0)
        return 0;

    for(int i = 0; i < size; i++)
    {
        if(A[i] == value)
            return 1;
    }

    return 0;
}

int main()
{
    int sizeA, sizeB, A[100], B[100], C[100], i, j, k;
    
    printf("Enter size of set A: ");
    scanf("%d", &sizeA);
    printf("Enter size of set B: ");
    scanf("%d", &sizeB);

    printf("Enter elements of set A: ");
    for(i = 0; i < sizeA; i++)
        scanf("%d", &A[i]);
    printf("Enter elements of set B: ");
    for(i = 0; i < sizeB; i++)
        scanf("%d", &B[i]);

    // Difference Logic
    k = 0;
    for(i = 0; i < sizeA; i++)
    {
        if(!isPresent(B, sizeB, A[i]) && !isPresent(C, k, A[i]))
        {
            C[k] = A[i];
            k++;
        }
    }

    printf("Difference set A - set B is: ");
    for(i = 0; i < k; i++)
        printf("%d ", C[i]);
    printf("\n");

    return 0;
}