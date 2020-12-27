// Program to delete duplicate elements from an Array
#include <stdio.h>

int deleteDuplicates(int arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = i + 1; j < size; j++)
        {
            if(arr[i] == arr[j])
            {
                for(int k = j; k < size - 1; k++)
                    arr[k] = arr[k + 1];

                size--;
                j--;
            }
        }
    }
    return size;
}

int main()
{
    int arr[100], size;
    
    printf("Enter size: ");
    scanf("%d", &size);

    printf("Enter array elements: ");
    for(int i = 0; i < size; i++)
        scanf("%d", &arr[i]);

    size = deleteDuplicates(arr, size);

    printf("Array after deleting duplicates: ");
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}