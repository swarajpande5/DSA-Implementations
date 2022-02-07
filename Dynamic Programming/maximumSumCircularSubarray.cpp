// Maximum sum circular subarray:   https://leetcode.com/problems/maximum-sum-circular-subarray/
//                                  https://leetcode.com/problems/maximum-sum-circular-subarray/discuss/178422/One-Pass

class Solution
{
public:
    int maxSubarraySumCircular(vector<int>& nums)
    {
        int total = 0;
        int maxSum = nums[0];
        int currMax = 0;
        int minSum = nums[0];
        int currMin = 0;

        for(int &ele: nums)
        {
            currMax = max(currMax + ele, ele);
            maxSum = max(maxSum, currMax);
            currMin = min(currMin + ele, ele);
            minSum = min(minSum, currMin);

            total += ele;
        }

        if(maxSum < 0)
            return maxSum;
        
        return max(maxSum, total - minSum);
    }
};