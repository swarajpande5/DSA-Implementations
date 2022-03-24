// Design and add search words in data structure: https://leetcode.com/problems/design-add-and-search-words-data-structure/

class WordDictionary
{
    vector<WordDictionary *> links;
    bool flag;

public:
    WordDictionary()
    {
        links = vector<WordDictionary *>(26, nullptr);
        flag = false;
    }

    void addWord(string word)
    {
        WordDictionary *curr = this;

        for(char c: word)
        {
            if(curr -> links[c - 'a'] == nullptr)
                curr -> links[c - 'a'] = new WordDictionary();
            
            curr = curr -> links[c - 'a'];
        }

        curr -> flag = true;
    }

    bool search(string word)
    {
        WordDictionary *curr = this;
        
        for(int i = 0; i < word.size(); i++)
        {
            char c = word[i];

            if(c == '.')
            {
                for(auto ch: curr -> links)
                    if(ch && ch -> search(word.substr(i+1)))
                        return true;
                
                return false;
            }

            if(curr -> links[c - 'a'] == nullptr)
                return false;

            curr = curr -> links[c - 'a'];
        }

        return curr && curr -> flag;
    }
};