// Subarray Sum Equals K: https://leetcode.com/problems/subarray-sum-equals-k/
class Solution 
{
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        int sum = 0;
        int result = 0;
        map<int, int> m;
        m[0] = 1;
        
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            
            if(m.find(sum - k) != m.end())
                result += m[sum - k];
            
            m[sum]++;
        }
        
        return result;
    }
};
