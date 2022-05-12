// Permutations 2: https://leetcode.com/problems/permutations-ii/

class Solution 
{
public:
    
    vector<vector<int>> ans;
    
    void generatePermutations(unordered_map<int, int> &mp, vector<int> &curr, int n)
    {
        if(curr.size() == n)
        {    
            ans.push_back(curr);
            return;
        }
        
        for(auto [key, value]: mp)
        {
            if(value == 0)
                continue;
            
            curr.push_back(key);
            mp[key]--;
            
            generatePermutations(mp, curr, n);  // Recursive call
            
            curr.pop_back();                    // Backtracking
            mp[key]++;
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        unordered_map<int, int> mp;
        vector<int> curr;
        
        for(int ele: nums)
            mp[ele]++;
        
        generatePermutations(mp, curr, nums.size());
        
        return ans;
    }
};
