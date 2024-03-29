// Target sum (0/1 Knapsack and Subset sum variation) : https://leetcode.com/problems/target-sum/
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

// The target sum problem is same as that of "count subset sum difference"
int targetSum(int arr[], int n, int diff)
{
    // Calculating the sum of the array
    int sum = accumulate(arr, arr + n, 0);

    // Using the formula to check and return
    if((sum + diff) % 2 != 0)
        return 0;
    
    else 
        return countSubsetSum(arr, n, (sum + diff) / 2);
}

int main()
{
    int n; 
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int diff;
    cin >> diff;

    cout << targetSum(arr, n, diff) << "\n";

    return 0;
}


// Leetcode Problem: https://leetcode.com/problems/target-sum/
//                   https://leetcode.com/problems/target-sum/discuss/1174595/99-faster-oror-Using-DP-oror-Formula-explain

class Solution 
{
public:
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        
        int n = nums.size();
        target = abs(target);
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int diff = (sum + target) / 2;
        
        if(sum < target || (sum + target) % 2 != 0)
            return 0;
    
        vector<int> dp(diff + 1, 0);
        dp[0] = 1;
        
        for(int i = 0; i < n; i++)
            for(int j = diff; j >= nums[i]; j--)
                dp[j] += dp[j - nums[i]];
    
        return dp[diff];
    }
};