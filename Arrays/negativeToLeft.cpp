// Move all negative numbers to left side of array
#include <bits/stdc++.h>
using namespace std;

void swap(int *x, int *y)
{
    *x = *x ^ *y;
    *y = *x ^ *y;
    *x = *x ^ *y;
}

void moveNegativeTwoPointer(int arr[], int left, int right)
{
    while(left <= right)
    {
        if(arr[left] < 0 && arr[right] < 0)
            left++;
        
        else if(arr[left] > 0 && arr[right] < 0)
        {
            swap(&arr[left], &arr[right]);
            left++;
            right--;
        }

        else if(arr[left] > 0 && arr[right] > 0)
            right--;
        
        else 
        {
            left++;
            right--;
        }
    }
}

void moveNegativePartition(int arr[], int n)
{
    int j = 0;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] < 0)
        {
            if(i != j)
                swap(&arr[i], &arr[j]);
            
            j++;
        }
    }
}

int main()
{
    int arr[] = {-1, -2, 3, 4, 5, -6, -7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    // moveNegativePartition(arr, n);
    moveNegativeTwoPointer(arr, 0, n - 1);

    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";

    return 0;
}