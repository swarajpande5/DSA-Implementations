// Palindrome pairs: https://leetcode.com/problems/palindrome-pairs/

struct TrieNode 
{
    TrieNode *link[26] = {}; 
    int currIdx = -1; 
    vector<int> wordIndex;
};

class Solution 
{
public:
    
    TrieNode *root;
    
    bool isPalindrome(string &s, int i, int j)
    {
        while(i < j)
            if(s[i++] != s[j--])
                return false; 
        
        return true;
    }
    
    void insert(string &s, int index)
    {
        TrieNode *curr = root; 
        for(int i = s.size() - 1; i >= 0; i--)
        {
            int c = s[i] - 'a'; 
            if(curr -> link[c] == NULL)
                curr -> link[c] = new TrieNode();
            if(isPalindrome(s, 0, i))
                curr -> wordIndex.push_back(index); 
            curr = curr -> link[c];
        }
        
        curr -> wordIndex.push_back(index); 
        curr -> currIdx = index;
    }
    
    vector<vector<int>> palindromePairs(vector<string>& words) 
    {
        root = new TrieNode(); 
        for(int i = 0; i < words.size(); i++)
            insert(words[i], i); 
        
        vector<vector<int>> ans; 
        for(int i = 0; i < words.size(); i++)
        {
            TrieNode *curr = root; 
            string &s = words[i]; 
            
            for(int j = 0; j < s.size(); j++)
            {
                if(curr -> currIdx != -1 && curr -> currIdx != i && isPalindrome(s, j, s.size() - 1))
                    ans.push_back({i, curr -> currIdx});
                
                curr = curr -> link[s[j] - 'a']; 
                
                if(curr == NULL)
                    break;
            }
            
            if(curr == NULL)
                continue; 
            
            for(int j: curr -> wordIndex)
            {
                if(i == j)
                    continue; 
                
                ans.push_back({i, j});
            }
        }
        
        return ans;
    }
};