// 0-1 Knapsack problem using memoization 
#include <bits/stdc++.h>
using namespace std;

const int n = 100, W = 1000;        // Constraints 
int t[n + 2][W + 2];                // DP Matrix

int knapsack(int wt[], int val[], int W, int n)
{
    // Base case 
    if(n == 0 || W == 0)
        return 0;
    
    // If already calculated the value, then return it 
    if(t[n][W] != -1)
        return t[n][W];
    
    // else calculate in the recursive calls
    else 
    {
        if(wt[n - 1] <= W)
            return t[n][W] = max(val[n - 1] + knapsack(wt, val, W - wt[n - 1], n - 1), 
                                knapsack(wt, val, W, n - 1));
        
        else if(wt[n - 1] > W)
            return t[n][W] = knapsack(wt, val, W, n - 1);
        
        else 
            return -1;  // To avoid warning
    }
}

int main()
{
    int n;      
    cin >> n;
    int wt[n], val[n];
    for(int i = 0; i < n; i++)
        cin >> wt[i];
    for(int i = 0; i < n; i++)
        cin >> val[i];
    int W;
    cin >> W;

    // Initializing the DP Matrix with -1
    memset(t, -1, sizeof(t));

    cout << knapsack(wt, val, W, n) << "\n";
    return 0;
}