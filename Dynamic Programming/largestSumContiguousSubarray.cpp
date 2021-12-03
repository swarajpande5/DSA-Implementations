// Largest Sum Contiguous Subarray (using DP) : https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1
#include <bits/stdc++.h>
using namespace std;

int maxSubarraySum(int arr[], int n)
{
    int maxSum = arr[0];
    int currMaxSum = arr[0];

    for(int i = 1; i < n; i++)
    {
        currMaxSum = max(arr[i], currMaxSum + arr[i]);
        maxSum = max(maxSum, currMaxSum);
    }

    return maxSum;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    cout << maxSubarraySum(arr, n) << "\n";

    return 0;
}