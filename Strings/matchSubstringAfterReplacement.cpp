// Match substring after replacement: https://leetcode.com/problems/match-substring-after-replacement/
// https://leetcode.com/problems/match-substring-after-replacement/discuss/2138790/Greedy-Approach-or-O(N-*K)-or-C%2B%2B-Solution

class Solution 
{
public:
    
    unordered_map<char, unordered_map<char, bool>> isMapped;
    
    bool check(string &s, string &sub, int pos)
    {
        if(pos + sub.size() > s.size())
            return false;
        
        int idx = 0;
        for(int i = pos; i < pos + sub.size(); i++)
        {
            if(sub[idx] == s[i] || isMapped[sub[idx]][s[i]])
                idx++;
            else
                return false;
        }
        
        return true;
    }
    
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) 
    {
        for(vector<char> mapping: mappings)
            isMapped[mapping[0]][mapping[1]] = true;
        
        for(int i = 0; i < s.size(); i++)
            if(check(s, sub, i))
                return true;
        
        return false;
    }
};