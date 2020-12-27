// Program for Selection Sort (ascending)
#include <stdio.h>

int selectionSort(int arr[], int size)
{
    int i, j, t, min;
    for(i = 0; i < size - 1; i++)
    {
        min = i;
        for(j = i; j < size; j++)
        {
            if(arr[j] < arr[min])
                min = j;
        }
        if(i != min)
        {
            t = arr[i];
            arr[i] = arr[min];
            arr[min] = t;
        }
    }
}

int main()
{
    int arr[100], size, i;
    printf("Enter size: ");
    scanf("%d", &size);
    printf("Enter array elements: ");
    for(i = 0; i < size; i++)
        scanf("%d", &arr[i]);

    selectionSort(arr, size);
    printf("The sorted array is: ");
    for(i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}