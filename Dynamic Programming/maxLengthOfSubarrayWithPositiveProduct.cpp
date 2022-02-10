// Maximum length of subarray with positive product:    https://leetcode.com/problems/maximum-product-subarray/discuss/183483/JavaC++Python-it-can-be-more-simple/330117
//                                                      https://leetcode.com/problems/maximum-length-of-subarray-with-positive-product/discuss/824426/Fully-Explained-Solution-oror-Using-simple-concept-of-odd-and-even-oror-O(n)-Solution

class Solution
{
public:
    int getMaxLen(vector<int>& nums)
    {
        int mx = 0;
        int size = nums.size();

        for(int i = 0; i < size; i++)
        {
            int negStart = -1;
            int negEnd = -1;
            int neg = 0;
            int pos = 0;
            int j;

            for(j = i; j < size; j++)
            {
                if(nums[j] < 0)
                    neg++;
                
                if(nums[j] > 0)
                    pos++;
                
                if(nums[j] < 0 && negStart == -1)
                    negStart = j;
                
                if(nums[j] < 0)
                    negEnd = j;
                
                if(nums[j] == 0)
                    break;
            }

            if(neg % 2 == 0)
                mx = max(mx, neg + pos);
            
            if(neg % 2 == 1)
            {
                mx = max(mx, j - negStart - 1);
                mx = max(mx, negEnd - i);
            }

            i = j;
        }

        return mx;
    }
};