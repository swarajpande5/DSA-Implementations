// Matrix Chain Multiplication 
#include <bits/stdc++.h>
using namespace std;

int solve(int arr[], int i, int j)
{
    // Base condition
    if(i >= j)
        return 0;

    int ans = INT_MAX;
    for(int k = i; k <= j - 1; k++)
    {
        int temp =  solve(arr, i, k) +                  // recursive call to compute cost of i to k 
                    solve(arr, k + 1, j) +              // recursive call to compute cost of k + 1 to j
                    arr[i - 1] * arr[k] * arr[j];       // the cost of multipliying the chosen two matrices

        ans = min(ans, temp);
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    cout << solve(arr, 1, n - 1) << "\n";               // calling the function keeping i -> 1 and j -> n - 1

    return 0;
}