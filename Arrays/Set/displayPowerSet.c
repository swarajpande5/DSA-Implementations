// Program to display power set elements of a set
#include <stdio.h>

int power(int base, int exp)
{
    int result = 1;
    
    for(int i = 0; i < exp; i++)
        result = result * base;
    
    return result;
}

int main()
{
    int size, A[100], powerSize, i, j;

    printf("Enter size of set: ");
    scanf("%d", &size);

    printf("Enter character elements of set: ");
    for(i = 0; i < size; i++)
    scanf("%d", &A[i]);

    // Power Set Logic
    powerSize = power(2, size);
    printf("Power set elements are: ");
    for(i = 0; i < powerSize; i++)
    {
        for(j = 0; j < size; j++)
        {
            if(i & (1<<j)) //Checking if ith bit is set using Bitwise Logic (Bitmasking)
                printf("%d ", A[j]);
        }
        printf("\n");
    }
    
    printf("Phi \n");
    return 0;
}