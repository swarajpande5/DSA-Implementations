// Implement trie (Prefix tree): https://leetcode.com/problems/implement-trie-prefix-tree/

struct Node 
{
    Node *links[26];
    bool flag = false;
    
    bool containsKey(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }
    
    void put(char ch, Node *newNode)
    {
        links[ch - 'a'] = newNode;
    }
    
    Node *get(char ch)
    {
        return links[ch - 'a'];
    }
    
    void setEnd()
    {
        flag = true;
    }
    
    bool isEnd()
    {
        return flag;
    }
};

class Trie 
{
    Node *root;
    
public:
    Trie() 
    {
        root = new Node();
    }
    
    // T.C. = O(L)
    // L = length of the word
    void insert(string word) 
    {
        Node *node = root;
        
        for(int i = 0; i < word.size(); i++)
        {
            // If trie does not contains the current letter
            if(!node -> containsKey(word[i]))
                node -> put(word[i], new Node());
            
            // Fetching and moving to the reference trie
            node = node -> get(word[i]);
        }
        
        // Finally we stand at the last reference trie, and we set the end flag
        node -> setEnd();
    }
    
    bool search(string word) 
    {
        Node *node = root;
        
        for(int i = 0; i < word.size(); i++)
        {
            // If trie does not contains the current letter, then word does not exists
            if(!node -> containsKey(word[i]))
                return false;
            
            // Fetching and moving to the next reference trie
            node = node -> get(word[i]);
        }
        
        // If the last reference try ends, then we return true
        return node -> isEnd();
    }
    
    bool startsWith(string prefix) 
    {
        Node *node = root;
        
        for(int i = 0; i < prefix.size(); i++)
        {
            // If trie does not contains the current letter prefix does not exists
            if(!node -> containsKey(prefix[i]))
                return false;
            
            // Fetching and moving to the next reference trie
            node = node -> get(prefix[i]);
        }
        
        // Finally we return true
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */