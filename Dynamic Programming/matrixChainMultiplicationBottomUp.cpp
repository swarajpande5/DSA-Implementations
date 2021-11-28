// Matrix Chain Multiplication (Bottom Up DP)
#include <bits/stdc++.h>
using namespace std;

int mcm(int arr[], int n)
{
    int t[n][n];
    /*
    t[i][j] = Minimum number of scalar multiplications needed to compute the 
    matrix A[i]A[i+1]...A[j] = A[i...j] where dimension of A[i] is arr[i-1] X a[i].
    */

    // Cost is zero when multiplying one matrix 
    for(int i = 1; i < n; i++)
        t[i][i] = 0;
    
    // L is the chain length 
    for(int L = 2; L < n; L++)
    {
        for(int i = 1; i < n - L + 1; i++)
        {
            int j = i + L - 1;
            t[i][j] = INT_MAX;

            for(int k = i; k <= j - 1; k++)
            {
                int temp = t[i][k] + t[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                t[i][j] = min(temp, t[i][j]);
            }
        }
    }

    return t[1][n - 1];
}

int mcmEfficient(int arr[], int n)
{
    int t[n][n];
    /*
    t[i][j] = Minimum number of scalar multiplications needed to compute the 
    matrix A[i]A[i+1]...A[j] = A[i...j] where dimension of A[i] is arr[i-1] X a[i].
    */

    // Cost is zero when multiplying one matrix 
    for(int i = 1; i < n; i++)
        t[i][i] = 0;
    
    // Following the recursive formula
    // L is the chain length 
    for(int L = 1; L < n - 1; L++)
    {
        for(int i = 1; i < n - L; i++)
        {
            t[i][i + L] = min(
                t[i + 1][i + L] + arr[i - 1] * arr[i] * arr[i + L],
                t[i][i + L - 1] + arr[i - 1] * arr[i + L - 1] * arr[i + L]
            );
        }
    }

    return t[1][n - 1];
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    // cout << mcm(arr, n) << "\n";
    cout << mcmEfficient(arr, n) << "\n";
    
    return 0;
}