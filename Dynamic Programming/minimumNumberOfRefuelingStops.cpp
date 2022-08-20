// Minimum number of refueling stops: https://leetcode.com/problems/minimum-number-of-refueling-stops/

class Solution 
{
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) 
    {
        int n = stations.size();
        
        // dp[i][j] = Maximum distance reached if I stopped at 'j' fuelstops from total of 'i' fuelStops
        vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, 0));
        
        
        // If j = 0, i.e. I did not use any fuelStops, Then maximum distance reachable is 'startFuel' 
        // Hence, initializing the array based on this information.
        
        for(int i = 0; i < n + 1; i++)
            dp[i][0] = startFuel;
        
        for(int i = 1; i < n + 1; i++)
        {
            for(int j = 1; j <= i; j++)
            {
                // Case 1: If I don't refuel at current stop, then the max distance I can cover is
                // equal to the maximum distance I could cover from previous state.
                dp[i][j] = dp[i - 1][j];
                
                // Case 2: I wll refuel at the current fuelstop, but checking 
                // if I can even reach this station or not from previous station
                if(dp[i - 1][j - 1] >= stations[i - 1][0])
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + stations[i - 1][1]);
            }
        }
        
        // After the calculation, check which dp[n][j] was best for reaching target.
        // That maens, the best minimum j used which reaches at least target.
        for(int j = 0; j < n + 1; j++)
            if(dp[n][j] >= target)
                return j;
        
        // If cannot reach then return -1
        return -1;
    }
};