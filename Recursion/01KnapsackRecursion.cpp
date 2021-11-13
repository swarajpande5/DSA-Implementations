// 0-1 Knapsack problem using recursion
#include <bits/stdc++.h>
using namespace std;

int knapsack(int wt[], int val[], int W, int n)
{
    // Base case 
    if(n == 0 || W == 0)
        return 0;
    
    // Recursive cases 
    if(wt[n - 1] <= W)
        return max( val[n - 1] + knapsack(wt, val, W - wt[n - 1], n - 1), 
                    knapsack(wt, val, W, n - 1) );
    
    else if(wt[n - 1] > W)
        return knapsack(wt, val, W, n - 1);
    
    else 
        return -1;  // to avoid warning
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