// Number of increasing paths in a grid: https://leetcode.com/problems/number-of-increasing-paths-in-a-grid/

class Solution
{
public:
    const static int max = 1000;
    int mod = 1e9 + 7;
    int cntIncreasingPaths(vector<vector<int>> &grid, int dp[max][max], int n, int m, int x, int y)
    {

        if (dp[x][y] != -1)
            return dp[x][y];

        int delta[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        int newx, newy;

        int ans = 1;

        for (int i = 0; i < 4; i++)
        {

            newx = x + delta[i][0];
            newy = y + delta[i][1];

            // Bound check and increasing check
            if (newx >= 0 && newx < n && newy >= 0 && newy < m && grid[newx][newy] > grid[x][y])
            {
                ans += cntIncreasingPaths(grid, dp, n, m, newx, newy);
                ans = ans % mod;
            }
        }
        return dp[x][y] = ans;
    }

    int countPaths(vector<vector<int>> &grid)
    {
        int dp[max][max];
        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                dp[i][j] = -1;

        int sum = 0;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                sum += cntIncreasingPaths(grid, dp, n, m, i, j);
                sum = sum % mod;
            }

        return sum % mod;
    }
};