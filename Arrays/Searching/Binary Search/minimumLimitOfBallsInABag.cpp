// Minimum limit of balls in a bag: https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/ 

class Solution
{
public: 
    int minimumSize(vector<int> &nums, int maxOperations)
    {
        int low = 1; 
        int high = 1e9; 

        while(low < high) 
        {
            int mid = (low + high) / 2; 
            
            int count = 0; 
            for(int ele: nums)
                count += (ele - 1) / mid; 

            if(count > maxOperations)
                low = mid + 1; 
            
            else 
                right = mid; 
        }

        return low;
    }
};