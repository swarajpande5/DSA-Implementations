// Program for Insertion Sort (ascending)
#include <stdio.h> 

void insertionSort(int arr[], int size)
{
    int i, j, t;
    for(i = 0; i< size - 1; i++)
    {
        j = i + 1;
        while(j > 0 && arr[j] < arr[j - 1])
        {
            t = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = t;
            j--;
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

    insertionSort(arr, size);
    
    printf("The sorted array is: ");
    for(i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}