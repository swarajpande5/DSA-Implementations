// 3 Sum: https://leetcode.com/problems/3sum/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> res;
        
        if(nums.empty())
            return res;
    
        size_t n = nums.size();
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < n; i++)
        {
            if(nums[i] > 0)
                break;
        
            // If we have seen the combination before, we simply skip it
            if(i > 0 && nums[i] == nums[i - 1])
                continue;
        
            int left = i + 1;
            int right = n - 1;
            
            while(left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                
                if(sum < 0)
                    left++;
            
                else if(sum > 0)
                    right--;
            
                else 
                {
                    res.push_back({nums[i], nums[left], nums[right]});
                    
                    int lastLeft = nums[left];
                    int lastRight = nums[right];
                    
                    // If we have seen the combination before, we simply skip it
                    while(left < right && nums[left] == lastLeft)
                        left++;
                    
                    while(left < right && nums[right] == lastRight)
                        right--;
                }
            }
        }
        
        return res;
    }
};