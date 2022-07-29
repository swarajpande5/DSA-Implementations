// Maximum distance between a pair of values: https://leetcode.com/problems/maximum-distance-between-a-pair-of-values/

class Solution 
{
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) 
    {
        int ans = 0;
        
        for(int i = 0; i < nums1.size(); i++)
        {
            // Finding the first element greater than or equal to nums[1]
            auto it = lower_bound(nums2.rbegin(), nums2.rend(), nums1[i]) - nums2.rbegin();
            int j = nums2.size() - 1 - it;  
            if(i <= j)
                ans = max(ans, j - i);
        }
        
        return ans;
    }
};