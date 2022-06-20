// Short encoding of words: https://leetcode.com/problems/short-encoding-of-words/
// https://leetcode.com/problems/short-encoding-of-words/discuss/1096064/C%2B%2B-Trie-solution.
// https://leetcode.com/problems/short-encoding-of-words/discuss/125811/C%2B%2BJavaPython-Easy-Understood-Solution-with-Explanation

// Trie solution
class Trie 
{
    Trie *link[26];
    bool endOfWord;
    
public:
    Trie()
    {
        memset(link, 0, sizeof(link));
        endOfWord = false;
    }
    
    ~Trie()
    {
        for(int i = 0; i < 26; i++)
            delete link[i];
    }
    
    int insert(string &word)
    {
        Trie *node = this;
        bool newBranch = false;
        
        for(int i = word.size() - 1; i >= 0; i--)
        {
            if(node -> link[word[i] - 'a'] == NULL)
            {
                newBranch = true;
                node -> link[word[i] - 'a'] = new Trie();
            }
            node = node -> link[word[i] - 'a'];
        }
        
        node -> endOfWord = true;
        
        return newBranch ? word.size() : 0;
    }
};

class Solution 
{
public:
    int minimumLengthEncoding(vector<string>& words) 
    {
        // Sorting words in descending order of length
        sort(words.begin(), words.end(), [](auto &a, auto &b)
        {
            return a.size() > b.size();                                           
        });    
        
        Trie root;
        
        int ans = 0;
        
        for(string word: words)
        {
            int cnt = root.insert(word);
            if(cnt)
                ans += cnt + 1;
        }
        
        return ans;
    }
};

// Hashing solution 
class HashingSolution
{
public:
    int minimumLengthEncoding(vector<string>& words)
    {
        unordered_set<string> s(words.begin(), words.end());
        
        for(string word: s)
            for(int i = 1; i < word.size(); i++)
                s.erase(word.substr(i));
        
        int res = 0;
        for(string word: s)
            res += word.size() + 1;     // +1 for # character
        
        return res;
    }
};