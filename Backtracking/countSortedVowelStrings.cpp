// Count sorted vowel strings: 
// https://leetcode.com/problems/count-sorted-vowel-strings/discuss/2027270/Count-Sorted-Vowel-Strings
// https://leetcode.com/problems/count-sorted-vowel-strings/discuss/918498/JavaC%2B%2BPython-DP-O(1)-Time-and-Space

// Backtracking solution
class BacktrackingSolution 
{
public:
    vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};

    void solve(int n, int last, int &count)
    {
        if(n == 0)
        {
            count++;
            return;
        }

        for(int i = 0; i < 5; i++)
            if(i >= last)
                solve(n - 1, i, count);
    }

    int countVowelStrings(int n)
    {
        int count = 0;
        solve(n, 0, count);

        return count;
    }
};

// DP Solution
class DPSolution
{
public:
    int countVowelStrings(int n)
    {
        vector<int> dp = {0, 1, 1, 1, 1, 1};
        
        for(int i = 1; i <= n; i++)
            for(int k = 1; k <= 5; k++)
                dp[k] += dp[k - 1];
            
        return dp[5];
    }
};

// Combination Solution
class Solution
{
public:
    int countVowelStrings(int n)
    {
        return (n + 1) * (n + 2) * (n + 3) * (n + 4) / 24;
    }
};