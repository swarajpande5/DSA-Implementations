// Product of array except self:    https://leetcode.com/problems/product-of-array-except-self/
//                                  https://leetcode.com/problems/product-of-array-except-self/discuss/1597959/c%2B%2B-or-discussing-all-solutions-or-explaining-in-detail-with-image-or

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {

        int n = nums.size();
        vector<int> ans(n);

        // Used as right product array
        ans[n - 1] = 1;

        for (int i = n - 2; i >= 0; i--)
            ans[i] = nums[i + 1] * ans[i + 1];

        int leftProd = 1;
        for (int i = 0; i < n; i++)
        {
            ans[i] = leftProd * ans[i];
            leftProd = leftProd * nums[i];
        }

        return ans;
    }
};