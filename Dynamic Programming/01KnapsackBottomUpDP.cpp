// 0-1 Knapsack problem using bottom-up dynamic programming 
#include <bits/stdc++.h>
using namespace std; 

int knapsack(int wt[], int val[], int W, int n)
{
    int t[n + 1][W + 1];            // DP matrix

    for(int i = 0; i < n + 1; i++)
    {
        for(int j = 0; j < W + 1; j++)
        {
            // Base case
            if(i == 0 || j == 0)
                t[i][j] = 0;
            
            // Current weight can fit in the knapsack
            else if(wt[i - 1] <= j)
            {
                // taking the current weight
                int val1 = val[i - 1] + t[i - 1][j - wt[i - 1]];
                // skipping the current weight
                int val2 = t[i - 1][j];
                
                t[i][j] = max(val1, val2);
            }

            // Current weight cannot fit in the knapsack
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

    cout << knapsack(wt, val, W, n) << "\n";
    return 0;
}