// Search in rotated sorted array 2: 

class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {
        int low = 0;
        int high = nums.size() - 1;

        while(low <= high)
        {
            // Skipping duplicates from left
            while (low < high && nums[low] == nums[low + 1])
                low++;
            
            // Skipping duplicates from right
            while(high > low && nums[high] == nums[high - 1])
                high--;
            
            int mid = (low + high) / 2;

            if(target == nums[mid])
                return true;
            
            // There exists rotation, the middle element is in the left part of the PIVOT
            if (nums[mid] > nums[high]) 
            {
                if (target < nums[mid] && target >= nums[low])
                    high = mid - 1;
                else
                    low = mid + 1;
            }

            // There exists rotation, the middle element is in the right part of the PIVOT
            else if (nums[mid] < nums[low]) 
            {
                if (target > nums[mid] && target <= nums[high])
                    low = mid + 1;
                else
                    high = mid - 1;
            }

            // There is no rotation, just like normal binary search
            else 
            {
                if (target < nums[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
        }

        return false;
    }
};