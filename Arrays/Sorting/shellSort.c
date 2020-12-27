// Program for Shell Sort (ascending)
#include <stdio.h>

void shellSort(int arr[], int size)
{
    int i, j, gap, temp;
    for(gap = size/2; gap > 0; gap = gap / 2)
    {
        for(i = gap; i < size; i++)
        {
            temp = arr[i];
            
            for(j = i; j >= gap && arr[j - gap] > temp; j = j - gap)
                arr[j] = arr[j - gap];

            arr[j] = temp;
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
    
    shellSort(arr, size);

    printf("The sorted array is: ");
    for(i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
return 0;
}