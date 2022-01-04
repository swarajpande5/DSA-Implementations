// Search Insert Position: https://leetcode.com/problems/search-insert-position/

class Solution 
{
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        int lo = 0;
        int hi = nums.size();
        
        if(nums[hi - 1] < target)
            return hi;
        
        else 
        {
            while(lo <= hi)
            {
                int mi = lo + (hi - lo) / 2;
                if(nums[mi] == target)
                    return mi;
                else if(nums[mi] < target)
                    lo = mi + 1;
                else 
                    hi = mi - 1;
            }
        }
        
        return lo;
    }
};