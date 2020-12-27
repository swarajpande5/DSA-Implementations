// Program for Heap Sort (ascending)
#include <stdio.h>
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void maxHeapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if(l < n && arr[l] > arr[largest])
        largest = l;
    if(r < n && arr[r] > arr[largest])
        largest = r;
    if(largest != i)
    {
        swap(&arr[i], &arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void buildMaxHeap(int arr[], int n)
{
    for(int i = n/2-1; i >= 0; i--)
        maxHeapify(arr, n , i);
}

void heapSort(int arr[], int n)
{
    buildMaxHeap(arr, n);
    for(int i = n - 1; i > 0; i--)
    {
        swap(&arr[0], &arr[i]);
        maxHeapify(arr, i, 0);
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

    heapSort(arr, size);

    printf("The sorted array is: ");
    for(i = 0; i < size; i++)
        printf("%d ", arr[i]);

    printf("\n");
return 0;
}