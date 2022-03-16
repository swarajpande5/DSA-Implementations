// Total Decoding Messages: https://leetcode.com/problems/decode-ways/

class Solution 
{
public:
	int CountWays(string str)
	{
        // int mod = 1e9 + 7;
        
        int n = str.length();
        int dp[n + 1];
        dp[0] = 1;
        dp[1] = 1;
        
        if(str[0] == '0')
            return 0;
        if(n == 1 && str[0] != '0')
            return 1;
        
        for(int i = 2; i <= n; i++)
        {
            // Default value of the dp matrix
            dp[i] = 0;
            
            // When last digit is greater than zero, 
            // we simply add the digit to the number of words
            if(str[i- 1] > '0')
                dp[i] = dp[i - 1];
            
            // If last two digits form a number less than equal to 26
            // then the number of words is incremented by
            // the count of words till those two digits.
            if(str[i - 2] == '1' || str[i - 2] == '2' && str[i - 1] <= '6')
                dp[i] = (dp[i] + dp[i - 2]);
        }
        
        return dp[n];
	}

};