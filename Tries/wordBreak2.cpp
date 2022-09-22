// Word Break 2: https://leetcode.com/problems/word-break-ii/

// Recursive Approach on maps
class Solution 
{
public:
    
    bool isWordInDict(string s, vector<string> &dict)
    {
        for(auto word: dict)
            if(word == s)
                return true; 
        
        return false;
    }
    
    void wordBreakRecursive(string &s, vector<string> &dict, int cut, int n, string str, vector<string> &res)
    {
        // Checking if string can be split into words in w 
        for(int i = cut + 1; i <= n; i++)
        {
            string sloc = s.substr(cut, i - cut); 
            
            if(isWordInDict(sloc, dict))
            {
                // If at the end of the string, add to valid sentences and return 
                if(i == n)
                {
                    res.push_back(str + sloc); 
                    return;
                }
                
                wordBreakRecursive(s, dict, i, n, (str + sloc + " "), res);
            }
        }
    }
    
    vector<string> util(string s, vector<string> &dict)
    {
        int n = s.length(); 
        vector<string> res; 
        
        wordBreakRecursive(s, dict, 0, n, "", res);
        
        return res;
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) 
    {
        return util(s, wordDict);
    }
};

// Trie + Backtracking 

class TrieNode 
{
public: 
    bool isEnd; 
    TrieNode *link[26]; 

    TrieNode() 
    {
        isEnd = false; 
        for(int i = 0; i < 26; i++)
            link[i] = NULL;
    }
};

class Solution 
{
public:

    TrieNode *root; 
    vector<string> ans; 

    // Inserting a word in trie 
    void insert(string word)
    {
        TrieNode *curr = root; 
        int idx; 

        for(char c: word)
        {
            idx = c - 'a'; 
            if(curr -> link[idx] == NULL)
                curr -> link[idx] = new TrieNode(); 
            
            curr = curr -> link[idx];
        }

        curr -> isEnd = true;
    }

    void solve(int i, string &s, string currStr)
    {
        TrieNode *curr = root; 

        if(i == s.size())
        {
            currStr.pop_back(); 
            ans.push_back(currStr); 
            return; 
        }

        int idx, j; 
        for(j = i; j < s.size(); j++)
        {
            idx = s[j] - 'a'; 

            if(curr -> link[idx] == NULL)
                return; 

            curr = curr -> link[idx]; 
            currStr.push_back(s[j]); 

            if(curr -> isEnd == true)
            {
                currStr.push_back(' '); 
                solve(j + 1, s, currStr); 
                currStr.pop_back();
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) 
    {
        root = new TrieNode(); 

        for(string word: wordDict)
            insert(word);
        
        string currStr = ""; 
        solve(0, s, currStr); 

        return ans;
    }
};