// Interleaving String: https://leetcode.com/problems/interleaving-string/

// Memoization solution
class Solution 
{
public:
    
    bool solve(string &s1, string &s2, string &s3, int i, int j, vector<vector<int>> &dp)
    {
        if(i == s1.size() && j == s2.size())
            return true;
        
        if(dp[i][j] != -1)
            return dp[i][j]; 
        
        if(i < s1.size() && s1[i] == s3[i + j])
            if(solve(s1, s2, s3, i + 1, j, dp))
                return dp[i][j] = true; 
        
        if(j < s2.size() && s2[j] == s3[i + j])
            if(solve(s1, s2, s3, i, j + 1, dp))
                return dp[i][j] = true; 
        
        return dp[i][j] = false;
    }
    
    bool isInterleave(string s1, string s2, string s3) 
    {
        const int M = s1.size() + 1;
        const int N = s2.size() + 1;
        vector<vector<int>> dp(M, vector<int>(N, -1));
        
        if(s1.size() + s2.size() != s3.size())
            return false;
        
        if(solve(s1, s2, s3, 0, 0, dp))
            return true; 
        
        return false;
    }
};