// Program to delete a root in Heap 
// This insertion works for both (Min and Max) heaps.
#include <stdio.h>

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void maxHeapify(int arr[], int size, int i)
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    // If left child is larger than root
    if(l < size && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than root    
    if(r < size && arr[r] > arr[largest])
        largest = r;
    
    // If largest is not root, then swap
    if(largest != i)
    {
        swap(&arr[i], &arr[largest]);

        // Heapifying the subtree (recursively)
        maxHeapify(arr, size, largest);
    }
}

void buildMaxHeap(int arr[], int size)
{
    int startIndex = (size/2) - 1;
    
    // Reverse level order traversal
    for(int i = startIndex; i >= 0; i--)
        maxHeapify(arr, size, i);
}

void printMaxHeap(int arr[], int size)
{
    printf("Array representation of Max-Heap is: ");
    for(int i = 0; i < size; ++i)
        printf("%d ", arr[i]);
    
    printf("\n");
}

/*
    This function will return the decremented size 
    of the heap array after the deletion.
*/
int deletionHeap(int arr[], int size)
{
    int lastEle = arr[size - 1];
    arr[0] = lastEle;
    size--;
    maxHeapify(arr, size, 0);

    return size;
}

int main()
{
    int arr[100], size, ele;

    printf("Enter size: ");
    scanf("%d", &size);

    printf("Enter array elements: ");
    for(int i = 0; i < size; i++)
        scanf("%d", &arr[i]);

    buildMaxHeap(arr, size);
    printMaxHeap(arr, size);

    printf("Element after the root deletion is: ");

    size = deletionHeap(arr, size);

    printMaxHeap(arr, size);

    return 0;
}