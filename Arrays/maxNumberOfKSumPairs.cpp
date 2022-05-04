// Max number of k-sum pairs: https://leetcode.com/problems/max-number-of-k-sum-pairs/
class Solution 
{
public:
    int maxOperations(vector<int>& nums, int k) 
    {
        unordered_map<int, int> mp;
        
        for(int num: nums)
            mp[num]++;
        
        int ans = 0;
        for(auto p: mp)
        {
            int num = p.first;
            int count = p.second;
            
            if(k - num == num)
                ans += count / 2;
            
            else if(mp.count(k - num))
            {
                int mn = min(count, mp[k - num]);
                ans += mn;
                mp[num] -= mn;
                mp[k - num] -= mn;
            }
        }
        
        return ans;
    }
};