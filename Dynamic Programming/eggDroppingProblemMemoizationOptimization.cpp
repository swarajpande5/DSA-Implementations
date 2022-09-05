// Egg dropping problem memoization (optimized)

#include <bits/stdc++.h>
using namespace std;

const int D = 101;
int dp[D][D];

int solve(int eggs, int floors)
{
    if(dp[eggs][floors] != -1)
        return dp[eggs][floors];

    if(eggs == 1 || floors == 0 || floors == 1)
        return dp[eggs][floors] = floors;
    
    int mn = INT_MAX;
    for(int k = 1; k <= floors; k++)
    {
        int top, bottom;
        
        if(dp[eggs - 1][k - 1] != -1)
            top = dp[eggs - 1][k - 1];
        else 
        {
            top = solve(eggs - 1, k - 1);
            dp[eggs - 1][k - 1] = top;
        }

        if(dp[eggs][floors - k] != -1)
            bottom = dp[eggs][floors - k];
        else 
        {
            bottom = solve(eggs, floors - k);
            dp[eggs][floors - k] = bottom;
        }

        int temp = 1 + max(top, bottom);
        mn = min(mn, temp);
    }

    return dp[eggs][floors] = mn;
}

int main()
{
    int eggs, floors;
    cin >> eggs >> floors;

    memset(dp, -1, sizeof(dp));

    cout << solve(eggs, floors) << endl;

    return 0;
}

// Super Egg Drop: https://leetcode.com/problems/super-egg-drop/
// Most Optimal Solution 
class Solution 
{
public:
    
    static const int maxEggs = 101; 
    static const int maxFloors = 10001;
    
    int dp[maxEggs][maxFloors];
    
    int solve(int eggs, int floors)
    {
        if(dp[eggs][floors] != -1)
            return dp[eggs][floors]; 
        
        // Base condition 
        if(eggs == 1 || floors == 0 || floors == 1)
        {
            dp[eggs][floors] = floors;
            return dp[eggs][floors];
        }
        
        // Binary Search + DP Approach
        int mn = INT_MAX;
        int low = 1;
        int high = floors; 
        
        while(low <= high)
        {
            int mid = low + (high - low) / 2; 
            
            int eggBreaks = solve(eggs - 1, mid - 1); 
            int eggNotBreaks = solve(eggs, floors - mid); 
            
            int temp = 1 + max(eggBreaks, eggNotBreaks);
            mn = min(mn, temp); 
            
            if(eggBreaks > eggNotBreaks)
                high = mid - 1; 
            else 
                low = mid + 1;
        }
        
        return dp[eggs][floors] = mn;
    }
    
    int superEggDrop(int k, int n) 
    {
        memset(dp, -1, sizeof dp); 
        return solve(k, n);
    }
};