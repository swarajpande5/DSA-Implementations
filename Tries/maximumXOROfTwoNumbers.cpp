// Maximum XOR: https://www.codingninjas.com/codestudio/problems/maximum-xor_973113
//              https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/

class TrieNode 
{
public:
    TrieNode *links[2];

    bool containsKey(int index)
    {
        return (links[index] != NULL);
    }

    TrieNode *get(int index)
    {
        return links[index];
    }

    void put(int index, TrieNode *node)
    {
        links[index] = node;
    }
};

class Trie
{
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }

    void insert(int num)
    {
        TrieNode *node = root;

        for(int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            
            if(!node -> containsKey(bit))
                node -> put(bit, new TrieNode());
            
            node = node -> get(bit);
        }
    }

    int findMax(int num)
    {
        TrieNode *node = root;
        int maxNum = 0;

        for(int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;

            if(node -> containsKey(!bit))
            {
                maxNum = maxNum | (1 << i);
                node = node -> get(!bit);
            }
            else 
                node = node -> get(bit);
        }

        return maxNum;
    }
};

int maxXOR(int n, int m, vector<int> &arr1, vector<int> &arr2)
{
    Trie trie;
    for(int i = 0; i < n; i++)
        trie.insert(arr1[i]);
    
    int maxi = 0;
    for(int i = 0; i < m; i++)
    {
        maxi = max(maxi, trie.findMax(arr2[i]));
    }

    return maxi;
}