// Find all anagrams in string: https://leetcode.com/problems/find-all-anagrams-in-a-string/submissions/

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        int n = s.length();
        int m = p.length();

        if(m > n)
            return {};
        
        vector<int> pv(26, 0), sv(26, 0), res;

        for(int i = 0; i < m; i++)
            pv[p[i] - 'a']++;
        
        int i = 0, j = 0;
        while(j < n)
        {
            sv[s[i] - 'a']++;

            if((j - i + 1) < m)             // If the current window size is smaller we move ahead
                j++;
            
            else if((j - i + 1) == m)
            {
                if(pv == sv)
                    res.push_back(i);
                
                sv[s[i] - 'a']--;
                
                i++;
                j++;
            }
        }

        return res;
    }
};