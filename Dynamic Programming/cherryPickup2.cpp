// Cherry Pickup II: https://leetcode.com/problems/cherry-pickup-ii/

/*
    Intuition 1:
    This is definitely a DP problem, as we have to solve similar subproblems, 
    and the answer requires a optimal substructure.

    Intuition 2:
    As robo1 and robo2 can move in 3 directions i.e. in downward row changes
    and diagonal left and right column changes. So the dimensions of the dp matrix
    can be dp[r1][c1][r2][c2].
    But we know that robos can move simulatenously, so we can take advantage of this fact 
    and can say that they both change at the same row.
    So combining r1 and r2, we get new dimensions as dp[r][c1][c2]

    Intuition 3:
    We have defined our dimensions now let's decise the movement by recursion formula.
    We have three directions for each robot, so there are 9 possible movements.
    which are as follows,
                dp[r - 1][c1 - 1][c2 - 1],
				dp[r - 1][c1 - 1][c2],
				dp[r - 1][c1 - 1][c2 + 1],
				dp[r - 1][c1][c2 - 1],
				dp[r - 1][c1][c2],
				dp[r - 1][c1][c2 + 1],
				dp[r - 1][c1 + 1][c2 - 1],
				dp[r - 1][c1 + 1][c2],
				dp[r - 1][c1 + 1][c2 + 1]
    Since we need to return max number of cherrys, we need to find max of all 9 states.

    Intuition 4:
    There may be clash between the robos, when they move to same position. In this case,
    we simply can use a if condition to give the cherry to any one robo.
    (c1 == c2) ? (dp[r][c1][c2] = prevMax + grid[r][c1]) : (dp[r][c1][c2] = prevMax + grid[r][c1] + grid[r][c2]);

    Intuition 5:
    In the end we just need to compute the maximum of the last dp row, by using
    res = max (res, dp[m - 1][i][j])
    
*/

class Solution
{
public:
    int cherryPickup(vector<vector>>& grid)
    {
        // m = number of rows, n = number of columns
        int m = grid.size();
        int n = grid[0].size();

        // Initializing dp matrix
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n, vector<int>(n, 0)));

        // dp dimensions
        dp[0][0][n - 1] = 0 == n - 1 ? grid[0][0] : grid[0][0] + grid[0][n - 1];

        for(int r = 1; r < m; r++)
        {
            for(int c1 = 0; c1< min(n, r + 1); c1++)
            {
                for(int c2 = max(0, n - 1 - r); c2 < n; c2++)
                {
                    int prevMax = 0;
                    for(int offset1 = max(0, c1 - 1); offset1 <= min(n - 1, c1 + 1); offset1++)
                    {
                        for(int offset2 = max(0, c2 - 1); offset2 <= min(n - 1, c2 + 1); offset2++)
                        {
                            prevMax = max(prevMax, dp[r - 1][offset1][offset2]);  // 9 states summarized using offset1 and offset2 iterating vars
                        }
                    }

                    // Robo collision condition check
                    if(c1 == c2)
                        dp[r][c1][c2] = prevMax + grid[r][c1];
                    else 
                        dp[r][c1][c2] = prevMax + grid[r][c1] + grid[r][c2];
                }
            }
        }

        int res = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
                res = max(res, dp[m - 1][i][j]);
        }

        return res;
    }
};