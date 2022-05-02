// https://leetcode.com/problems/sort-array-by-parity/

class Solution 
{
public:
    vector<int> sortArrayByParity(vector<int>& nums) 
    {
        int i = 0;
        int j = 0;
        
        while(i < nums.size())
        {
            if(nums[i] % 2 == 0)
            {
                swap(nums[i], nums[j]);
                j++;
            }
            
            i++;
        }
        
        return nums;
    }
};