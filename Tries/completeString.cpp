// Complete String: https://www.codingninjas.com/codestudio/problems/complete-string_2687860?leftPanelTab=0

struct Node
{
    Node *links[26];
    bool flag = false;

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

    void insert(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
                node->put(word[i], new Node());

            node = node->get(word[i]);
        }

        node->setEnd();
    }
    // This function checks if all prefix of a given word exist in the trie or not
    bool checkIfAllPrefixExists(string word)
    {
        Node *node = root;

        // Every letter's reference trie flag must be true.
        // If the above statement is true, the string is a "complete string".
        for (int i = 0; i < word.size(); i++)
        {
            // If the current letter is present in the trie,
            // then we move to its reference trie and finally
            // we check if its flag is true (i.e it ends or not).
            if (node->containsKey(word[i]))
            {
                node = node->get(word[i]);

                if (node->isEnd() == false)
                    return false;
            }
            else
                return false;
        }

        return true;
    }
};

string completeString(int n, vector<string> &a)
{
    Trie trie;

    for (auto word : a)
        trie.insert(word);

    string longest = "";

    for (auto word : a)
    {
        if (trie.checkIfAllPrefixExists(word))
        {
            if (word.size() > longest.size())
                longest = word;

            else if (word.size() == longest.size() && word < longest)
                longest = word;
        }
    }

    if (longest == "")
        return "None";

    return longest;
}