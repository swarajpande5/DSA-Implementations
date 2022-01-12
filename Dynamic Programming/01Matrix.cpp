// 01 Matrix: https://leetcode.com/problems/01-matrix/
// https://leetcode.com/problems/01-matrix/discuss/1369741/C%2B%2BJavaPython-BFS-DP-solutions-with-Picture-Clean-and-Concise-O(1)-Space

class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();
        int INF = m + n;

        // Calculating distance based on left and top neighbour for a given cell
        for(int r = 0; r < m; r++)
        {
            for(int c = 0; c < n; c++)
            {
                if(mat[r][c] == 0)
                    continue;
                
                int top = INF;
                int left = INF;

                if(r - 1 >= 0)
                    top = mat[r - 1][c];
                
                if(c - 1 >= 0)
                    left = mat[r][c - 1];
                
                mat[r][c] = min(top, left) + 1;
            }
        }

        // Calculating distance based on right and bottom neighbour for a given cell
        for(int r = m - 1; r >= 0; r--)
        {
            for(int c = n - 1; c >= 0; c--)
            {
                if(mat[r][c] == 0)
                    continue;
                
                int bottom = INF;
                int right = INF;

                if(r + 1 < m)
                    bottom = mat[r + 1][c];
                
                if(c + 1 < n)
                    right = mat[r][c + 1];
                
                mat[r][c] = min(mat[r][c], min(bottom, right) + 1);
            }
        }

        return mat;
    }
};