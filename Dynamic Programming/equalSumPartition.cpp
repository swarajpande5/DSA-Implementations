// Equal sum partition (Subset sum and 0/1 Knapsack variation) : https://leetcode.com/problems/partition-equal-subset-sum/
#include <bits/stdc++.h>
using namespace std;

bool isSubsetSum(int arr[], int n, int sum)
{
    bool t[n + 1][sum + 1];             // DP matrix

    // Initialization 
    for(int i = 0; i < sum + 1; i++)
        t[0][i] = false;
    
    for(int i = 0; i < n + 1; i++)
        t[i][0] = true;
    
    // DP
    for(int i = 1; i < n + 1; i++)
    {
        for(int j = 1; j < sum + 1; j++)
        {
            if(arr[i - 1] <= j)
                t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j];      // either take or do not take
            
            else 
                t[i][j] = t[i - 1][j];                                  // do not take
        }
    }

    return t[n][sum];
}

bool equalPartition(int arr[], int n)
{
    // Calculating the sum of the array 
    int sum = accumulate(arr, arr + n, 0);

    // if sum is odd then it is not possible to make equal sum partitions
    if(sum % 2 != 0)
        return false;

    // when the sum is even, dividing the sum by two and applying the subset sum
    return isSubsetSum(arr, n, sum / 2);
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    cout << equalPartition(arr, n) << "\n";

    return 0;
}