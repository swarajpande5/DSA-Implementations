// Search a 2D matrix: https://leetcode.com/problems/search-a-2d-matrix/

class RowBinarySearchSolution 
{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        
        if(!matrix.size() || !matrix[0].size())
            return false;
        
        int row, mid;
        int l = 0;
        int r = matrix.size() - 1;
        
        // First choosing the appropiate row
        while(l < r)
        {
            mid = (l + r) / 2;
            if(matrix[mid].back() < target)
                l = mid + 1;
            else if(matrix[mid][0] > target)
                r = mid - 1;
            else 
            {
                l = mid;
                break;
            }
        }
        
        // After the row is chosen, we finally search the element
        row = l;
        l = 0;
        r = matrix[0].size() - 1;
        
        while(l <= r)
        {
            mid = (l + r) / 2;
            if(matrix[row][mid] < target)
                l = mid + 1;
            else if(matrix[row][mid] > target)
                r = mid - 1;
            else 
                return true;
        }
        
        return false;
    }
};

class Solution 
{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        if (!matrix.size()) return false;

        int m = matrix.size();
        int n = matrix[0].size();
        int l = 0;
        int h = (m * n) - 1;

        while (l <= h) 
        {
            int mid = (l + (h - l) / 2);

            if (matrix[mid / n][mid % n] == target)
                return true;
            if (matrix[mid / n][mid % n] < target)
                l = mid + 1;
            else
                h = mid - 1;
        }
        return false;  
    }
};