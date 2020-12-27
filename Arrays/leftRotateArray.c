// Program to left rotate an array
#include <stdio.h>

void leftRotate(int arr[], int size, int rotations)
{
    int first;
    for(int t = 0; t < rotations; t++)
    {
        first = arr[0];
        for(int i = 0; i < size - 1; i++)
            arr[i] = arr[i + 1];
        
        arr[size - 1] = first;
    }
}

int main()
{
    int arr[100], size, rotations;
    
    printf("Enter size: ");
    scanf("%d", &size);

    printf("Enter array elements: ");
    for(int i = 0; i < size; i++)
        scanf("%d", &arr[i]);

    printf("Enter number of left rotations: ");
    scanf("%d", &rotations);

    leftRotate(arr, size, rotations);

    printf("Array after %d left rotations: ", rotations);
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}