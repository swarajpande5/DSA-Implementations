// Subarray product less than k: https://leetcode.com/problems/subarray-product-less-than-k/

class Solution
{
public:
    int numSubarrayProductLessThanK(vector<int>& a, int k)
    {
        int n = a.size();
        if(k <= 1)
            return 0;
        
        long long prod = 1;
        int result = 0;

        int left = 0;
        int right = 0;

        while(right < n)
        {
            prod *= a[right];

            while(prod >= k)
            {
                prod /= a[left];
                left++;
            }

            result += right - left + 1;
            right++;
        }

        return result;
    }
};