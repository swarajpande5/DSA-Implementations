// Maximize dot product of two arrays (with insertion of zeros): https://practice.geeksforgeeks.org/problems/maximize-dot-product2649/1/

class Solution{
		
	public:
	int maxDotProduct(int n, int m, int A[], int B[]) 
	{ 
	    int dp[m + 1][n + 1];
        memset(dp, 0, sizeof(dp));
        
        for(int i = 1; i < m + 1; i++)
            for(int j = i; j < n + 1; j++)
                dp[i][j] = max(
                    (dp[i - 1][j - 1] + A[j - 1] * B[i - 1]),
                    dp[i][j - 1]
                );
        
        return dp[m][n];
	} 
};