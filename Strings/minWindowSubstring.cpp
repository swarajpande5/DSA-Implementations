// Minimum window substring:

class Solution
{
public:
    string minWindow(string s, string t)
    {
        if(s.empty() || t.empty())
            return "";
        
        unordered_map<char, int> map;
        unordered_map<char, int> window;

        for(int i = 0; i < t.length(); i++)
            map[t[i]]++;
        
        string result;
        int minLength = INT_MAX;

        int letterCount = 0;

        int left = 0;
        int right = 0;
        while(right < s.length())
        {
            char curr = s[right];

            // If current character of string "s" is present in the map of string "t" characters
            if(map.find(curr) != map.end())
            {
                // Store that character in current window and increase counter by 1
                window[curr]++;

                if(window[curr] <= map[curr])
                    letterCount++;
            }

            // If we have found the result in current window
            if(letterCount >= t.length())
            {
                while(map.find(s[left]) == map.end() || window[s[left]] > map[s[left]])
                {
                    // Decreasing frequency of character of extra character in the window
                    window[s[left]]--;
                    left++;
                }

                if(right - left + 1 < minLength)
                {
                    minLength = right - left + 1;
                    result = s.susbstr(left, minLength);
                }
            }

            right++;
        }

        return result;
    }
};