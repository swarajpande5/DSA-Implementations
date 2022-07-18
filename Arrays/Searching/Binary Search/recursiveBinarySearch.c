// Binary Search in an Array using Recursion (Recursive)
#include <stdio.h>

// This function will return the index of the found element
int recursiveBinarySearch(int *arr, int first, int last, int value)
{
    int mid;
    if(first <= last)
    {
        mid = first + (last-first)/2;

        if(arr[mid] > value)
            return recursiveBinarySearch(arr, first, mid-1, value);
        
        else if(arr[mid] < value)
            return recursiveBinarySearch(arr, mid+1, last, value);
        
        else if(arr[mid] == value)
            return mid;
    }

    return -1;
}

int main()
{
    int arr[] = {1,2,3,4,5,7,7};
    int size = sizeof(arr)/sizeof(arr[0]);
    int pos = recursiveBinarySearch(arr, 0, size-1, 5);
    printf("%d\n", pos);
}