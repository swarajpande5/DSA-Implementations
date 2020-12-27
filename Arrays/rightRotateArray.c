// Program to right rotate an array
#include <stdio.h>

void rightRotate(int arr[], int size, int rotations)
{
    int last;
    for(int t = 0; t < rotations; t++)
    {
        last = arr[size - 1];
        for(int i = size - 1; i > 0; i--)
            arr[i] = arr[i - 1];
        
        arr[0] = last;
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

    printf("Enter number of right rotations: ");
    scanf("%d", &rotations);

    rightRotate(arr, size, rotations);

    printf("Array after %d right rotations: ", rotations);
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}