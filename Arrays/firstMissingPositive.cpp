// First missing positive: https://leetcode.com/problems/first-missing-positive/
//                         https://leetcode.com/problems/first-missing-positive/discuss/767105/Short-C%2B%2B-O(n)-time-O(1)-space-oror-Steps-explained

class Solution 
{
public:
    int firstMissingPositive(vector<int>& nums) 
    {
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            while(nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1])
                swap(nums[i], nums[nums[i] - 1]);
        }
        
        for(int i = 0; i < n; i++)
            if(nums[i] != i + 1)
                return i + 1;
        
        return n + 1;
    }
};