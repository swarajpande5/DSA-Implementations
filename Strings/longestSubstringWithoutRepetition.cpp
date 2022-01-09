// Longest substring without repeating characters: https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        map<char, int> m;
        int l, r, ans;

        while(r < s.length())
        {
            m[s[r]]++;

            while(m[s[r]] > 1)
            {
                m[s[l]]--;
                l++;
            }

            ans = max(ans, r - l + 1);
            r++;
        }

        return ans;
    }
};