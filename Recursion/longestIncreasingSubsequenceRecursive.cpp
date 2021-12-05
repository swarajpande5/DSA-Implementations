// Longest Increasing Subsequence (Recursive)
#include <bits/stdc++.h>
using namespace std;

int LISUtil(int arr[], int n, int *max_ref)
{
    // Base case
    if(n == 1)
        return 1;
    
    // currMax is the length of LIS ending with arr[n-1]
    int res, currMax = 1;

    // Recursively getting all LIS ending with arr[0], arr[1], arr[2] ... arr[n - 2].
    // If arr[i - 1] is smaller than arr[n - 1], and currMax with arr[n - 1] needs to be updated, then updating it.
    for(int i = 1; i < n; i++)
    {
        res = LISUtil(arr, i, max_ref);
        
        if(arr[i - 1] < arr[n - 1] && res + 1 > currMax)
            currMax = res + 1;
    }

    // Comparing currMax with the overall max.
    // Then updating overall max if needed.
    if(*max_ref < currMax)
        *max_ref = currMax;
    
    // Returning length of LIS ending with arr[n - 1]
    return currMax;
}

int LIS(int arr[], int n)
{
    int max = 1;
    LISUtil(arr, n, &max);
    return max;
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