// Shortest unsorted continuous subarray: https://leetcode.com/problems/shortest-unsorted-continuous-subarray/

// Two pass solution
class Solution 
{
public:
    int findUnsortedSubarray(vector<int>& nums) 
    {
        int n = nums.size();
        
        int start = -1, end = n;
        
        int currMin = INT_MAX;
        for(int i = n - 1; i >= 0; i--)
        {
            if(currMin > nums[i])
                currMin = nums[i];
            
            if(nums[i] > currMin)
                start = i;
        }
        
        int currMax = INT_MIN;
        for(int i = 0; i < n; i++)
        {
            if(currMax < nums[i])
                currMax = nums[i];
            
            if(nums[i] < currMax)
                end = i;
        }
        
        return (start == -1) ? 0 : end - start + 1;
    }
};

// One pass solution
class EfficientSolution
{
public:
    int findUnsortedSubarray(vector<int>& nums)
    {
        int start = 0;
        int end = -1;

        int i = 0;
        int j = nums.size() - 1;

        int currMax = INT_MIN;
        int currMin = INT_MAX;

        while(j >= 0)
        {
            if(nums[i] >= currMax)
                currMax = nums[i];
            else 
                end = i;

            if(nums[j] <= currMin)
                currMin = nums[j];
            else 
                start = j;
            
            i++;
            j--;
        }

        return end - start + 1;
    }
};