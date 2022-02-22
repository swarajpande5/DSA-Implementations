// Minimum size subarray sum: 

class Solution
{
public:
    int minSubarrayLen(int target, vector<int>& nums)
    {
        int right = 0, left = 0;
        int sum = 0, ans = INT_MAX;

        while(right < nums.size())
        {
            sum += nums[right];

            while(sum >= target)
            {
                ans = min(ans, right - left + 1);
                sum -= nums[left];
                left++;
            }

            right++;
        }

        return ans == INT_MAX ? 0 : ans;
    }
    
};