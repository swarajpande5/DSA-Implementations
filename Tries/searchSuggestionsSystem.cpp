// Search Suggestion System: 
// https://leetcode.com/problems/search-suggestions-system/discuss/436674/C%2B%2BJavaPython-Sort-and-Binary-Search-the-Prefix
// https://leetcode.com/problems/search-suggestions-system/discuss/1242773/c%2B%2B-trie

class Trie 
{
    Trie *link[26];
    bool endOfWord;

public:
    Trie()
    {
        memset(link, NULL, sizeof(link));
        endOfWord = false;
    }

    void insert(string &word)
    {
        Trie *node = this;

        for(char c: word)
        {
            if(node -> link[c - 'a'] == NULL)
                node -> link[c - 'a'] = new Trie();
            
            node = node -> link[c - 'a'];
        }

        node -> endOfWord = true;
    }

    void dfs(string pre, vector<string> &result)
    {
        if(result.size() == 3)
            return;
        
        if(this -> endOfWord)
            result.push_back(pre);
        
        for(int i = 0; i < 26; i++)
        {
            if(this -> link[i])
                this -> link[i] -> dfs(pre + (char)(i + 'a'), result);
        }
    }

    vector<string> searchWord(string &prefix)
    {
        vector<string> result;
        
        Trie *node = this;

        for(char c: prefix)
        {
            int idx = c - 'a';
            if(!node -> link[idx])
                return {};
            
            node = node -> link[idx];
        }

        node -> dfs(prefix, result);

        return result;
    }
};

class Solution 
{
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) 
    {
        Trie *trie = new Trie();

        for(string &product: products)
            trie -> insert(product);
        
        vector<vector<string>> result;
        string prefix;

        for(char c: searchWord)
        {
            prefix += c;
            result.push_back(trie -> searchWord(prefix));
        }

        return result;
    }
};