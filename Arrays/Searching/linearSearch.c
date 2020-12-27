// Linear Search in an Array
#include <stdio.h>

void linearSearch(int *arr, int size, int ele)
{
    int i, flag;
    flag = 0;

    for(i = 0; i<size; i++)
    {
        if(arr[i] == ele)
        {
            printf("Element found at %d position\n", i+1);
            flag = 1;
        }
    }
    if(flag == 0)
        printf("Element NOT found\n");
}

void main()
{
    int arr[] = {1,2,3,4,5,7,7};
    int size = sizeof(arr)/sizeof(arr[0]);
    linearSearch(arr, size, 5);
}