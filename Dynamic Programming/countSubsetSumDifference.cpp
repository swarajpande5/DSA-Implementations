// Count the number of subset with a given difference (0/1 Knapsack and Subset sum variation)
/*
    Given an array and a difference, we need to find how many possible partitioning is possible
    such that the difference between the sum of the two partitions is equal to the given difference.
*/

#include <bits/stdc++.h>
using namespace std;

int countSubsetSum(int arr[], int n, int sum)
{
    int t[n + 1][sum + 1];             // DP matrix

    // Initialization 
    for(int i = 0; i < sum + 1; i++)
        t[0][i] = 0;
    
    for(int i = 0; i < n + 1; i++)
        t[i][0] = 1;
    
    // DP
    for(int i = 1; i < n + 1; i++)
    {
        for(int j = 1; j < sum + 1; j++)
        {
            if(arr[i - 1] <= j)
                t[i][j] = t[i - 1][j - arr[i - 1]] + t[i - 1][j];      // either take or do not take
            
            else 
                t[i][j] = t[i - 1][j];                                  // do not take
        }
    }

    return t[n][sum];
}

int countSubsetDifference(int arr[], int n, int diff)
{
    // Calculating the sum of the array
    int sum = accumulate(arr, arr + n, 0);

    // Using the formula to check and return
    if((sum + diff) % 2 != 0)
        return 0;
    
    else 
        return countSubsetSum(arr, n, (sum + diff) / 2);
}

int main()
{
    int n; 
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int diff;
    cin >> diff;

    cout << countSubsetDifference(arr, n, diff) << "\n";

    return 0;
}