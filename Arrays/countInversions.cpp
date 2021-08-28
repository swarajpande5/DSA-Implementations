// Count Inversions: https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1
#include <bits/stdc++.h>
using namespace std;

int getInvCountNaive(int arr[], int n)
{
    int count = 0;
    for(int i = 0; i < n - 1; i++)
        for(int j = i + 1; j < n; j++)
            if(arr[i] > arr[j])
                count++;

    return count;
}

// Optimized method using merge sort 
int merge(int arr[], int temp[], int left, int mid, int right)
{
    int i, j, k;
    int count = 0;

    i = left;
    j = mid;
    k = left;

    while((i <= mid - 1) && (j <= right))
    {
        if(arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else 
        {
            temp[k++] = arr[j++];
            count += (mid - i);
        }
    }

    while(i <= mid - 1)
        temp[k++] = arr[i++];
    
    while(j <= right)
        temp[k++] = arr[j++];
    
    for(int i = left; i <= right; i++)
        arr[i] = temp[i];
    
    return count;
}

int mergeSortUtil(int arr[], int temp[], int left, int right)
{
    int mid, count = 0;

    if(right > left)
    {
        mid = (right + left) / 2;

        count += mergeSortUtil(arr, temp, left, mid);
        count += mergeSortUtil(arr, temp, mid + 1, right);
        count += merge(arr, temp, left, mid + 1, right);
    }

    return count;
}

int mergeSort(int arr[], int n)
{
    int temp[n];
    return mergeSortUtil(arr, temp, 0, n - 1);
}

int main()
{
    int arr[] = { 8, 4, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << mergeSort(arr, n) << "\n";

    return 0;
}