// Longest repeating character replacement: https://leetcode.com/problems/longest-repeating-character-replacement/

class Solution 
{
public:
    int characterReplacement(string s, int k) 
    {
        int ans = 0;
        int maxSoFar = 0;
        int ws = 0;
        map<char, int> mp;
        
        for(int we = 0; we < s.size(); we++) 
        {
            int currChar = s[we];
            mp[currChar]++;
            
            maxSoFar = max(maxSoFar, mp[currChar]);
            
            // If characters left to repalce are more than k then slide the window
            if((we - ws + 1) - maxSoFar > k) 
            {
                currChar = s[ws];
                mp[currChar]--;
                ws++;
            }
            
            ans = max(ans, we - ws + 1);
        }
        
        return ans;
    }
};