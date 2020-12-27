// Deletion in an Array
#include <stdio.h>

int findElement(int arr[], int size, int ele)
{
    for(int i = 0; i < size; i++)
    {
        if(arr[i] == ele)
            return i;
    }
    return -1;
}

int deleteElement(int arr[], int size, int ele)
{
    int pos = findElement(arr, size, ele);

    if(pos == -1)
    {
        printf("Element not found. \n");
        return size;
    }

    for(int i = pos; i < size - 1; i++)
        arr[i] = arr[i + 1];

    return size - 1;
}

int main()
{
    int arr[100], size, ele;
    printf("Enter size: ");
    scanf("%d", &size);

    printf("Enter elements :");
    for(int i = 0; i < size; i++)
        scanf("%d", &arr[i]);

    printf("Enter element to be deleted: ");
    scanf("%d", &ele);

    size = deleteElement(arr, size, ele);

    printf("Array after deletion is: ");
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}