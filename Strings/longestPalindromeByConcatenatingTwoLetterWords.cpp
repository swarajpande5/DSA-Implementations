// Longest palindrome by concatenating two letter words: https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/

class Solution 
{
public:
    int longestPalindrome(vector<string>& words) 
    {
        unordered_map<string, int> freq;
        
        int unpaired = 0;
        int ans = 0;
        
        for(string word: words)
        {
            if(word[0] == word[1])
            {
                if(freq[word] > 0)
                {
                    unpaired--;
                    freq[word]--;
                    ans += 4;
                }    
                else 
                {
                    freq[word]++;
                    unpaired++;
                }
            }
            else 
            {
                string rev = word;
                reverse(rev.begin(), rev.end());
                
                if(freq[rev] > 0)
                {
                    ans += 4;
                    freq[rev]--;
                }
                else 
                    freq[word]++;
            } 
        }
        
        if(unpaired > 0)
            ans += 2;
        
        return ans;
    }
};