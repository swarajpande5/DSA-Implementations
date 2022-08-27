// Max sum of rectangle no larger than k: https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/

class Solution 
{
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) 
    {
        if(matrix.empty())
            return 0;
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        int ans = INT_MIN; 
        
        for(int l = 0; l < n; l++)
        {
            vector<int> sums(m, 0); 
            for(int j = l; j < n; j++)
            {    
                for(int i = 0; i < m; i++)
                    sums[i] += matrix[i][j];
            
            // Finding max subarray no more than k 
                set<int> accu;
                accu.insert(0); 

                int currSum = 0;
                int currMax = INT_MIN; 

                for(int sum: sums)
                {    
                    currSum += sum;
                    auto it = accu.lower_bound(currSum - k); 

                    if(it != accu.end())
                        currMax = max(currMax, currSum - *it);

                    accu.insert(currSum);
                }
                
                ans = max(ans, currMax);
            }   
        }
        
        return ans;
    }
};