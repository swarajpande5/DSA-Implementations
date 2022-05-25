// Russian Doll Envelopes: https://leetcode.com/problems/russian-doll-envelopes/
/*
    Intuition:  This question is a variation of Longest Increasing Subsequence problem
*/

// LIS Solution (T.C O(n ^ 2))
class LISSolution 
{
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) 
    {
        int n = envelopes.size();
        
        if(n == 0)
            return 0;
        
        sort(envelopes.begin(), envelopes.end());
        
        vector<int> dp(n + 1, 1);
        int max = 1;
        
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if( envelopes[i][0] > envelopes[j][0] &&
                    envelopes[i][1] > envelopes[j][1] &&
                    dp[j] + 1 > dp[i] )
                    dp[i] = dp[j] + 1;
                
                if(max < dp[i])
                    max = dp[i];
            }
        }
        
        return max;
    }
};

// https://leetcode.com/problems/russian-doll-envelopes/discuss/1134011/JS-Python-Java-C%2B%2B-or-Easy-LIS-Solution-w-Explanation
// T.C O(n^2)
class Solution 
{
public:
    
    int maxEnvelopes(vector<vector<int>>& envelopes) 
    {
        sort(envelopes.begin(), envelopes.end(), [](vector<int>& a, vector<int>& b) -> bool {
            if(a[0] < b[0])
                return true;
            else if(a[0] == b[0])
                if(b[1] < a[1])
                    return true;
            
            return false;
        });
        
        vector<int> dp;
        
        for(auto e: envelopes)
        {
            int height = e[1];
            
            int left = lower_bound(dp.begin(), dp.end(), height) - dp.begin();
            if(left == dp.size())
                dp.push_back(height);
            
            dp[left] = height;
        }
        
        return dp.size();
    }
};