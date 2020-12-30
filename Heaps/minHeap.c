// Program to build Min-heap from an array
#include <stdio.h>

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(int arr[], int size, int i)
{
    int smallest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    // If left child is smaller than root
    if(l < size && arr[l] < arr[smallest])
        smallest = l;

    // If right child is smaller than root    
    if(r < size && arr[r] > arr[smallest])
        smallest = r;
    
    // If smallest is not root, then swap
    if(smallest != i)
    {
        swap(&arr[i], &arr[smallest]);

        // Heapifying the subtree (recursively)
        minHeapify(arr, size, smallest);
    }
}

void buildMinHeap(int arr[], int size)
{
    int startIndex = (size/2) - 1;
    
    // Reverse level order traversal
    for(int i = startIndex; i >= 0; i--)
        minHeapify(arr, size, i);
}

void printMinHeap(int arr[], int size)
{
    printf("Array representation of Min-Heap is: ");
    for(int i = 0; i < size; ++i)
        printf("%d ", arr[i]);
    
    printf("\n");
}

int main()
{
    int arr[100], size;

    printf("Enter size: ");
    scanf("%d", &size);

    printf("Enter array elements: ");
    for(int i = 0; i < size; i++)
        scanf("%d", &arr[i]);

    buildMinHeap(arr, size);
    printMinHeap(arr, size);

    return 0;
}