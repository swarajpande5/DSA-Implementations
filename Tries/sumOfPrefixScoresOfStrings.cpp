// Sum of prefix scores of strings: https://leetcode.com/problems/sum-of-prefix-scores-of-strings/

struct TrieNode 
{
    TrieNode *link[26] = {};
    int cnt = 0;
};

class Solution 
{
    TrieNode root;
public:
    void insert(string word) 
    {
        auto node = &root;
        for(char c : word) 
        {
            if(!node -> link[c - 'a']) 
            {
                node -> link[c - 'a'] = new TrieNode();
            }
            
            node -> link[c - 'a'] -> cnt++;
            node = node -> link[c - 'a'];   
        }
    }

    int prefixCnt(string s) 
    {
        auto node = &root;
        int ans = 0;
        for(char c : s) 
        {
            ans += node -> link[c - 'a'] -> cnt;
            node = node -> link[c - 'a'];
        }
        
        return ans;
    }
    
    vector<int> sumPrefixScores(vector<string>& words) 
    {
        int n = words.size();
        
		// Insert words in trie.
        for (int i = 0; i < n; i++) 
                insert(words[i]);
    
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++)
			// Get the count of all prefixes of given string.
            ans[i] = prefixCnt(words[i]); 

        return ans;
    }
};