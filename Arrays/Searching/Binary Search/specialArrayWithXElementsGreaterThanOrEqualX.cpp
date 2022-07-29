// Special Array With X Elements Greater Than or Equal X: https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/

class Solution 
{
public:
    int specialArray(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        for(int i = 0; i <= n; i++)
        {
            int temp = n;
            int l=0;
            int h=n-1;
            while(h>=l)
            {
                int mid = l + (h - l)/2;
                if(nums[mid]>=i)
                {
                    temp = mid;
                    h = mid - 1;
                }
                
                else l = mid + 1;
            }
            if((n - temp) == i)
                return i;
    }
    return -1;
    }
};