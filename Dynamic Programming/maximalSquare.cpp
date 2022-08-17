// Maximal Square: https://leetcode.com/problems/maximal-square/

class BottomUPSolution 
{
public:
    int maximalSquare(vector<vector<char>>& matrix) 
    {
        int m = matrix.size(); 
        int n = matrix[0].size();
        
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        int side = 0;
        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++) 
            {
                if(matrix[i - 1][j - 1] == '0')
                    dp[i][j] = 0;
                else 
                    dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
                
                side = max(side, dp[i][j]);
            }
        }
        
        return side * side;
    }
};

// Space optimal Solution
class Solution 
{
public:
    int maximalSquare(vector<vector<char>>& matrix) 
    {
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<int> prev(n + 1, 0), curr(n + 1, 0);
        
        int side = 0;
        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(matrix[i - 1][j - 1] == '0')
                    curr[j] = 0;
                else 
                    curr[j] = 1 + min({prev[j], curr[j - 1], prev[j - 1]});
            
                side = max(side, curr[j]);
            }
            
            prev = curr;
        }
        
        return side * side;
    }
};

// In Place Solution
class InPlaceDPSolution
{
public: 
    int maximalSquare(vector<vector<char>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int side = 0; 
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(matrix[i][j] == '1')
                {
                    if(i != 0 && j != 0)
                        matrix[i][j] = 1 + min({matrix[i - 1][j] - '0', matrix[i - 1][j - 1] - '0', matrix[i][j - 1] - '0'}) + '0';
                    
                    side = max(side, matrix[i][j] - '0');
                }
            }
        }
        
        return side * side;
    }
};