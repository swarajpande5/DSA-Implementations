// Count negative numbers in a sorted matrix: https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/

class Solution 
{
public:
    int countNegatives(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();

        // Starting from bottom left position
        int i = m - 1;
        int j = 0;

        int count = 0;

        while(i >= 0 && j < n)
        {
            if(grid[i][j] < 0)
            {   
                // When the first occurence of a number in a row is negative, all the following numbers are negative.
                count += (n - j);

                // Then move to the above row
                i--;
            }
            else 
            {
                // Simply move to the right
                j++;
            }
        }

        return count;
    }
};