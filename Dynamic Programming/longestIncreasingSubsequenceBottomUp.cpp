// Longest Increasing Subsequence (Bottom Up DP) : https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1
#include <bits/stdc++.h>
using namespace std;

int LIS(int arr[], int n)
{
    int lis[n];         // DP matrix (array)

    lis[0] = 1;

    // Computing LIS values in bottom up fashion
    for(int i = 1; i < n; i++)
    {
        lis[i] = 1;
        for(int j = 0; j < i; j++)
        {
            if(arr[i] > arr[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;
        }
    }

    // Returning maximum value in lis[]
    return *max_element(lis, lis + n);
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    cout << LIS(arr, n) << "\n";

    return 0;
}