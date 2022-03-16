// Arithmetic slices: https://leetcode.com/problems/arithmetic-slices/

class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {

        if (nums.size() < 3)
            return 0;

        int count = 0, idx = 0;
        int prevDiff = nums[1] - nums[0];

        for (int i = 1; i < nums.size() - 1; i++)
        {
            int currDiff = nums[i + 1] - nums[i];

            if (currDiff == prevDiff)
                idx++;
            else
            {
                prevDiff = currDiff;
                idx = 0;
            }

            count += idx;
        }

        return count;
    }
};