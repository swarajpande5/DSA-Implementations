// Find and replace the pattern: https://leetcode.com/problems/find-and-replace-pattern/

class Solution 
{
public:
    
    bool match(string &w1, string &w2)
    {
        // Maps character of w1 to character of w2
        unordered_map<char, char> mp;
        
        // Mapping w1[i] -> w2[i] and also checking w1[i] -> w2[i] is unique
        for(int i = 0; i < w1.size(); i++)
        {
            // If there is a map for current character, and it is not matching, then we return false.
            // Otherwise we simply map the character
            if(mp.count(w1[i]) && mp[w1[i]] != w2[i])
                return false;
            else
                mp[w1[i]] = w2[i];
        }
        
        // Checking w2[i] -> w1[i] is unique
        // Once all the letters are mapped, we re-iterate over the mappings and ensure that each w2[i] is only mapped to single w1[i].
        bitset<26> visited;
        for(auto p: mp)
        {    
            // If already visited the current character, then return false
            // Otherwise mark it as visited.
            if(visited[p.second - 'a'])
                return false;
            else
                visited[p.second - 'a'] = true;
        }
        
        return true;
    }
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) 
    {
        vector<string> ans;
        
        for(auto &word: words)
            if(match(word, pattern))
                ans.push_back(word);
        
        return ans;
    }
};