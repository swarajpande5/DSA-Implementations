// Count distinct substrings: https://www.codingninjas.com/codestudio/problems/count-distinct-substrings_985292?leftPanelTab=0

struct Node 
{
	Node *links[26];
    
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
};

int countDistinctSubstrings(string &s)
{
	Node *root = new Node();
    int count = 0;
    int n = s.size();
    
    for(int i = 0; i < n; i++)
    {
        Node *node = root;
        for(int j = i; j < n; j++)
        {
            if(!node -> containsKey(s[j]))
            {
                node -> put(s[j], new Node());
                count++;
            }
            
            node = node -> get(s[j]);
        }
    }
    
    return count + 1;
}