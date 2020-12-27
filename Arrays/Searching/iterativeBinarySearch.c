// Binary Search in an Array using Loop (Iterative)
#include <stdio.h>

void iterativeBinarySearch(int *arr, int first, int last, int value)
{
    int mid, flag = 0;
    while(first <= last)
    {
        mid = first + (last-first)/2;

        if(arr[mid] > value)
            last = mid - 1;
        
        else if(arr[mid] < value)
            first = mid + 1;
        
        else if(arr[mid] == value)
        {
            flag = 1;
            printf("Element found at %d position \n", mid + 1);
            break;
        }
    }
    if(flag == 0)
        printf("Element NOT found \n");
}

int main()
{
    int arr[] = {1,2,3,4,5,7,7};
    int size = sizeof(arr)/sizeof(arr[0]);
    iterativeBinarySearch(arr, 0, size-1, 5);
}