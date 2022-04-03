// Next permutation: https://leetcode.com/problems/next-permutation/

/*
    Intuition:
    1.  Linearly traversing the given array from end, and find a number that is greater than its adjacent nums[i] > nums[i - 1].
        Store this index of smaller number in a variable (say 'breakpoint'). If there is no such element, reverse entire array and return.
    2.  Linearly traverse from end and this time find a number larger than nums[breakpoint], then swap that number and nums[breakpoint].
    3.  Reverse the array from index breakpoint + 1 to nums.size()
*/

class Solution
{
public:
    void nextPermutation(vector<int>& nums)
    {
        int breakpoint = -1;
        
        // Finding a breakpoint
        for(int i = nums.size() - 1; i > 0; i--)
        {
            if(nums[i] > nums[i - 1])
            {
                breakpoint = i - 1;
                break;
            }
        }

        // If no breakpoint
        if(breakpoint == -1)
        {
            reverse(nums.begin(), nums.end());
            return;
        }

        // If found a breakpoint
        for(int i = nums.size() - 1; i >= 0; i--)
        {
            if(nums[i] > nums[breakpoint])
            {
                swap(nums[breakpoint], nums[i]);
                reverse(nums.begin() + breakpoint + 1, nums.end());
                break;
            }
        }
    }
};

// Another simple solution using STL
class STLSolution
{
public:
    void nextPermutation(vector<int>& nums)
    {
        next_permutation(nums.begin(), nums.end());
    }
};