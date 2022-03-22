// Implement trie (Prefix tree): https://www.codingninjas.com/codestudio/problems/implement-trie_1387095?leftPanelTab=0

struct Node
{
    Node *links[26];
    int countEndWith = 0;
    int countPrefix = 0;

    bool containsKey(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }

    Node *get(char ch)
    {
        return links[ch - 'a'];
    }

    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }

    void increaseEnd()
    {
        countEndWith++;
    }

    void increasePrefix()
    {
        countPrefix++;
    }

    void deleteEnd()
    {
        countEndWith--;
    }

    void reducePrefix()
    {
        countPrefix--;
    }

    int getEnd()
    {
        return countEndWith;
    }

    int getPrefix()
    {
        return countPrefix;
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

    void insert(string &word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
                node->put(word[i], new Node());

            node = node->get(word[i]);
            // We increase the prefix count as new word is added
            node->increasePrefix();
        }
        // Finally we increase the end count,
        // which denotes that the current word is ended and
        // and its value is the frequency of the word
        node->increaseEnd();
    }

    int countWordsEqualTo(string &word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            // If the current letter is present in the trie, we move forward in the trie
            if (node->containsKey(word[i]))
                node = node->get(word[i]);
            else
                return 0;
        }

        // Finally we return the "end" count holded by the last trie,
        // which denotes the frequency of a word
        return node->getEnd();
    }

    int countWordsStartingWith(string &word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            // If the current letter is present in the trie, we move forward in the trie
            if (node->containsKey(word[i]))
                node = node->get(word[i]);
            else
                return 0;
        }

        // Finally we return the "prefix" count holded by the last trie,
        // which denotes how many words actually have that prefix
        return node->getPrefix();
    }

    void erase(string &word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            // If the current letter is present in the trie,
            // we move to that trie, and reduce the "prefix" count
            if (node->containsKey(word[i]))
            {
                node = node->get(word[i]);
                node->reducePrefix();
            }
            else
                return;
        }

        // Finally we reduce the "end" count
        node->deleteEnd();
    }
};
