// Count of subset sum (Subset sum and 0-1 Knapsack variation) : https://practice.geeksforgeeks.org/problems/perfect-sum-problem5633/1
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

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int sum;
    cin >> sum;

    cout << countSubsetSum(arr, n, sum) << "\n";

    return 0;
}