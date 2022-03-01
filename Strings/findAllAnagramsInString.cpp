// Find all anagrams in string: https://leetcode.com/problems/find-all-anagrams-in-a-string/submissions/
//                              https://leetcode.com/problems/find-all-anagrams-in-a-string/discuss/1305008/Simple-C%2B%2B-solutionororSliding-WindowororWith-explanation

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> res;

        unordered_map<char, int> mp;

        for(int i = 0; i < p.length(); i++)
            mp[p[i]]++;
        
        int count = mp.size();
        int k = p.length();         // Window size

        int i = 0, j = 0;
        while(j < s.length())
        {
            if(mp.find(s[j]) != mp.end())       // If a character is found which is present in map, then decrease the freq by 1
            {
                mp[s[j]]--;
                if(mp[s[j]] == 0)
                    count--;
            }

            if(j - i + 1 < k)
                j++;
            
            else if(j - i + 1 == k)
            {
                if(count == 0)
                    res.push_back(i);

                if(mp.find(s[i]) != mp.end())
                {
                    if(mp[s[i]] == 0)
                        count++;

                    mp[s[i]]++;
                }

                i++;
                j++;
            }
        }

        return res;
    }
};