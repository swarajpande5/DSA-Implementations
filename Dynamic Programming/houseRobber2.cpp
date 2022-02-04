// House robber: https://leetcode.com/problems/house-robber-ii/

/*
    This problem can be decomposed into two house robber problems.
    Since houses 0 and n - 1 are now neighbors, we cannot rob them together.
    And the solution is now the maximum of, 
        - Rob houses 0 to n - 2
        - Rob houses 1 to n - 1
*/

class Solution
{
private:
    int robber(vector<int>& nums, int l, int r)
    {
        int pre = 0, curr = 0;
        
        for(int i = l; i <= r; i++)
        {
            int temp = max(pre + nums[i], curr);
            pre = curr;
            curr = temp;
        }

        return curr;
    }

public:
    int rob(vector<int>& nums)
    {
        int n = nums.size();

        if(n < 2)
            return n ? nums[0] : 0;
        
        return max(robber(nums, 0, n - 2), robber(nums, 1, n - 1));
    }
};