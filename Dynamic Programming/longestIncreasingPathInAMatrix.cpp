// Longest increasing path in a matrix: https://leetcode.com/problems/longest-increasing-path-in-a-matrix/

// Recusive Solution ( T.C. = O((N*M)*4^(N*M)) )
class RecursiveSolution
{
    // Moving directions: Top, down, left, right
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
public:
    
    int solve(vector<vector<int>> &matrix, int i, int j)
    {
        // Variable to store the maximum length of path starting from ceil i, j of the matrix
        int mx = 1;
        
        // Choosing all the 4 moving directions for current cell
        for(auto direction: directions)
        {
            int newI = i + direction[0];
            int newJ = j + direction[1];
            
            // Bound checking
            if(newI < 0 || newJ < 0 || newI >= matrix.size() || newJ >= matrix[0].size() || matrix[newI][newJ] <= matrix[i][j])
                continue;
            
            mx = max(mx, 1 + solve(matrix, newI, newJ));
        }
        
        return mx;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix)
    {
        // Atleast one cell can always be selected in the path
        int maxPath = 1; 
        
        // Exploring each cell of matrix to find longest path achievable from that cell and finally return the maximum
        for(int i = 0; i < matrix.size(); i++)
            for(int j = 0; j < matrix[0].size(); j++)
                maxPath = max(maxPath, solve(matrix, i, j));
        
        return maxPath;
    }
    
};

// Top Down Solution ( T.C. = O(MN) )
class Solution 
{
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    // dp[i][j] will store maximum path length starting from matrix[i][j]
    vector<vector<int>> dp;
    
    int maxPath, m, n;
    
public:
    
    int solve(vector<vector<int>>& matrix, int i, int j)
    {
        // If already calculated, then return the stored value
        if(dp[i][j])
            return dp[i][j];
        
        // Minimum path from each cell is always atleast 1
        dp[i][j] = 1;
        
        for(int k = 0; k < 4; k++)
        {
            int newI = i + directions[k][0];
            int newJ = j + directions[k][1];
            
            // Bound checking
            if(newI < 0 || newJ < 0 || newI >= m || newJ >= n || matrix[newI][newJ] <= matrix[i][j])
                continue;
            
            // Updating the current maximum value
            dp[i][j] = max(dp[i][j], 1 + solve(matrix, newI, newJ));
        }
        
        return dp[i][j];
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) 
    {
        maxPath = 1;
        m = matrix.size();
        n = matrix[0].size();
        
        // Resizing the dp matrix
        dp.resize(m, vector<int>(n));
        
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                maxPath = max(maxPath, solve(matrix, i, j));
        
        return maxPath;
    }
};