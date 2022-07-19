// Partition array into two arrays to minimize sum difference: https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/
// https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/discuss/2121935/C-%2B%2B-Meet-in-Middle-but-no-TLE-faster-than-50

class Solution 
{
public:
    
    vector<vector<int>> getSubsetSum(vector<int> nums, int l, int r)
    {
        int len = r - l + 1; 
        
        vector<vector<int>> res(len + 1); 
        
        for(int i = 0; i < (1 << len); i++)
        {
            int sum = 0; 
            int cnt = 0;
            
            for(int j = 0; j < len; j++)
            {
                if(i & (1 << j))
                {
                    sum += nums[l + j]; 
                    cnt++;
                }
            }
            
            res[cnt].push_back(sum);
        }
        
        return res;
    }
    
    int minimumDifference(vector<int>& nums) 
    {
        int n = nums.size(); 
        int sum = accumulate(nums.begin(), nums.end(), 0); 
        int target = sum / 2; 
        
        vector<vector<int>> left = getSubsetSum(nums, 0, n / 2 - 1);        // Returns all possible sums if selecting i elements from left part
        vector<vector<int>> right = getSubsetSum(nums, n / 2, n - 1);       // Returns all possible sums if selecting i elements from right part
        
        int ans = INT_MAX; 
        
        for(int i = 0; i <= n / 2; i++)
        {
            sort(right[n / 2 - i].begin(), right[n / 2 - i].end()); 
            
            for(int j = 0; j < left[i].size(); j++)
            {
                int currLeft = left[i][j]; 
                
                // We perform binary search in the right parth such that we choose n / 2 - i elements (i.e. total n / 2) which is closest to the target (sum / 2)
                auto it = lower_bound(right[n / 2 - i].begin(), right[n / 2 - i].end(), target - currLeft); 
                
                if(it != right[n / 2 - i].end())
                    ans = min(ans, abs(sum - 2 * (currLeft + *it)));
            }
        }
        
        return ans;
    }
};