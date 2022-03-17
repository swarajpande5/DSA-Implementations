// Top k frequent words: https://leetcode.com/problems/top-k-frequent-words/

class Solution 
{
public:
    
    struct comp
    {
        bool operator()(pair<string, int> p1, pair<string, int> p2)
        {
            if(p1.second > p2.second)
                return true;
            else if(p1.second == p2.second)
            {
                return p1.first < p2.first;
            }
                
            return false;
        }
    };
    
    vector<string> topKFrequent(vector<string>& words, int k) 
    {
        priority_queue<pair<string, int>, vector<pair<string, int>>, comp> pq;
        unordered_map<string, int> mp;
        for(string s: words)            
            mp[s]++;
        
        for(auto p: mp)
        {
            pq.push(p);
            if(pq.size() > k)
                pq.pop();
        }
        
        vector<string> res;
        while(!pq.empty())
        {
            res.insert(res.begin(), pq.top().first);
            pq.pop();
        }
        
        return res;
    }
};