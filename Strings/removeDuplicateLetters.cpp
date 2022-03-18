// https://leetcode.com/problems/remove-duplicate-letters/

class Solution 
{
public:
    string removeDuplicateLetters(string s) 
    {
        unordered_map<char, int> freq;
        unordered_map<char, bool> visited;
        string res;
        
        for(char ch: s)
            freq[ch]++;
        
        for(char ch: s)
        {
            freq[ch]--;
            if(visited[ch])
                continue;
            
            while(!res.empty() && res.back() > ch && freq[res.back()] > 0)
            {
                visited[res.back()] = false;
                res.pop_back();
            }
            
            visited[ch] = true;
            res += ch;
        }
        
        return res;
    }
};