// Maximum XOR with an element from array: https://leetcode.com/problems/maximum-xor-with-an-element-from-array/
// Max XOR queries: https://www.codingninjas.com/codestudio/problems/max-xor-queries_1382020

struct Node 
{
    Node *links[2];

    bool containsKey(int index)
    {
        return (links[index] != NULL);
    }

    Node *get(int index)
    {
        return links[index];
    }

    void put(int index, Node *node)
    {
        links[index] = node;
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

    void insert(int num)
    {
        Node *node = root;
        for(int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            
            if(!node -> containsKey(bit))
                node -> put(bit, new Node());

            node = node -> get(bit);
        }
    }

    int findMax(int num)
    {
        Node *node = root;
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

vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> queries)
{
    vector<int> ans(queries.size(), 0);
    vector<pair<int, pair<int, int>>> offlineQueries;
    // vector of {queries[it][1], {queries[it][0], indexOfQuery}}
    
    sort(arr.begin(), arr.end());

    int index = 0;
    for(auto query: queries)
        offlineQueries.push_back({query[1], {query[0], index++}});
    
    sort(offlineQueries.begin(), offlineQueries.end());

    int i = 0;
    int n = arr.size();
    Trie trie;

    for(auto it: offlineQueries)
    {
        int ai = it.first;
        int xi = it.second.first;
        int idx = it.second.second;

        while(i < n && arr[i] <= ai)
        {
            trie.insert(arr[i]);
            i++;
        }

        if(i != 0)
            ans[idx] = trie.findMax(xi);
        else 
            ans[idx] = -1;
    }

    return ans;
}