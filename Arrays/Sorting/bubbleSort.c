// Program for Bubble Sort (ascending)
#include <stdio.h>

void bubbleSort(int arr[], int size)
{
    int i, j, t;
    for(i = 0; i < size; i++)
    {
        for(j = 0 ; j < size-i-1; i++)
        {
            if(arr[j] > arr[j + 1])
            {
                t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
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
    
    bubbleSort(arr, size);

    printf("The sorted array is: ");
    for(i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
return 0;
}