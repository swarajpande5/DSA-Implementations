// Triangle: https://leetcode.com/problems/triangle/

// // Recusive Solution
// class Solution
// {
// public:
//     int minTotalUtil(vector<vector<int>>& triangle, int h, int j)
//     {
//         if(h == triangle.size())
//             return 0;
        
//         return triangle[h][j] + min(minTotalUtil(triangle, h+1, j), minTotalUtil(triangle, h+1, j+1));
//     }

//     int minimumTotal(vector<vector<int>>& triangle)
//     {
//         return minTotalUtil(triangle, 0, 0);
//     }
// };

// // Memoization Solution
// class Solution
// {
// public:
//     int minTotalUtil(vector<vector<int>>& triangle, int h, int j, vector<vector<int>> &v)
//     {
//         if(h == triangle.size())
//             return 0;
        
//         if(v[h][j] != -1)
//             return v[h][j];
        
//         return v[h][j] = triangle[h][j] + min(minTotalUtil(triangle, h+1, j, v), minTotalUtil(triangle, h+1, j+1, v));
//     }
    
//     int minimumTotal(vector<vector<int>>& triangle)
//     {
//         int minSum = INT_MAX;
//         int h = triangle.size();
//         int j = h;

//         vector<vector<int>> v(h, vector<int>(j, -1));
//         minSum = minTotalUtil(triangle, 0, 0, v);

//         return minSum;
//     }
// };

// Bottom - up DP Solution
class Solution
{
public:
    int minimumTotal(vector<vector<int>>& triangle)
    {
        int minSum = INT_MAX;
        int h = triangle.size();
        int j = h;

        vector<vector<int>> dp(h, vector<int>(j, 0));

        dp[0][0] = triangle[0][0];

        for(int i = 1; i < h; i++)
        {
            for(int j = 0; j < triangle[i].size(); j++)
            {
                if(j == 0)
                    dp[i][j] = dp[i - 1][j] + triangle[i][j];
                
                else if(j == triangle[i].size() - 1)
                    dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
                
                else 
                    dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
            }
        }

        return *min_element(dp[h - 1].begin(), dp[h - 1].end());
    }
};