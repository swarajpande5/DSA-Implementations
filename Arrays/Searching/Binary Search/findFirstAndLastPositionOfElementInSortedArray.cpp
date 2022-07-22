// Find first and last position of an element in sorted array: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

class Solution 
{
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        auto lit = lower_bound(nums.begin(), nums.end(), target);
        auto uit = lower_bound(nums.begin(), nums.end(), target + 1);
            
        if(lit != nums.end() && *lit == target)
        {
            return {static_cast<int>(lit - nums.begin()), static_cast<int>(uit - nums.begin() - 1)};
        }
        
        return {-1, -1};
    }
};