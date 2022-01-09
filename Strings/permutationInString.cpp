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