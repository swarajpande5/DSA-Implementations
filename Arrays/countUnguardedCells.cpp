// Count unguarded cells in the grid: https://leetcode.com/problems/count-unguarded-cells-in-the-grid/

class Solution 
{
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) 
    {
        vector<vector<int>> mat(m, vector<int>(n, 0));
        for(auto v: guards)
            mat[v[0]][v[1]] = 2;
        for(auto v: walls)
            mat[v[0]][v[1]] = -2;
        
        
        for(auto g: guards)
        {
            int r = g[0];
            int c = g[1];
            
            // Moving right
            for(int i = c + 1; i < n; i++)
            {
                if(mat[r][i] == -2 || mat[r][i] == 2)
                    break;
                
                mat[r][i] = 1;
            }
            
            // Moving down 
            for(int i = r + 1; i < m; i++)
            {
                if(mat[i][c] == -2 || mat[i][c] == 2)
                    break;
                
                mat[i][c] = 1;
            }
            
            // Moving left
            for(int i = c - 1; i >= 0; i--)
            {
                if(mat[r][i] == -2 || mat[r][i] == 2)
                    break;
                
                mat[r][i] = 1;
            }
            
            // Moving up
            {
                for(int i = r - 1; i >= 0; i--)
                {
                    if(mat[i][c] == -2 || mat[i][c] == 2)
                    break;
                
                    mat[i][c] = 1;
                }
            }
        }
        
        int count = 0;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(mat[i][j] == 0)
                    count++;
        
        return count;
        
    }
};