// Two sum 2 Input array is sorted: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

// Binary search solution (T.C. O(nlogn))
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int n = nums.size();

        for(int i = 0; i < n - 1; i++)
        {
            int lo = i + 1;
            int hi = n;

            int idx = lower_bound(nums.begin() + lo, nums.begin() + hi, target - nums[i]) - nums.begin();
            if(idx != nums.size() && nums[idx] == target-nums[i])
                return {i+1, idx + 1};
        }

        return {};
    }
};

// Two pointer solution (T.C. O(n))
class Solution 
{
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        int i = 0, j = nums.size() - 1;

        while(i <= j)
        {
            int sum = nums[i] + nums[j];
            if(sum == target)
                return {i + 1, j + 1};
            else if(sum > target)
                j--;
            else 
                i++;
        }
        
        return {-1, -1};
    }
};