// Top K frequent elements: https://leetcode.com/problems/top-k-frequent-elements/

class Solution 
{
public:
    
    struct comparator
    {
        bool operator() (pair<int, int> &a, pair<int, int> &b)
        {
            return a.second > b.second;
        }
    };
    
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int, int> mp;
        for(auto x: nums)
            mp[x]++;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, comparator> minHeap;
        
        for(auto p: mp)
        {
            minHeap.push(p);
            if(minHeap.size() > k)
                minHeap.pop();
        }
        
        
        vector<int> res;
        while(!minHeap.empty())
        {
            res.push_back(minHeap.top().first);
            minHeap.pop();
        }
        
        return res;
    }
};