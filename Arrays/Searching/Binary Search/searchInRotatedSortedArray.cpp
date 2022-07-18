// Search in rotated sorted array: https://leetcode.com/problems/search-in-rotated-sorted-array/

class Solution 
{
public:
    int search(vector<int>& nums, int target) 
    {
        int low = 0;
        int high = nums.size() - 1;
        int mid;
        
        while(low <= high)
        {
            mid = (low + high)/2;
            
            if(nums[mid] == target)
                return mid;
            
            // There exists rotation, the middle element is in the left part of the pivot
            if(nums[mid] > nums[high])
            {
                if(target < nums[mid] && target >= nums[low])
                    high = mid - 1;
                else 
                    low = mid + 1;
            }

            // There exists rotation, the middle element is in the right parth of the pivot
            else if(nums[mid] < nums[low])
            {
                if(target > nums[mid] && target <= nums[high])
                    low = mid + 1;
                else 
                    high = mid - 1;
            }

            // There is no rotation, just like normal binary search
            else 
            {
                if(target < nums[mid])
                    high = mid - 1;
                else 
                    low = mid + 1;
            }
        }
        
        return -1;
    }
};