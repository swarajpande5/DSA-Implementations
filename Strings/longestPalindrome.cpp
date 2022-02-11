// Longest palindrome: 

class Solution
{
public:
    int longestPalindrome(string s)
    {
        int freq[128] = {0};
        
        for(char c: s)
            freq[c]++;
        
        int odds = 0;
        for(int f: freq)
            odds = odds + (f & 1);
        
        return s.size() - odds + (odds > 0);
    }
};