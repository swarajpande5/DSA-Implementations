// Unbounded Knapsack using bottom-up DP : https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1
#include <bits/stdc++.h>
using namespace std;

int unboundedKnapsack(int wt[], int val[], int W, int n)
{
    int t[n + 1][W + 1];        // DP matrix

    for(int i = 0; i < n + 1; i++)
    {
        for(int j = 0; j < W + 1; j++)
        {
            // Base case (Initialization)
            if(i == 0 || j == 0)
                t[i][j] = 0;

            else if(wt[i - 1] <= j)
            {
                // Note that this is unbounded knapsack, so multiple instances of same item
                // are allowed, hence t[i][j - wt[i - 1]] is added when the item is included 
                int val1 = val[i - 1] + t[i][j - wt[i - 1]];
                // If the item is excluded from the knapsack, it is never considered again, 
                // hence t[i - 1][j] is the value here.
                int val2 = t[i - 1][j];

                t[i][j] = max(val1, val2);
            }

            else if(wt[i - 1] > j)
                t[i][j] = t[i - 1][j];
        }
    }

    return t[n][W];
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

    cout << unboundedKnapsack(wt, val, W, n) << "\n";
    return 0;
}