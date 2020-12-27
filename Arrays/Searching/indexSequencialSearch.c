// Program for Index Sequential Search with a Slice of 30.
#include <stdio.h>
#define SLICE 30
void indexedSequencialSearch(int *arr, int size, int value)
{
    int elements[SLICE], indices[SLICE];
    int i, index = 0, start, end;
    int setFlag = 0, findFlag = 0;

    for(i = 0; i<size; i = i+3)
    {
        elements[index] = arr[i];
        indices[index] = i;
        index++;
    }
    if(value < elements[0])
    {
        printf("Element NOT Found\n");
        return;
    }
    else 
    {
        for(i = 1; i<index; i++)
        {
            if(value <= elements[i])
            {
                start = indices[i-1];
                end = indices [i];
                setFlag = 1;
                break;
            }
        }
    }

    if(setFlag == 0)
    {
        start = indices[i-1];
        end = size;
    }

    for(i = start; i<= end; i++)
    {
        if(value == arr[i])
        {
            findFlag = 1;
            break;
        }
    }

    if(findFlag)
        printf("Found at index %d\n", i);
    else 
        printf("Element NOT found\n");
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7};
    int size = sizeof(arr)/sizeof(arr[0]);

    indexedSequencialSearch(arr, size, 5);
    return 0;
}