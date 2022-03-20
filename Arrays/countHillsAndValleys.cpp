// Count hills and valleys: https://leetcode.com/problems/count-hills-and-valleys-in-an-array/

class Solution 
{
public:
    int countHillValley(vector<int>& nums) 
    {
        
        vector<int> vec;
        vec.push_back(nums[0]);
        
        // Pushing unique elements into new vector
        for(int i = 1; i < nums.size(); i++)
            if(nums[i] != nums[i - 1])
                vec.push_back(nums[i]);
        
        int count = 0;
        
        // Checking for valleys and hills
        for(int i = 1; i < vec.size() - 1; i++)
            if((vec[i] > vec[i - 1] && vec[i] > vec[i + 1]) || (vec[i] < vec[i - 1] && vec[i] < vec[i + 1]))
                count++;
        
        return count;
    }
};