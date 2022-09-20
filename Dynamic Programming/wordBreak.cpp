// Word Break: https://leetcode.com/problems/word-break/
//             https://leetcode.com/problems/word-break/discuss/43886/Evolve-from-brute-force-to-optimal-a-review-of-all-solutions

/*
    T(n) = T(n - 1) + T(n - 2) + ... + T(1)
    =>  T(n + 1) = T(n) + T(n - 1) + T(n - 2) + ... + T(1)
    =>  T(n + 1) = 2T(n)
*/

// Recursive Solution
class RecursiveSolution
{
public:
    bool canBreak(int start, string &s, set<string> &wordDict)
    {
        int n = s.size();
        if (start == n)
            return true;

        string sub;
        for (int i = start; i < n; i++)
        {
            sub += s[i];
            if (wordDict.count(sub) && canBreak(i + 1, s, wordDict))
                return true;
        }

        return false;
    }

    bool wordBreak(string s, vector<string> &wordDict)
    {
        set<string> st(wordDict.begin(), wordDict.end());
        return canBreak(0, s, st);
    }
};

// Top Down DP Solution
class TopDownDPSolution
{
public:
    bool canBreak(int start, string &s, set<string> &wordDict, vector<char> &memo)
    {
        int n = s.size();
        if (start == n)
            return true;

        if (memo[start] != -1)
            return memo[start];

        string sub;
        for (int i = start; i < n; i++)
        {
            sub += s[i];
            if (wordDict.count(sub) && canBreak(i + 1, s, wordDict, memo))
                return memo[start] = true;
        }

        return memo[start] = false;
    }

    bool wordBreak(string s, vector<string> &wordDict)
    {
        set<string> st(wordDict.begin(), wordDict.end());
        vector<char> memo(s.size(), -1);
        return canBreak(0, s, st, memo);
    }
};

// Bottom Up DP Solution
class BottomUPDPSolution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        int n = s.size();
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        vector<bool> dp(n + 1);
        dp[n] = 1;

        for(int i = n - 1; i >= 0; i--)
        {
            string sub;
            for(int j = i; j < n; j++)
            {
                sub += s[j];
                dp[i] = st.count(sub);

                if(dp[i] && dp[j + 1])
                    break;
            }
        }

        return dp[0];
    }
};

// BFS Approach 
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) 
    {    
        queue<string> q; 
        q.push(s); 
        
        set<string> visited; 
        
        while(!q.empty())
        {
            s = q.front(); 
            q.pop(); 
            
            for(string word: wordDict)
            {
                if(s.rfind(word, 0) == 0)       // If string s starts with word as prefix
                {
                    string newString = s.substr(word.size()); 
                    
                    if(newString == "")
                        return true; 
                    if(!visited.count(newString))
                    {
                        q.push(newString); 
                        visited.insert(newString);
                    }
                }
            }
        }
        
        return false;
    }
};