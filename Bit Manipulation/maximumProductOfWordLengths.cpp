// Maximum product of word lengths: https://leetcode.com/problems/maximum-product-of-word-lengths/
// https://leetcode.com/problems/maximum-product-of-word-lengths/discuss/1233648/Short-and-Easy-Solution-w-Explanation-or-C%2B%2B-using-Bitset-and-Bit-masking-or-Beats-100

class BitsetSolution 
{
public:
    
    bool checkCommon(bitset<26> &a, bitset<26> &b)
    {
        for(int i = 0; i < 26; i++)
            if(a[i] && b[i])
                return true;
        
        return false;
    }
    
    int maxProduct(vector<string>& words) 
    {
        int n = words.size();
        int ans = 0;
        
        vector<bitset<26>> chars(n);
        
        for(int i = 0; i < n; i++)
        {
            for(auto ch: words[i])
                chars[i][ch - 'a'] = 1;
            
            for(int j = 0; j < i; j++)
                if(!checkCommon(chars[i], chars[j]))
                    ans = max(ans, int(words[i].size() * words[j].size()));
        }
        
        return ans;
    }
};

class Solution 
{
public:
    int maxProduct(vector<string>& words) 
    {
        int n = words.size();
        int ans = 0;
        
        vector<int> mask(n);
        
        for(int i = 0; i < n; i++)
        {
            for(auto ch: words[i])
                mask[i] |= 1 << (ch - 'a');     // Hash the word
            
            for(int j = 0; j < i; j++)
                if((mask[i] & mask[j]) == 0)
                    ans = max(ans, int(words[i].size() * words[j].size()));
        }
        
        return ans;
    }
};