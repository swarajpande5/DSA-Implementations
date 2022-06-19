// Prefix and Suffix Search: https://leetcode.com/problems/prefix-and-suffix-search/

class Trie 
{
    // 0 - 25 for alphabets
    // 26 for {, which will be used as separator
    Trie *link[27];  
    int weight;
    
public:
    Trie() 
    {
        memset(link, 0, sizeof(link));
        weight = 0;
    }
    
    void insert(string str, int weight)
    {
        Trie *node = this;
        
        for(char c: str)
        {
            if(node -> link[c - 'a'] == NULL)
                node -> link[c - 'a'] = new Trie();
        
            node = node -> link[c - 'a'];
            node -> weight = weight;
        }
    }
    
    int startsWith(string str)
    {
        Trie *node = this;
        
        for(char c: str)
        {
            if(node -> link[c - 'a'] == NULL)
                return -1;
            
            node = node -> link[c - 'a'];
        }
        
        return node -> weight;
    }
};

class WordFilter 
{
public:
    
    Trie root;
    
    WordFilter(vector<string>& words) 
    {
        int idx = 0;
        
        for(string word: words)
        {
            root.insert(word, idx);
            string temp = "{" + word;
            for(int i = word.length() - 1; i >= 0; i--)
            {
                string newWord = word[i] + temp;
                temp = newWord;
                root.insert(newWord, idx);
            }
            
            idx++;
        }
    }
    
    int f(string prefix, string suffix) 
    {
        string word = suffix + "{" + prefix;
        return root.startsWith(word);
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */