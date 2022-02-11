// Permutation in string: https://leetcode.com/problems/permutation-in-string/

class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        vector<int> count(26, 0);

        if(s1.length() < s2.length())
            return false;
        
        for(int i = 0; i < s1.length(); i++)
        {
            count[s1[i] - 'a']++;
            count[s2[i] - 'a']--;
        }

        if(allZero(count))
            return true;
    
        for(int i = s1.length(); i < s2.length(); i++)
        {
            count[s2[i] - 'a']--;
            count[s2[i - s1.length()] - 'a']++;

            if(allZero(count))
                return true;
        }
        
        return false;
    }

    bool allZero(vector<int> count)
    {
        for(int x: count)
            if(x != 0)
                return false;
        
        return true;
    }
};

class Solution2 
{
public:
    bool checkInclusion(string s1, string s2) 
    {
        int map[26] = {0};
        
        for(char c : s1) 
            map[c - 'a']++;
        
        int j = 0, i = 0, count_chars = s1.size();
        while(j < s2.size())
        {
            if(map[s2.at(j++) - 'a']-- > 0)
                count_chars--;
            
            if(count_chars == 0) 
                return true;
            
            if(j - i == s1.size() && map[s2.at(i++) - 'a']++ >= 0)
                count_chars++;
        }
        
        return false;
    }
};

class Solution3
{
public:
    bool checkInclusion(string s1, string s2)
    {
        if(s1.size() > s2.size())
            return false;
        
        vector<int> s1Freq(26, 0), s2Freq(26, 0);

        int i = 0;
        
        // First Window
        for(; i < s1.size(); i++)
        {
            s1Freq[s1[i] - 'a']++;
            s2Freq[s2[i] - 'a']++;
        }

        if(s1Freq == s2Freq)
            return true;
        
        // Searching the remaining windows
        for(; i < s2.size(); i++)
        {
            // Removing the first character of current window and adding the current character
            s2Freq[s2[i - s1.size()] - 'a']--;
            s2Freq[s2[i] - 'a']++;

            if(s1Freq == s2Freq)
                return true;
        }

        return false;
    }
};