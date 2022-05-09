// Count vowel permutation: https://leetcode.com/problems/count-vowels-permutation/
// https://leetcode.com/problems/count-vowels-permutation/discuss/1315113/C%2B%2BJavaPython-Top-down-DP-Bottom-up-DP-Picture-explain-Clean-and-Concise

class Solution 
{
public:
    
    const int a = 0, e = 1, i = 2, o = 3, u = 4;
    const int mod = 1e9 + 7;
    
    int countVowelPermutation(int n) 
    {
        vector<long long> dp(5, 1LL);
        vector<long long> prev(5, 1LL);
        
        while(--n)
        {
            dp[a] = (prev[e] + prev[i] + prev[u]) % mod;
            dp[e] = (prev[a] + prev[i]) % mod;
            dp[i] = (prev[e] + prev[o]) % mod;
            dp[o] = prev[i];
            dp[u] = (prev[i] + prev[o]) % mod;
            
            dp.swap(prev);
        }
        
        return accumulate(prev.begin(), prev.end(), 0LL) % mod;
    }
};