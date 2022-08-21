// Matrix block sum: https://leetcode.com/problems/matrix-block-sum/
class Solution 
{
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) 
    {
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<int>> ans(n, vector<int>(m));
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 1; j < m; j++)
            {
                mat[i][j] += mat[i][j-1];
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j = 0;j < m; j++)
            {
                int r1 = max(0, i - k), r2 = min(n - 1,i + k);
                int c1 = max(0, j - k), c2 = min(m - 1,j + k);
                int sum = 0;
                for(int p = r1;p <= r2; p++)
                {
                    sum += mat[p][c2];
                    sum -= (c1 - 1 >= 0 ? mat[p][c1 - 1] : 0);
                }
                
                ans[i][j] = sum;
            }
        }
        
        return ans;
    }
};