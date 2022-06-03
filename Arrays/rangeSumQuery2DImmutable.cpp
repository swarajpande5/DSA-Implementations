// Range sum query 2d immutable: https://leetcode.com/problems/range-sum-query-2d-immutable/

class RowWisePrefixSumSolution 
{
public:
    
    vector<vector<int>> dp;
    
    RowWisePrefixSumSolution(vector<vector<int>>& matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        
        if(m == 0 || n == 0)
            return;
        
        dp.resize(m, vector<int>(n + 1, 0));
        
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                dp[i][j + 1] = dp[i][j] + matrix[i][j];
    }
    
    int sumRegion(int row1, int col1, int row2, int col2)
    {
        int sum = 0;
        for(int r = row1; r <= row2; r++)
            sum += dp[r][col2 + 1] - dp[r][col1];
        
        return sum;
    }
};

class NumMatrix 
{
public:
    vector<vector<int>> dp;
    
    NumMatrix(vector<vector<int>>& matrix) 
    {
        int m = matrix.size();
        int n = matrix[0].size();
        
        if(m == 0 || n == 0)
            return;
        
        dp.resize(m + 1, vector<int>(n + 1, 0));
        
        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= n; j++)
                dp[i][j] = matrix[i - 1][j - 1] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) 
    {
        return dp[row2 + 1][col2 + 1] - dp[row2+1][col1] - dp[row1][col2 + 1] + dp[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */