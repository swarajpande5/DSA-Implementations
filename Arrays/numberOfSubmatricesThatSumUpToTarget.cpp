// Number of submatrices that sum up to target: https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/
// https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/discuss/1162927/Optimization-from-Brute-Force-to-Optimized-Solution-w-Easy-Explanation

class Solution 
{
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) 
    {
        int ans = 0; 
        int m = matrix.size(), n = matrix[0].size();
        
        for(int row = 0; row < m; row++)
            for(int col = 1; col < n; col++)
                matrix[row][col] += matrix[row][col - 1]; 
        
        unordered_map<int, int> mp; 
        
        for(int colStart = 0; colStart < n; colStart++)
        {
            for(int colEnd = colStart; colEnd < n; colEnd++)
            {
                int currSum = 0; 
                
                mp = {{0, 1}};
                
                for(int row = 0; row < m; row++)
                {
                    if(colStart == 0)
                        currSum += matrix[row][colEnd]; 
                    else 
                        currSum += matrix[row][colEnd] - matrix[row][colStart - 1];
                    
                    ans += mp[currSum - target]; 
                    mp[currSum]++;
                } 
            }
        }
        
        return ans;
    }
};