// Spiral matrix 2: https://leetcode.com/problems/spiral-matrix-ii/

class Solution 
{
public:
    vector<vector<int>> generateMatrix(int n) 
    {
        int r1 = 0, r2 = n - 1;
        int c1 = 0, c2 = n - 1;
        int val = 0;
        
        vector<vector<int>> grid(n, vector<int>(n));
        
        while(r1 <= r2 && c1 <= c2)
        {
            // Left to right move, row is fixed
            for(int i = c1; i <= c2; i++)
                grid[r1][i] = ++val;
            
            // Top to bottom move, column is fixed
            for(int i = r1 + 1; i <= r2; i++)
                grid[i][c2] = ++val;
            
            // Right to left move, row is fixed
            for(int i = c2 - 1; i >= c1; i--)
                grid[r2][i] = ++val;
            
            // Bottom to up move, column is fixed
            for(int i = r2 - 1; i > r1; i--)
                grid[i][c1] = ++val;
            
            r1++;
            c1++;
            r2--;
            c2--;
        }
        
        return grid;
    }
};